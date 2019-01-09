#include "graphics_FA.h"
#include <math.h>
#include <time.h>
#include "maths_FA.h"

typedef struct
{
    float x;
    float y;
    
} vec2;

int isRunning = 1;

#define MAX_BALLS_NUM 20
fvec2 ballsPos[MAX_BALLS_NUM];
float radii[MAX_BALLS_NUM];
fvec2 velocity[MAX_BALLS_NUM];

void updatePositions(const float aRatio, const float dt)
{
    for (unsigned i = 0; i < MAX_BALLS_NUM; ++i)
    {
        ballsPos[i].x += velocity[i].x * dt;
        ballsPos[i].y += velocity[i].y * dt;

        if (ballsPos[i].x > aRatio || ballsPos[i].x < -aRatio)
        {
            velocity[i].x *= -1.0f;
        }

        if (ballsPos[i].y > 1.0f || ballsPos[i].y < -1.0f)
        {
            velocity[i].y *= -1.0f;
        }
    }
}

int main(int argc, char* argv[])
{
    newLine();
    newLine();
    
    ContextData contextData;
    contextData.minimalGLXVersionMajor = 1;
    contextData.minimalGLXVersionMinor = 3;
    contextData.minimalGLVersionMajor = 3;
    contextData.minimalGLVersionMinor = 3;
    contextData.windowWidth = 1920;
    contextData.windowHeight = 1080;
    contextData.name = "Faith";

    UserVSyncData userVSyncData;

    configureOpenGL(&contextData, &userVSyncData);
    loadFunctionPointers();

    
#if USE_EBO_TO_DRAW_QUAD == 1
    ScreenQuadWithEBO squad;
    configureScreenQuadWithEBO(&squad);
#else
    ScreenQuad squad;
    configureScreenQuad(&squad);
#endif


    unsigned metaProgram = createShaderProgram("shaders/meta.vs", "shaders/meta.fs");
    glUseProgram_FA(metaProgram);

    ballsPos[0].x = 0.2f;
    ballsPos[1].y = 0.3f;
    radii[0] = 0.1f;
    radii[1] = 0.1f;
    radii[2] = 0.2f;

    setRandomSeed(1339877);
    velocity[0] = getRandomFVec2OnInterval(-0.0004f, 0.0004f);
    velocity[1] = getRandomFVec2OnInterval(-0.0004f, 0.0004f);
    velocity[2] = getRandomFVec2OnInterval(-0.0004f, 0.0004f);


    float aRatio = contextData.windowWidth / contextData.windowHeight;

    int ballsPosLoc = glGetUniformLocation_FA(metaProgram, "ballsPos");
    int aRatioLoc = glGetUniformLocation_FA(metaProgram, "aRatio");
    int radiiLoc = glGetUniformLocation_FA(metaProgram, "radii");
    glUniform1fv_FA(radiiLoc, MAX_BALLS_NUM, radii);
    glUniform1f_FA(aRatioLoc, aRatio);
    
    glDisable(GL_DEPTH_TEST);

#if 0
    disableVSyncIfPossible(&contextData, &userVSyncData);
#else
    enableVSyncIfPossible(&contextData, &userVSyncData);
#endif

    struct timespec prevTime;
    clock_gettime(CLOCK_MONOTONIC_RAW, &prevTime);
    float dt = 0.0f;
    float elapsed = 0.0f;
    float maxFrameTimeNoticed = 0.0f;
    
    while(1)
    {        
        XEvent event;

        while (XPending(contextData.display))
        {
            XNextEvent(contextData.display, &event);
            switch (event.type)
            {
                case ClientMessage:
                    if (event.xclient.data.l[0] == contextData.deleteMessage)
                        isRunning = 0;
                    break;
            }
        }

        if (isRunning == 0)
        {
            break;
        }

        glClearColor(0, 0.5, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
#if USE_EBO_TO_DRAW_QUAD == 1
        glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_INT, 0);
#else
        glDrawArrays(GL_TRIANGLES, 0, 6);
#endif
        
        glXSwapBuffers(contextData.display, contextData.window);

        struct timespec nowTime;
        clock_gettime(CLOCK_MONOTONIC_RAW, &nowTime);
        dt = (nowTime.tv_sec - prevTime.tv_sec) * 1000000
            + (nowTime.tv_nsec - prevTime.tv_nsec) / 1000;
        dt /= 1000.0f;
        
        prevTime = nowTime;
        
        updatePositions(aRatio, dt);

        glUniform2fv_FA(ballsPosLoc, MAX_BALLS_NUM, (const float*)ballsPos);

        elapsed += dt;
        if (dt - maxFrameTimeNoticed > EPSILON)
        {
            maxFrameTimeNoticed = dt;
        }

#if 1
        if (elapsed > 2.0f * 1000)
        {
            printf("Longest frame: %f\n", maxFrameTimeNoticed);
            elapsed = 0.0f;
            maxFrameTimeNoticed = 0.0f;
        }
#else
        printf("dt = %f\n", dt);
#endif
    }

    freeContextData(&contextData);

#if USE_EBO_TO_DRAW_QUAD == 1
    freeScreenQuadWithEBO(&squad);
#else
    freeScreenQuad(&squad);
#endif

    glDeleteShader_FA(metaProgram);
    return 0;
}

#include "graphics.h"
#include <math.h>
#include <time.h>

int isRunning = 1;

#define MAX_BALLS_NUM 20
float ballsPosX[MAX_BALLS_NUM];
float ballsPosY[MAX_BALLS_NUM];
float radii[MAX_BALLS_NUM];

float velocityX[MAX_BALLS_NUM];
float velocityY[MAX_BALLS_NUM];

void updatePositions(const float aRatio, const float dt)
{
    for (unsigned i = 0; i < MAX_BALLS_NUM; ++i)
    {
        ballsPosX[i] += velocityX[i] * dt;
        ballsPosY[i] += velocityY[i] * dt;

        if (ballsPosX[i] > aRatio || ballsPosX[i] < -aRatio)
        {
            velocityX[i] *= -1.0f;
        }

        if (ballsPosY[i] > 1.0f || ballsPosY[i] < -1.0f)
        {
            velocityY[i] *= -1.0f;
        }
    }
}

void drawBalls()
{
    newLine();
    for (unsigned i = 0; i < MAX_BALLS_NUM; ++i)
    {
        printf("%d: X:%f Y:%f\n", i, ballsPosX[i], ballsPosY[i]);
    }
    newLine();
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

    ballsPosX[0] = 0.2f;
    ballsPosY[1] = 0.3f;
    radii[0] = 0.1f;
    radii[1] = 0.1f;

    velocityX[0] = 0.001f;
    velocityY[0] = -0.002f;
    velocityX[1] = -0.002f;
    velocityY[1] = 0.004f;
    
    float aRatio = contextData.windowWidth / contextData.windowHeight;
    

    
    int ballsPosXLoc = glGetUniformLocation_FA(metaProgram, "ballsPosX");
    int ballsPosYLoc = glGetUniformLocation_FA(metaProgram, "ballsPosY");
    int aRatioLoc = glGetUniformLocation_FA(metaProgram, "aRatio");
    int radiiLoc = glGetUniformLocation_FA(metaProgram, "radii");
    glUniform1fv_FA(radiiLoc, MAX_BALLS_NUM, radii);
    glUniform1f_FA(aRatioLoc, aRatio);

    drawBalls();
    
    glDisable(GL_DEPTH_TEST);

#if 0
    disableVSyncIfPossible(&contextData, &userVSyncData);
#else
    enableVSyncIfPossible(&contextData, &userVSyncData);
#endif

    struct timespec prevTime;
    clock_gettime(CLOCK_MONOTONIC_RAW, &prevTime);
    double dt = 0.0f;

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

        glUniform1fv_FA(ballsPosXLoc, MAX_BALLS_NUM, ballsPosX);
        glUniform1fv_FA(ballsPosYLoc, MAX_BALLS_NUM, ballsPosY);

        printf("dt = %f\n", dt);
        //sleep(1);
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

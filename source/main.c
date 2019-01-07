#include "graphics.h"
#include <math.h>
#include <time.h>

int isRunning = 1;

#define MAX_BALLS_NUM 20
float ballsPosX[MAX_BALLS_NUM];
float ballsPosY[MAX_BALLS_NUM];
float radii[MAX_BALLS_NUM];

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

    ballsPosX[0] = 0.5f;
    ballsPosY[1] = 0.3f;
    radii[0] = 0.2f;
    radii[1] = 0.5f;
    
    int ballsPosXLoc = glGetUniformLocation_FA(metaProgram, "ballsPosX");
    int ballsPosYLoc = glGetUniformLocation_FA(metaProgram, "ballsPosY");
    int radiiLoc = glGetUniformLocation_FA(metaProgram, "radii");
    glUniform1fv_FA(ballsPosXLoc, MAX_BALLS_NUM, ballsPosX);
    glUniform1fv_FA(ballsPosYLoc, MAX_BALLS_NUM, ballsPosY);
    glUniform1fv_FA(radiiLoc, MAX_BALLS_NUM, radii);

    drawBalls();
    
    glDisable(GL_DEPTH_TEST);

#if 0
    disableVSyncIfPossible(&contextData, &userVSyncData);
#else
    enableVSyncIfPossible(&contextData, &userVSyncData);
#endif

    clock_t prevTime = clock();
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

        clock_t nowTime = clock();
        dt = (nowTime - prevTime) *100000.0f / CLOCKS_PER_SEC;
        prevTime = nowTime;

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

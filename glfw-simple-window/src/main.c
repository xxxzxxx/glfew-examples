#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "error_callback.[%d]:%s\n", error, description);
}

int main(int argc, char *argv[])
{
    int error = 0;
    {
        if (!glfwInit())
        {
            fprintf(stderr, "glfwInit failed.\n");
            error = -1;
            goto exit_terminate;
        }
        glfwSetErrorCallback(error_callback);
    }

    GLFWwindow* window;
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
        if (!window)
        {
            fprintf(stderr, "Window or OpenGL context creation failed\n");
            goto exit_terminate;
        }
        glfwMakeContextCurrent(window);
    }
    {
        GLenum err;
        err = glewInit();
        if(err != GLEW_OK)
        {
            fprintf(stderr, "glew failed.%s\n", (char*)glewGetErrorString(err));
            error = -1;
            goto exit_terminate;
        }
    }
    while(glfwWindowShouldClose(window) == GL_FALSE)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    glfwDestroyWindow(window);
exit_terminate:
    glfwTerminate();
    return error;
}

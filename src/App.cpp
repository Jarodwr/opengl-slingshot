#include "App.h"
#include "glad/gl.h"

namespace slingshot {
    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

	App::App() {
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())
            exit(EXIT_FAILURE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        auto initialWidth = 600;
        auto initialHeight = 480;


        this->window = (glfwCreateWindow(initialWidth, initialHeight, "Simple example", NULL, NULL));
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
            });
        glfwSetKeyCallback(this->window, key_callback);

        glfwMakeContextCurrent(this->window);
        gladLoadGL(glfwGetProcAddress);
        glfwSwapInterval(1);

	}

	App::~App() {
        glfwDestroyWindow(this->window);

        glfwTerminate();
        exit(EXIT_SUCCESS);
	}

	void App::Draw() {

	}

    void App::Execute() {

        while (!glfwWindowShouldClose(this->window))
        {
            int width, height;

            glfwGetFramebufferSize(this->window, &width, &height);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            this->Draw();

            glfwSwapBuffers(this->window);
            glfwPollEvents();
        }
    }
}
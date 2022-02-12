#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int my_window_size_x = 640;
int my_window_size_y = 480;

void glfwWindowSizeCallback(GLFWwindow* window, int n_width, int n_height) 
{
    my_window_size_x = n_width;
    my_window_size_y = n_height;
    glViewport(0, 0, my_window_size_x, my_window_size_y);
}
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
int main() 
{

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "GLFW PROBLEMS!";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(my_window_size_x, my_window_size_y, 
                                          "Hello World", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }
    glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	if (!gladLoadGL()) 
    {
		std::cout << "GLAD PROGLEMS!";
		return -1;
	}

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
    
    /* Loop until the user closes the window */
    glClearColor(0, 1, 0, 1);
	while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
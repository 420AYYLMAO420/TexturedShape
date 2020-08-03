#include "Window.h"
#include <GLFW/glfw3.h>
#include "Log.h"

Window::Window(const char* title, unsigned int width, unsigned int height)
	:Title(title), Width(width), Height(height)
{

	PRINT_IF_ELSE(glfwInit() == GLFW_TRUE, "Initialized GLFW", "Failed to initialize GLFW");
	//suggest to window that the app wants OpenGL 4.3 core
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//create the window and OpenGL context
	pWindow = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
	glfwMakeContextCurrent(pWindow);
}

Window::~Window()
{
	//clean up window
	glfwDestroyWindow(pWindow);
	glfwTerminate();
}

void Window::HandleEvents()
{
	//retrieve events from window 
	glfwPollEvents();
}

void Window::SwapBuffers()
{
	//swap buffers of the window
	glfwSwapBuffers(pWindow);
}

bool Window::IsRequestingClose()
{
	//return close flag when user wishes to close window
	return glfwWindowShouldClose(pWindow);
}

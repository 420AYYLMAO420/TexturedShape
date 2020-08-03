#pragma once

class Window {

public:
	Window(const char* title, unsigned int width, unsigned int height);
	~Window();

	//is the user wanting to close the window
	bool IsRequestingClose();
	void HandleEvents();
	void SwapBuffers();

private:
	//pointer to the window
	struct GLFWwindow* pWindow;
	//title of window
	const char* Title;
	//dimensions of window
	unsigned int Width, Height;


};
#pragma once

#include <memory>

class App {
public:
	App();
	~App();

	void Run();//main loop

private:
	//app will contain a window and a graphics object for rendering
	std::unique_ptr<class Window> window;
	std::unique_ptr<class Graphics> graphics;

};
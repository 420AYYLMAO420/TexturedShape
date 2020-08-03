#include "App.h"
#include "Window.h"
#include "Graphics.h"

App::App()
{
	//create components of app
	window = std::make_unique<Window>("Textured Shape", 1280, 720);
	graphics = std::make_unique<Graphics>();
}

App::~App(){}

void App::Run()
{
	//handle messages, render, and swap buffers until user wants to quit app
	while (!window->IsRequestingClose()) {
		window->HandleEvents();
		graphics->Render();
		window->SwapBuffers();
	}
}

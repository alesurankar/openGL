#pragma once
#include <app/Window.h>
#include <utils/FrameTimer.h>

class App
{
public:
	App();
	~App();
	int Run();
private:
	void UpdateFrame();
	void DrawFrame();
private:
	Window wnd;
	FrameTimer ft;
};
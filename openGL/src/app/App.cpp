#include "App.h"
#include <utils/DebugLog.h>


App::App()
	:
	wnd(800, 600, "OpenGL App")
{
	DBG_LOG("Constructing App");
}

App::~App()
{
	DBG_LOG("Destroying App");
}

int App::Run()
{
	DBG_LOG("App::Run");
	while (true) {
		if (const auto ecode = Window::ProcessMessages(wnd.GetHandle())) {
			return *ecode;
		}
		wnd.Gfx().BeginFrame(0.07f, 0.0f, 0.12f);
		UpdateFrame();
		DrawFrame();
		wnd.Gfx().EndFrame();
	}
}

void App::UpdateFrame()
{
	float dt = ft.Mark();
}

void App::DrawFrame()
{

}

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
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
}

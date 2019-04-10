
#include "application.h"


int main()
{
	Application* app = new Application();
	app->init();



	while (app->isRunning())
	{
		app->handleEvents();
		app->update();
		app->render();
	}

	app->cleanup();

	delete app;
	app = nullptr;



	return 0;
}
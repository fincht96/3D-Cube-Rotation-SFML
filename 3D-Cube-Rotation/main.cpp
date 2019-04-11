
#include "application.h"

#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#define WINDOW_TITLE "3D-Cube-Rotation"

int main()
{
	Application* app = new Application();
	app->init(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);



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
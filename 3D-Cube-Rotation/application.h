#ifndef APPLICATION_H
#define APPLICATION_H


#include <SFML/Graphics.hpp>
#include "../3D-Cube-Rotation/raster_graphics.h"
#include "../3D-Cube-Rotation/globals.h"

class Application
{
private:
	bool m_running = false;
	RasterGraphics* m_pRasterGraphics;				  
	sf::RenderWindow* m_pRenderWindow;



public:
	void init();
	void handleEvents();
	void update();
	void render();
	void cleanup();

	bool isRunning() { return m_running; }
	void quit() { m_running = false; }

};


#endif
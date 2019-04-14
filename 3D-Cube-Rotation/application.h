#ifndef APPLICATION_H
#define APPLICATION_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "../3D-Cube-Rotation/raster_graphics.h"
#include "../3D-Cube-Rotation/global_types.h"



class Application
{
private:
	bool m_running = false;
	RasterGraphics m_rasterGraphics;				  
	sf::RenderWindow m_renderWindow;
	Mesh mMeshCube;
	Mat4x4 mMatProj;		// projection matrix
	void MultiplyMatrixVector(vec3d &i, vec3d &o, Mat4x4 &m);
	

public:
	void init(sf::Vector2u windowSize, std::string windowTitle);
	void handleEvents();
	void update();
	void render();
	void cleanup();

	bool isRunning() { return m_running; }
	void quit() { m_running = false; }

};


#endif
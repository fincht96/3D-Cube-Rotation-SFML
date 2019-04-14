#include "../3D-Cube-Rotation/raster_graphics.h"


void RasterGraphics::init(sf::Vector2u size)
{
	// resizes the render texture
	m_renderTexture.create(size.x, size.y);

	
}

void RasterGraphics::drawLine(sf::Vector2f p0, sf::Vector2f p1)
{

	sf::Vertex line[] =
	{
		sf::Vertex(p0),
		sf::Vertex(p1)
	};

	m_renderTexture.draw(line, 2, sf::Lines);
}




void RasterGraphics::drawTriangle(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2)
{
	drawLine(p0, p1);
	drawLine(p1, p2);
	drawLine(p2, p0);
}

void RasterGraphics::drawTriangle(triangle tris)
{
	// converts each vec3d vertice into a Vector2f vertice
	sf::Vector2f p0 = sf::Vector2f((float)tris.p[0].x, (float)tris.p[0].y);
	sf::Vector2f p1 = sf::Vector2f((float)tris.p[1].x, (float)tris.p[1].y);
	sf::Vector2f p2 = sf::Vector2f((float)tris.p[2].x, (float)tris.p[2].y);

	drawLine(p0, p1);
	drawLine(p1, p2);
	drawLine(p2, p0);
}


void RasterGraphics::fill(sf::Color col)
{
	m_renderTexture.clear(col);
}

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




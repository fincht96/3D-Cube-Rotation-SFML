#ifndef RASTERGRAPHICS_H
#define RASTERGRAPHICS_H


#include <SFML/Graphics.hpp>
#include "../3D-Cube-Rotation/global_types.h"

/*
	Manages all pixel drawing related operations, draws pixels to a render texture

 */

class RasterGraphics
{
public:
	void init(sf::Vector2u size);						
	void drawLine(sf::Vector2f p0, sf::Vector2f p1);	
	void drawTriangle(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);
	void drawTriangle(triangle tris);
	void fill(sf::Color col);

	const sf::Texture& getTexture() { return m_renderTexture.getTexture(); }

private:
	
	sf::RenderTexture m_renderTexture;		// enables off screen drawing

};


#endif
#ifndef RASTERGRAPHICS_H
#define RASTERGRAPHICS_H

#include <SFML/Graphics.hpp>

/*
	Manages all pixel drawing related operations, draws pixels to a render texture

 */

class RasterGraphics
{
public:
	void init(sf::Vector2u size);						
	void drawLine(sf::Vector2f p0, sf::Vector2f p1);	
	void drawTriangle(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);


	const sf::Texture& getTexture() { return m_renderTexture.getTexture(); }

private:
	sf::CircleShape shape;
	sf::RenderTexture m_renderTexture;		// enables off screen drawing

};


#endif
#ifndef RASTERGRAPHICS_H
#define RASTERGRAPHICS_H

#include <SFML/Graphics.hpp>
#include "../3D-Cube-Rotation/draw_shape.h"

/*
	Manages all pixel drawing related operations, draws pixels to a render texture

 */

class RasterGraphics
{
public:
	void init();		
	void setPxGridSize(sf::Vector2f size);
	//void drawLine(sf::Vector2f startPos, sf::Vector2f endPos);
	DrawShape* m_pDrawShape;

	void setDrawShape(DrawShape* pDrawshape) {m_pDrawShape = pDrawshape;}		// allows the drawshape subtype interface to be set at run time


private:
	sf::RenderTexture* m_pRenderTexture;
	RasterGrid* m_pGrid;					

};


#endif
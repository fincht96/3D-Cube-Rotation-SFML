#pragma once

#include <SFML/Graphics.hpp>

class DrawShape
{
public:
	virtual void draw(RasterGrid* pRasterGrid) = 0;

};



class DrawLine : public DrawShape
{
private:
	sf::Vector2f m_startPos = {0.0 , 0.0};
	sf::Vector2f m_finishPos = { 0.0 , 0.0 };

public:
	void setStartPos(sf::Vector2f pos) { m_startPos = pos; }
	void setFinishPos(sf::Vector2f pos) { m_finishPos = pos; }

	void draw(RasterGrid* pRasterGrid) override;

};

class DrawTriangle : public DrawShape
{
	void draw(RasterGrid* pRasterGrid) override;
};
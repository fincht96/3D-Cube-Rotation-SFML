#include "../3D-Cube-Rotation/application.h"



void Application::init(sf::Vector2u windowSize, std::string windowTitle)
{
	// creates a new render window
	m_renderWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle);

	// sets application running
	m_running = true;
	
	// initialises rastergraphics
	m_rasterGraphics.init(windowSize);
}





void Application::update()
{
	m_rasterGraphics.drawLine(sf::Vector2f(620, 370), sf::Vector2f(410, 166));
	

	m_rasterGraphics.drawTriangle(sf::Vector2f(50, 50), sf::Vector2f(250, 340), sf::Vector2f(100, 230));

	m_rasterGraphics.drawTriangle(sf::Vector2f(480, 222), sf::Vector2f(189, 150), sf::Vector2f(35, 67));
}







void Application::handleEvents()
{
	sf::Event event;
	while (m_renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->quit();
		}


	}



}




void Application::render()
{
	m_renderWindow.clear();					
	m_renderWindow.draw(sf::Sprite(m_rasterGraphics.getTexture()));
	m_renderWindow.display();
}



void Application::cleanup()
{

	
}
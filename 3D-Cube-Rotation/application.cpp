#include "../3D-Cube-Rotation/application.h"



void Application::init()
{
	
	
	m_pRasterGraphics = new RasterGraphics();
	m_pRenderWindow = new sf::RenderWindow();
	


	m_pRasterGraphics->init(*m_pRenderWindow);


	m_running = true;
	


}





void Application::update()
{


}







void Application::handleEvents()
{
	sf::Event event;
	while (m_pRenderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->quit();
		}
	}



}




void Application::render()
{
	m_pRenderWindow->clear();					// clear renderwindow
	

	m_pRenderWindow->draw(/* some graphics */);


	m_pRenderWindow->display();
}



void Application::cleanup()
{
	delete m_pRasterGraphics;
	delete m_pRenderWindow;

	m_pRasterGraphics = nullptr;
	m_pRenderWindow = nullptr;

	
}
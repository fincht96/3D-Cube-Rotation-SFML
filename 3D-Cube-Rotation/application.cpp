#include "../3D-Cube-Rotation/application.h"
#include <iostream>


void Application::init(sf::Vector2u windowSize, std::string windowTitle)
{
	// creates a new render window
	m_renderWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle);

	// sets application running
	m_running = true;
	
	// initialises rastergraphics
	m_rasterGraphics.init(windowSize);



	mMeshCube.tris =
	{
		// SOUTH
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// EAST                                                      
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		// NORTH                                                     
		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// WEST                                                      
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// TOP                                                       
		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		// BOTTOM                                                    
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },
	};





	//mMatProj.m[0][0] = fAspectRatio * fFovRad;		 
	//mMatProj.m[1][1] = fFovRad;						
	//mMatProj.m[2][2] = fFar / (fFar = fNear);
	//mMatProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	//mMatProj.m[2][3] = 1.0f;
	//mMatProj.m[3][3] = 0.0f;
 
}





void Application::update()
{
	// projection matrix
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;		// 90 degrees
	float fAspectRatio = (float)m_renderWindow.getSize().y / (float)m_renderWindow.getSize().x; // aspect ratio
	float fFovRad = 1.0f / tanf((fFov/2) * 0.0174533f);		// converted field of view to rad



	m_rasterGraphics.fill(sf::Color::Black);


	//m_rasterGraphics.drawLine(sf::Vector2f(620, 370), sf::Vector2f(410, 166));
	//m_rasterGraphics.drawTriangle(sf::Vector2f(50, 50), sf::Vector2f(250, 340), sf::Vector2f(100, 230));
	//m_rasterGraphics.drawTriangle(sf::Vector2f(480, 222), sf::Vector2f(189, 150), sf::Vector2f(35, 67));






	//m_rasterGraphics.drawTriangle(mMeshCube.tris[0]);
	//m_rasterGraphics.drawTriangle(mMeshCube.tris[1]);


	//m_rasterGraphics.drawTriangle(sf::Vector2f(0, 0), sf::Vector2f(630, 470), sf::Vector2f(40, 40));







	/* iterates through each triangle in mesh*/
	for (const auto tris : mMeshCube.tris)
	{
		// represents the new projected triangle after transformation
		triangle triProjected, triTranslated;

		triTranslated = tris;

		triTranslated.p[0].z = tris.p[0].z + 3.0f;
		triTranslated.p[1].z = tris.p[1].z + 3.0f;
		triTranslated.p[2].z = tris.p[2].z + 3.0f;

	
			

		// First vertice
		// ---------------------------------


		// new x component 
		if (triTranslated.p[0].z == 0.0f)
		{
			triProjected.p[0].x  = triTranslated.p[0].x * fAspectRatio * fFovRad;
		}

		else
		{
			triProjected.p[0].x  = (triTranslated.p[0].x * fAspectRatio * fFovRad) / triTranslated.p[0].z;
		}
		

		// new y component 

		if (triTranslated.p[0].z == 0.0f)
		{
			triProjected.p[0].y = (triTranslated.p[0].y * fFovRad);
		}

		else
		{
			triProjected.p[0].y = (triTranslated.p[0].y * fFovRad) / triTranslated.p[0].z;
		}
		
		
		// new z component 
		triProjected.p[0].z = ((triTranslated.p[0].z * fFar) / (fFar - fNear)) - ((fNear * fFar) / (fFar - fNear));
 

		// Second vertice
		// ---------------------------------

		// new x component 
		if (triTranslated.p[1].z == 0.0f)
		{
			triProjected.p[1].x = (triTranslated.p[1].x * fAspectRatio * fFovRad);
		}
		
		else
		{
			triProjected.p[1].x = (triTranslated.p[1].x * fAspectRatio * fFovRad) / triTranslated.p[1].z;
		}


		// new y component 
		if (triTranslated.p[1].z == 0.0f)
		{
			triProjected.p[1].y = triTranslated.p[1].y * fFovRad;
		}

		else
		{
			triProjected.p[1].y = (triTranslated.p[1].y * fFovRad) / triTranslated.p[1].z;
		}
		


		// new z component 
		triProjected.p[1].z = ((triTranslated.p[1].z * fFar) / (fFar - fNear)) - ((fNear * fFar) / (fFar - fNear));



		// Third vertice
		// ---------------------------------

		// new x component 
		if (triTranslated.p[2].z == 0.0f)
		{
			triProjected.p[2].x = (triTranslated.p[2].x * fAspectRatio * fFovRad);
		}

		else
		{
			triProjected.p[2].x = (triTranslated.p[2].x * fAspectRatio * fFovRad) / triTranslated.p[2].z;
		}
		
		

		// new y component 
		if (tris.p[2].z == 0.0f)
		{
			triProjected.p[2].y = triTranslated.p[2].y * fFovRad;
		}

		else
		{
			triProjected.p[2].y = (triTranslated.p[2].y * fFovRad) / triTranslated.p[2].z;
		}
		

		// new z component 
		triProjected.p[2].z = ((triTranslated.p[2].z * fFar) / (fFar - fNear)) - ((fNear * fFar) / (fFar - fNear));




		// Scale into view
		triProjected.p[0].x += 1.0f; 
		triProjected.p[0].y += 1.0f;

		triProjected.p[1].x += 1.0f;
		triProjected.p[1].y += 1.0f;

		triProjected.p[2].x += 1.0f;
		triProjected.p[2].y += 1.0f;

		triProjected.p[0].x *= 0.5f * (float)m_renderWindow.getSize().x;
		triProjected.p[0].y *= 0.5f * (float)m_renderWindow.getSize().y;
		
		triProjected.p[1].x *= 0.5f * (float)m_renderWindow.getSize().x;
		triProjected.p[1].y *= 0.5f * (float)m_renderWindow.getSize().y;

		triProjected.p[2].x *= 0.5f * (float)m_renderWindow.getSize().x;
		triProjected.p[2].y *= 0.5f * (float)m_renderWindow.getSize().y;

		std::cout << std::endl;
		std::cout << " x: " << triProjected.p[0].x << " y: " << triProjected.p[0].y << " z: " << triProjected.p[0].z << std::endl;
		std::cout << " x: " << triProjected.p[1].x << " y: " << triProjected.p[1].y << " z: " << triProjected.p[1].z << std::endl;
		std::cout << " x: " << triProjected.p[2].x << " y: " << triProjected.p[2].y << " z: " << triProjected.p[2].z << std::endl;


		// draws new triangle to the screen
		m_rasterGraphics.drawTriangle(triProjected);

	}
	




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
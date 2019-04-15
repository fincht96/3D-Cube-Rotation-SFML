#include "../3D-Cube-Rotation/application.h"
#include <iostream>



void Application::MultiplyMatrixVector(const vec3d &i, vec3d &o, Mat4x4 &m)
{
	o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
	o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
	o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
	float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

	if (w != 0.0f)
	{
		o.x /= w; o.y /= w; o.z /= w;
	}



}



void Application::init(sf::Vector2u windowSize, std::string windowTitle)
{
	// creates a new render window
	m_renderWindow.create(sf::VideoMode(windowSize.x, windowSize.y), windowTitle);


	m_renderWindow.setVerticalSyncEnabled(true); // call it once, after creating the window

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

	// Projection Matrix
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = (float)m_renderWindow.getSize().y / (float)m_renderWindow.getSize().x;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);



	mMatProj.m[0][0] = fAspectRatio * fFovRad;		 
	mMatProj.m[1][1] = fFovRad;						
	mMatProj.m[2][2] = fFar / (fFar = fNear);
	mMatProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	mMatProj.m[2][3] = 1.0f;
	mMatProj.m[3][3] = 0.0f;
 
}





void Application::update()
{
	m_rasterGraphics.fill(sf::Color::Black);


	int frameTime = mClock.getElapsedTime().asMilliseconds();

	
	


	// Set up rotation matrices
	Mat4x4 matRotZ, matRotX;
	fTheta += 0.001f * (float)frameTime;

	// Rotation Z
	matRotZ.m[0][0] = cosf(fTheta);
	matRotZ.m[0][1] = sinf(fTheta);
	matRotZ.m[1][0] = -sinf(fTheta);
	matRotZ.m[1][1] = cosf(fTheta);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;

	// Rotation X
	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cosf(fTheta * 0.5f);
	matRotX.m[1][2] = sinf(fTheta * 0.5f);
	matRotX.m[2][1] = -sinf(fTheta * 0.5f);
	matRotX.m[2][2] = cosf(fTheta * 0.5f);
	matRotX.m[3][3] = 1;




	/* iterates through each triangle in mesh*/
	for (const auto tris : mMeshCube.tris)
	{
		// represents the new projected triangle after transformation
		triangle triProjected, triTranslated, triRotatedZ, triRotatedZX;

		

		// Rotate in Z-Axis (Working)
		MultiplyMatrixVector(tris.p[0], triRotatedZ.p[0], matRotZ);
		MultiplyMatrixVector(tris.p[1], triRotatedZ.p[1], matRotZ);
		MultiplyMatrixVector(tris.p[2], triRotatedZ.p[2], matRotZ);

		// Rotate in X-Axis(Working)
		MultiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
		MultiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
		MultiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);
		


		// Offset into the screen
		triTranslated = triRotatedZX;
		triTranslated.p[0].z = triRotatedZX.p[0].z + 3.0f;
		triTranslated.p[1].z = triRotatedZX.p[1].z + 3.0f;
		triTranslated.p[2].z = triRotatedZX.p[2].z + 3.0f;



		// Project triangles from 3D --> 2D
		MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], mMatProj);
		MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], mMatProj);
		MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], mMatProj);


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

		// draws new triangle to the screen
		m_rasterGraphics.drawTriangle(triProjected);
		

	}




	mClock.restart();


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
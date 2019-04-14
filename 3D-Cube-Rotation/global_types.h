#pragma once



struct vec3d
{
	float x = 0;
	float y = 0;
	float z = 0;
};

// contains three vertices
struct triangle
{
	vec3d p[3];
};


// represents object
struct Mesh
{
	std::vector<triangle> tris;
};


struct Mat4x4
{
	// row, column
	float m[4][4] = { 0 };
};
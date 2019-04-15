#pragma once



struct vec3d
{
	float x, y, z;

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


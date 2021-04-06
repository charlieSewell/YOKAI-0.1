//AABB.hpp - Axis Alligned Bounding Box

#pragma once

#include <glm/glm.hpp>

struct Points
{
	float xmin;
	float xmax;
	float ymin;
	float ymax;
	float zmin;
	float zmax;
};

class AABB
{
public:
	AABB() {};
	AABB(glm::vec3* position, float width, float length, float height);

	glm::vec3* getPosition();
	bool checkCollision(AABB &other);

	Points getAABBPoints();
	float getHeight();

private:
	void updatePoints();

	glm::vec3* m_position;

	float m_width;
	float m_length;
	float m_height;

	Points m_points;
};
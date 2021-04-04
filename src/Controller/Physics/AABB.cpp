//AABB.cpp - Axis Aligned Bounding Box

#include "Controller/Physics/AABB.hpp"

AABB::AABB(glm::vec3* position, float width, float length, float height)
	: m_position(position), m_width(width), m_length(length), m_height(height)
{
	updatePoints();
}

bool AABB::checkCollision(AABB &other)
{
	updatePoints();
	other.updatePoints();

	return (m_points.xmin <= other.getAABBPoints().xmax && m_points.xmax >= other.getAABBPoints().xmin &&
		m_points.ymin <= other.getAABBPoints().ymax && m_points.ymax >= other.getAABBPoints().ymin &&
		m_points.zmin <= other.getAABBPoints().zmax && m_points.zmax >= other.getAABBPoints().zmin);
}

void AABB::updatePoints()
{
	m_points.xmin = m_position->x - m_width / 2;
	m_points.xmax = m_position->x + m_width / 2;

	m_points.ymin = m_position->y - m_height / 2;
	m_points.ymax = m_position->y + m_height / 2;

	m_points.zmin = m_position->z - m_length / 2;
	m_points.zmax = m_position->z + m_length / 2;
}

Points AABB::getAABBPoints()
{
	updatePoints();
	return m_points;
}

float AABB::getHeight()
{
	return m_points.ymax - m_points.ymin;
}

glm::vec3* AABB::getPosition()
{
	return m_position;
}
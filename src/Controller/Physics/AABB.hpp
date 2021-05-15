//AABB.hpp - Axis Alligned Bounding Box

#pragma once

#include "Model/Transform.hpp"
/**
 * @struct Points
 * @brief Points that make up an AABB
 */
struct Points
{
    ///X min of AABB
	float xmin;
    ///X max of AABB
	float xmax;
    ///Y min of AABB
	float ymin;
    ///Y max of AABB
	float ymax;
    ///Z min of AABB
	float zmin;
    ///Z max of AABB
	float zmax;
};
/**
 * @class AABB
 * @brief Class for createing Axis Aligned Bounding Boxes
 */
class AABB
{
public:
    /**
     * @brief Default Constructor for AABB
     */
	AABB() {};
    /**
     * @brief Constructor for AABB
     * @param vec3* - position
     * @param float - width
     * @param float - length
     * @param float - height
     */
	AABB(Transform* position, float width, float length, float height);
    /**
     * Returns position of AABB
     * @return vec3*
     */
	glm::vec3 getPosition();
    /**
     * @brief Checks collisions between 2 AABBs
     * @param AABB& - other
     * @return bool
     */
	bool checkCollision(AABB &other);
    /**
     * @brief Gets the points of an AABB
     * @return Points
     */
	Points getAABBPoints();
    /**
     * @brief Gets the height of an AABB
     * @return float
     */
	float getHeight();

private:
  /**
   * @brief Updates the points of an AABB
   */
	void updatePoints();
    ///Position of AABB
	Transform* m_transform;
    ///Width of AABB
	float m_width;
    ///Length of AABB
	float m_length;
    ///Height of AABB
	float m_height;
    ///Points of the AABB
	Points m_points;
};
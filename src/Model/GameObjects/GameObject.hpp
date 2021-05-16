//GameObject.hpp

#pragma once


#include <glm/glm.hpp>
#include "View/Renderer/Shader.hpp"
#include "Controller/LuaManager.hpp"

/**
 * @class GameObjectType
 * @brief Stores enum values for the types of GameObjects
 */
enum class GameObjectType
{
	player, staticObject, npc
};

/**
 * @class GameObject
 * @brief Responsible for functions of every object created within the game
 */
class GameObject
{
public:
    /*!
     * @brief Registers the class for Lua
     */
    static void registerClass();

    /*!
     * @brief Virtual getter for the position of the GameObject
     * @return m_position
     */
    virtual glm::vec3 getPosition() const;

    /*!
     * @brief Virtual getter for the transform of the GameObject
     * @return m_transform
     */
    virtual glm::mat4 getTransform() const;

    /*!
     * @brief Virtual setter for the GameObject position
     * @param vec3 - position
     */
	virtual void setPosition(glm::vec3 position);

    /*!
     * @brief Virtual setter for the GameObject position within Lua
     * @param float - x
     * @param float - y
     * @param float - z
     */
    virtual void setLuaPosition(float x,float y,float z);

    /*!
     * @brief Virtual setter for the GameObject scale within Lua
     * @param float - x
     * @param float - y
     * @param float - z
     */
    virtual void setLuaScale(float x,float y,float z);

    /*!
     * @brief Virtual setter for the GameObject scale
     * @param vec3 - scale
     */
    virtual void setScale(glm::vec3 scale);

    /*!
     * @brief Pure virtual setter for the GameObject collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	virtual void setCollider(float width, float length, float height) = 0;

    /*!
     * @brief Virtual update call for the GameObject
     */
	virtual void update(float dt);

    /*!
     * @brief Pure virtual draw call for the GameObject
     */
    virtual void draw() = 0;

protected:
	/// Type of GameObject
	GameObjectType m_EntityType;

    /// Scale of the GameObject
	glm::vec3 m_scale;

	// Only used for physics, and should be yeeted
	// in favour for using position inside transform 
    glm::vec3 m_position;

    /// Transform of the GameObject
    glm::mat4 m_transform;
};

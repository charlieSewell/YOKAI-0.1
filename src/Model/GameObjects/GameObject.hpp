//GameObject.hpp

#pragma once

#include "View/Renderer/Shader.hpp"
#include "Controller/LuaManager.hpp"
#include "Model/Components/Transform.hpp"

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
	GameObject();
    /*!
     * @brief Registers the class for Lua
     */
    static void registerClass();

    /*!
     * @brief Virtual getter for the transform of the GameObject
     * @return m_transform
     */
    virtual Transform getTransform();

	/*!
	* @brief Virtual getter for the position of the GameObject
	* @return m_position
	*/
	virtual glm::vec3 getLuaPosition();

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
     * @brief Pure virtual setter for the GameObject collider
     * @param float - width
     * @param float - length
     * @param float - height
     */
	virtual void setCollider(float width, float length, float height) = 0;

    /*!
     * @brief Virtual update call for the GameObject
     */
	virtual void update();

    /*!
     * @brief Pure virtual draw call for the GameObject
     */
    virtual void draw() = 0;

protected:
	/// Type of GameObject
	GameObjectType m_EntityType;

    /// Transform of the GameObject
    Transform m_transform;
};

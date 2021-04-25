#pragma once

#include <functional>
#include <map>
#include <glm/glm.hpp>
#include "Controller/LuaManager.hpp"

enum class InputEvent
{
	moveForward,
	moveBackward,
	moveLeft,
	moveRight,
	jump,
	moveDown,
	increaseSpeed,
	xyLook,
    closePressed,
    closeReleased,
	togglePhysicsPressed,
	togglePhysicsReleased,
	toggleWireFramePressed,
	toggleWireFrameReleased,
    toggleMenuPressed,
    toggleMenuReleased,
    mouseClicked
};

enum class RenderEvent
{
    getViewMatrix,
    getPerspective
};
/**
 * @class EMS
 * @brief Singleton Class Defining The Event Management System
 */
class EMS
{
  public:
    /**
     * @brief Gets the instance of the EMS
     * @return EMS&
     */
    static EMS& getInstance();
    ///Deleted copy constructor
	EMS(EMS const&)			 = delete;
    ///Deleted = operator
	void operator=(EMS const&) = delete;
    /**
     * @brief Initialises the EMS
     */
    void Init();
    /**
     * @brief Adds an input Event callback
     * @param InputEvent - event
     * @param function<void()> - func
     */
	void add(InputEvent event, std::function<void()> func);
    /**
     * @brief Adds a Render Event callback
     * @param RenderEvent - event
     * @param function<mat4()> - func
     */
    void add(RenderEvent event, std::function<glm::mat4()> func);
    /**
     * @brief Adds a Render Event callback
     * @param InputEvent - event
     * @param function<void(double x, double y)> - func
     */
	void add(InputEvent event, std::function<void(double x, double)> func);
    /**
     * @brief Fires an Input Event
     * @param InputEvent - event
     */
	void fire(InputEvent event);
    /**
     * @brief Fires a Render Event
     * @param RenderEvent - event
     * @return mat4
     */
    glm::mat4 fire(RenderEvent event);
    /**
     * @brief Fires an Input Event with Data
     * @param InputEvent event
     * @param double - x
     * @param double - y
     */
	void fire(InputEvent event, double x, double y);
  private:
      ///Privatised constructor of EMS
	  EMS() {}
      ///Multimap storing input events against their function pointers
	  std::multimap<InputEvent, std::function<void()>> m_inputEventList;
      ///Function pointer for mouse Look
	  std::function<void(double, double)> m_xyLook;
      ///Function pointer for View Matrix
      std::function<glm::mat4(void)> m_viewMatrix;
      ///Function pointer for Perspective matrix
      std::function<glm::mat4(void)> m_perspective;
};

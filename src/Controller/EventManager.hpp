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
    close,
	togglePhysicsPressed,
	togglePhysicsReleased,
	toggleWireFramePressed,
	toggleWireFrameReleased,
    toggleMenuPressed,
    toggleMenuReleased
};

enum class RenderEvent
{
    getViewMatrix,
    getPerspective
};

class EMS
{
  public:
    static EMS& getInstance();
	EMS(EMS const&)			 = delete;
	void operator=(EMS const&) = delete;
    void Init();
	void add(InputEvent event, std::function<void()> func);
    void add(RenderEvent event, std::function<glm::mat4()> func);
	void add(InputEvent event, std::function<void(double x, double)> func);

	void fire(InputEvent event);
    glm::mat4 fire(RenderEvent event);
	void fire(InputEvent event, double x, double y);
    void luaFire(InputEvent event, float);
  private:
	  EMS() {}

	  std::multimap<InputEvent, std::function<void()>> m_inputEventList;
	  std::function<void(double, double)> m_xyLook;
      std::function<glm::mat4(void)> m_viewMatrix;
    std::function<glm::mat4(void)> m_perspective;
};

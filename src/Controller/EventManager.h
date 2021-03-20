#pragma once

#include <functional>
#include <map>

enum class InputEvent
{ 
	moveForward, 
	moveBackward, 
	moveLeft, 
	moveRight, 
	moveUp, 
	moveDown,
	increaseSpeed,
	xyLook
};

enum class ExampleEvent
{
	example
};

class EMS 
{
  public:
    static EMS& getInstance();
	EMS(EMS const&)			 = delete;
	void operator=(EMS const&) = delete;


	void add(InputEvent event, std::function<void()> func);
	void add(InputEvent event, std::function<void(double x, double)> func);

	void fire(InputEvent event);
	void fire(InputEvent event, double x, double y);


  private:
	  EMS() {}

	  std::multimap<InputEvent, std::function<void()>> m_inputEventList;
	  std::function<void(double, double)> m_xyLook;

};
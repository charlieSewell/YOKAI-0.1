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
	void fire(InputEvent event);

	//exmple of how to add events that requrie different parameters
	void add(ExampleEvent event, std::function<void()> func);
	void fire(ExampleEvent event);


  private:
	  EMS() {}

	  std::multimap<InputEvent, std::function<void()>> m_inputEventList;

	  // having targeted lists will mean we're only searching for relevant events 
	  std::multimap<ExampleEvent, std::function<void()>> m_exampleEventList;

};
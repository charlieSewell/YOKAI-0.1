//EventManager.cpp

#include "EventManager.h"

EMS& EMS::getInstance() 
{
	static EMS instance;
	return instance;
}

void EMS::add(InputEvent event, std::function<void()> func)
{
    m_inputEventList.insert(std::pair<InputEvent, std::function<void()>>(event, func));
}

void EMS::fire(InputEvent event) 
{
	for(std::multimap<InputEvent, std::function<void()>>::iterator itr = m_inputEventList.begin(); itr != m_inputEventList.end(); ++itr)
	{
		if(itr->first == event)
			(itr->second)();
	}
}

// EXAMPLE, DELTE LATER
void EMS::add(ExampleEvent event, std::function<void()> func)
{
	m_exampleEventList.insert(std::pair<ExampleEvent, std::function<void()>>(event, func));
}

void EMS::fire(ExampleEvent event)
{
	for (std::multimap<ExampleEvent, std::function<void()>>::iterator itr = m_exampleEventList.begin(); itr != m_exampleEventList.end(); ++itr)
	{
		if (itr->first == event)
			(itr->second)();
	}
}

// END EXAMPLE
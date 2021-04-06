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

void EMS::add(InputEvent event, std::function<void(double, double)> func)
{
	if(event == InputEvent::xyLook)
		m_xyLook = func;
}
void EMS::add(RenderEvent event, std::function<glm::mat4()> func)
{
    if(event == RenderEvent::getViewMatrix)
        m_viewMatrix = func;
}

void EMS::fire(InputEvent event) 
{
	for(std::multimap<InputEvent, std::function<void()>>::iterator itr = m_inputEventList.begin(); itr != m_inputEventList.end(); ++itr)
	{
		if(itr->first == event)
			(itr->second)();
	}
}

void EMS::fire(InputEvent event, double x, double y)
{
	if (event == InputEvent::xyLook)
		m_xyLook(x, y);
}
glm::mat4 EMS::fire(RenderEvent event)
{
    if (event == RenderEvent::getViewMatrix)
        return m_viewMatrix();
}
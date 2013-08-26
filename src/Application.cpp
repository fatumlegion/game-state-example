#include "Application.hpp"
#include "LevelState.hpp"

app_ptr Application::m_App = nullptr;

app_ptr Application::getSingleton()
{
	if (m_App == nullptr)
		m_App = app_ptr(new Application());
	return std::move(m_App);
}

void Application::initialize()
{
	videoMode.width = 1280;
	videoMode.height = 720;
	videoMode.bitsPerPixel = 32;
	
	timeNow = gameClock.getElapsedTime().asSeconds();
	dt = 1.0f / 60.0f;
	timeFrame = 0.0f;
	timeActual = 0.0f;
	accumulator = 0.0f;
}

void Application::release()
{
	popAllStates();
}

void Application::popAllStates()
{
	for (int i = 0; i < cont_states.size(); ++i)
	{
		GameState *state = cont_states.top();
		cont_states.pop();
		delete state;
	}
}

void Application::pushState(GameState *state)
{
	cont_states.push(state);
}

int Application::run(int argc, char **argv)
{
	rwin.create(videoMode, "Game State Test", !sf::Style::Resize | sf::Style::Close);
	
	pushState(new LevelState());
	
	while (rwin.isOpen())
	{
		sf::Event event;
		while (rwin.pollEvent(event))
		{
			cont_states.top()->input(event);
			switch (event.type)
			{
				case sf::Event::Closed:
					rwin.close();
				break;
			}
		}
		
		timeNow = gameClock.getElapsedTime().asSeconds();
		timeFrame = timeNow - timeActual;
		
		if (timeFrame > 0.25f)
			timeFrame = 0.25f;
		
		timeActual = timeNow;
		accumulator += timeFrame;
		
		while (accumulator >= dt)
		{
			cont_states.top()->update(dt);
			accumulator -= dt;
		}
		
		const float interpolation = accumulator / dt;
		
		rwin.clear();
		cont_states.top()->draw(rwin, interpolation);
		rwin.display();
	}
	release();
	return 0;
}
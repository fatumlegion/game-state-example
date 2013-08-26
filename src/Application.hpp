#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <memory>
#include <stack>

class Application;
typedef std::unique_ptr<Application> app_ptr;

class Application
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow rwin;
	static app_ptr m_App;
	
	float dt, timeNow, timeFrame, timeActual, accumulator;
	sf::Clock gameClock;
	
	std::stack<GameState*> cont_states;
public:
	static app_ptr getSingleton();
	void initialize();
	void release();
	int run(int argc, char **argv);
	
	void popAllStates();
	void pushState(GameState *state);
};
#endif
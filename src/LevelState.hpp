#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP
#include "GameState.hpp"
class LevelState : public GameState
{
public:
	LevelState();
	~LevelState() { }
	void draw(sf::RenderWindow &rwin, float interp);
	void input(sf::Event &event);
	void update(float dt);
};
#endif
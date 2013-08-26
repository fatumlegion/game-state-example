#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <SFML/Graphics.hpp>
class GameState
{
public:
	virtual void input(sf::Event &event) = 0;
	virtual void draw(sf::RenderWindow &rwin, float interp) = 0;
	virtual void update(float dt) = 0;
};
#endif
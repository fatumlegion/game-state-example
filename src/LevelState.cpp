#include "LevelState.hpp"

LevelState::LevelState()
{
	printf("Let's initialize everything for the level that we need here!\n");
}

void LevelState::input(sf::Event& event)
{
	//TODO: handle events
}

void LevelState::draw(sf::RenderWindow &rwin, float interp)
{
	/* In the player object (player->draw...)
	 * sf::Vector2f alphaInterp = pos;
	 * if (moving) alphaInterp += interp;
	 * setPosition(alphaInterp)
	*/
}

void LevelState::update(float dt)
{
	//TODO: handle update
}






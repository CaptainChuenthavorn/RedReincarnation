#pragma once
#include <sfml\Graphics.hpp>
#define MAX_ITEMS 2 //Restart Quit
class RestartMenu
{
public:
	RestartMenu(float width, float height);
	~RestartMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }

private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text Remenu[MAX_ITEMS];
};
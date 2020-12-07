#include "RestartMenu.h"

RestartMenu::RestartMenu(float width, float height)
{
	if (!font.loadFromFile("FSEX300.ttf"))
	{
		//handle error
	}
	Remenu[0].setFont(font);
	Remenu[0].setCharacterSize(72);
	Remenu[0].setFillColor(sf::Color::Red);
	Remenu[0].setString("Restart");
	Remenu[0].setOrigin(Remenu[0].getLocalBounds().width / 2, Remenu[0].getLocalBounds().height / 2);
	//Remenu[0].setPosition(sf::Vector2f((width / 6 * 5) - 20, (height / (MAX_ITEMS + 5) * 2) + 10));
	Remenu[0].setPosition(sf::Vector2f(width / 2 - 200, height / (MAX_ITEMS + 1) * 1));//Remenu[0].setPosition(sf::Vector2f(width/2-200,height/(MAX_ITEMS+1)*1 - 100));

	Remenu[1].setFont(font);
	Remenu[1].setFillColor(sf::Color::White);
	Remenu[1].setString("Exit");
	Remenu[1].setOrigin(Remenu[1].getLocalBounds().width / 2, Remenu[1].getLocalBounds().height / 2);
	//Remenu[1].setPosition(sf::Vector2f((width / 6 * 5) - 20, (height / (MAX_ITEMS + 5) * 3) + 40));
	Remenu[1].setPosition(sf::Vector2f(width / 2 - 200, height / (MAX_ITEMS + 1) * 2));//	Remenu[1].setPosition(sf::Vector2f(width / 2-200, height / (MAX_ITEMS + 1) * 2 - 200));
}

RestartMenu::~RestartMenu()
{
}

void RestartMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS;i++)
	{
		window.draw(Remenu[i]);
	}
}

void RestartMenu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		Remenu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		Remenu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void RestartMenu::MoveDown()
{
	if (selectedItem + 1 < MAX_ITEMS)
	{
		Remenu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		Remenu[selectedItem].setFillColor(sf::Color::Red);
	}
}
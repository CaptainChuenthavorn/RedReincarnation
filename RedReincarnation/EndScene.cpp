#include "EndScene.h"

EndScene::EndScene(float width, float height)
{
	if (!font.loadFromFile("FSEX300.ttf"))
	{
		//handle error
	}
	Endmenu[0].setFont(font);
	Endmenu[0].setCharacterSize(32);
	Endmenu[0].setFillColor(sf::Color::Red);
	Endmenu[0].setString("Main menu");
	//Endmenu[0].setOrigin(Endmenu[0].getLocalBounds().width / 2, Endmenu[0].getLocalBounds().height / 2);
	//Remenu[0].setPosition(sf::Vector2f((width / 6 * 5) - 20, (height / (MAX_ITEMS + 5) * 2) + 10));
	Endmenu[0].setPosition(sf::Vector2f(857-188, 584-109));//Remenu[0].setPosition(sf::Vector2f(width/2-200,height/(MAX_ITEMS+1)*1 - 100));

	Endmenu[1].setFont(font);
	Endmenu[1].setCharacterSize(32);
	Endmenu[1].setFillColor(sf::Color::White);
	Endmenu[1].setString("Exit");
	//Endmenu[1].setOrigin(Endmenu[1].getLocalBounds().width / 2, Endmenu[1].getLocalBounds().height / 2);
	//Remenu[1].setPosition(sf::Vector2f((width / 6 * 5) - 20, (height / (MAX_ITEMS + 5) * 3) + 40));
	Endmenu[1].setPosition(sf::Vector2f(900-188, 666-109));//	Remenu[1].setPosition(sf::Vector2f(width / 2-200, height / (MAX_ITEMS + 1) * 2 - 200));
} 

EndScene::~EndScene()
{
}

void EndScene::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS;i++)
	{
		window.draw(Endmenu[i]);
	}
}

void EndScene::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		Endmenu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		Endmenu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void EndScene::MoveDown()
{
	if (selectedItem + 1 < MAX_ITEMS)
	{
		Endmenu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		Endmenu[selectedItem].setFillColor(sf::Color::Red);
	}
}
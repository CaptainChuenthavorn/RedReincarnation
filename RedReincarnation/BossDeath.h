#pragma once
#include <SFML\Graphics.hpp>
#include "animationEnemyDeath.h"
class BossDeath
{
public:

	BossDeath(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float PosX, float PosY);
	~BossDeath();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetSize() { return body.getSize(); }
	sf::Vector2f SetPosition(sf::Vector2f randPos);

	sf::RectangleShape body;

	animationEnemyDeath animationEnemyDeath;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;


	void setDie(bool isDestroy);
	bool isDie() { return isDieBool; }
	bool isDieBool;
};


#include "BossDeath.h"

BossDeath::BossDeath(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float PosX, float PosY)
	:animationEnemyDeath(texture, imageCount, switchTime)
{
	this->isDieBool = false;
	this->speed = speed;

	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(128.0, 128.0));//Old

	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(PosX, PosY);
	body.setTexture(texture);
	body.setScale(2.0f, 2.0f);

}

BossDeath::~BossDeath()
{
}

void BossDeath::Update(float deltaTime)
{
	row = 6;
	animationEnemyDeath.Update(row, deltaTime, faceRight);
	body.setTextureRect(animationEnemyDeath.uvRect);
}

void BossDeath::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Vector2f BossDeath::SetPosition(sf::Vector2f randPos)
{
	body.setPosition(randPos);
	return body.getPosition();
}

void BossDeath::setDie(bool isDie)
{

	this->isDieBool = isDie;

}
#include "Flag.h"

Flag::Flag(sf::Texture* texture, sf::Vector2f position, sf::Vector2f velocity)
{
	//body.setSize(sf::Vector2f(40.f, 28.f));
	body.setSize(sf::Vector2f(128.f, 236.f));//256  472

	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	this->cool = cool;
	this->isDestroyBool = false;
	this->velocity = velocity;
	this->isSpawnBool = false;
	cooling = 10.0f;
}

void Flag::Update(float deltaTime)
{
	velocity.y += 981.0f * deltaTime;

	body.move(velocity * deltaTime);
}

void Flag::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Flag::setSpawn(bool isSpawn)
{
	this->isSpawnBool = isSpawn;
}

void Flag::setDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}

void Flag::OnCollision(sf::Vector2f direction)
{
	//printf("direction y =%f", direction.y);
	//printf("    %s\n", canJump ? "true" : "false");
	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = 0.0f;

	}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;
		//canJump = true;
	}
}

float Flag::cooldown(float deltaTime, int check)
{
	return 0.0f;
}
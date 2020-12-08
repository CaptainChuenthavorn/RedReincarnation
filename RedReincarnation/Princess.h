#pragma once
#include <SFML\Graphics.hpp>
#include "animationPrincess.h"
#include "Collider.h"
#include "Player.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
class Princess
{
public:

	Princess(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float PosX, float PosY);
	~Princess();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OncollisionPrincess(sf::Vector2f direction);
	sf::FloatRect GetGlobalbounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetSize() { return body.getSize(); }
	sf::Vector2f SetPosition(sf::Vector2f randPos);
	Collider GetCollider() { return Collider(body); }
	Collider GetColliderHitbox() { return Collider(hitbox); }
	



public:
	sf::Clock cl;
	float enycl;
	sf::RectangleShape bound;
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	animationPrincess animationPrincess;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2u imageCount;
	sf::Vector2f velocity;

	sf::Clock clockdead;



};
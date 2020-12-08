#include "Princess.h"
#include "enemy.h"


Princess::Princess(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float PosX, float PosY)
	:animationPrincess(texture, imageCount, switchTime)
{
	this->speed = speed;
	
	
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(48.0,60.0));//Old
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(PosX, PosY);
	body.setTexture(texture);
	body.setScale(1.4f, 1.4f);


	
}

Princess::~Princess()
{
}

void Princess::Update(float deltaTime)
{


	//velocity.x *= 0.8f; // 0.2 slow 0.8 fast 
	velocity.y += 981.0f * deltaTime;
	//velocity.x += speed;
	enycl = cl.getElapsedTime().asSeconds();

	//if (enycl <= 3.0f)
	//{
	//	velocity.x += speed * 0.5;
	//}
	//else if (enycl <= 6.0f && enycl >= 3.0f)
	//{
	//	velocity.x = 0;

	//}

	//else if (enycl <= 9.0f && enycl >= 6.0f)
	//{
	//	velocity.x -= speed * 0.5;
	//	enycl = 0.0f;
	//}

	//else {

	//	cl.restart();
	//}

	//if (velocity.x == 0.0f)
	//{
	//	row = 0; // idle
	//	if (imageCount.x >= 5)
	//		imageCount.x = 0;
	//}
	//else {
	//	row = 1;
	//	if (velocity.x > 0.0f)
	//		faceRight = true;
	//	else
	//		faceRight = false;//หันหน้าไปทางซ้าย
	//}
	
	animationPrincess.Update(row, deltaTime, faceRight);
	body.setTextureRect(animationPrincess.uvRect);
	body.move(velocity * deltaTime);//Before : velocity * deltaTime
}

void Princess::Draw(sf::RenderWindow& window)
{
	//window.draw(hitbox);

	window.draw(body);
	
}

void Princess::OncollisionPrincess(sf::Vector2f direction)
{

	//if (direction.x < 0.0f) {
	//	//collision on the left
	//	velocity.x = -velocity.x;
	//	velocity.x = 0.0f;

	//}
	//else if (direction.x > 0.0f) {
	//	//collision on the right
	//	velocity.x = -velocity.x;
	//	velocity.x = 0.0f;

	//}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;

	}
}

sf::Vector2f Princess::SetPosition(sf::Vector2f randPos)
{
	body.setPosition(randPos);
	return body.getPosition();
}


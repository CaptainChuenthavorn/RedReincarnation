#include "enemy.h"


enemy::enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float PosX, float PosY)
	:animationEnemy(texture, imageCount, switchTime)
{
	this->isDieBool = false;
	this->isDieSpawnBool = false;
	this->speed = speed;
	this->hp = 3;

	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(128.0, 128.0));//Old
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(PosX, PosY);
	body.setTexture(texture);
	body.setScale(1.4f, 1.4f);

	bound.setSize(sf::Vector2f(128.0, 128.0));//Old
	bound.setOrigin(body.getSize() / 2.0f);
	bound.setPosition(body.getPosition());
	bound.setTexture(texture);
	bound.setScale(1.4f, 1.4f);


	hitbox.setSize(sf::Vector2f(30.0, 48.0));
	//hitbox.setSize(sf::Vector2f(42.0, 57.6));
	hitbox.setOrigin(hitbox.getSize() / 2.0f);
	hitbox.setPosition(body.getPosition().x, body.getPosition().y);
	hitbox.setFillColor(sf::Color::Yellow);


}

enemy::~enemy()
{
}

void enemy::Update(float deltaTime)
{

	srand(time(NULL));

	hitbox.setPosition(body.getPosition().x, body.getPosition().y);
	animationEnemy.idle = true;
	velocity.x *= 0.8f; // 0.2 slow 0.8 fast 
	velocity.y += 981.0f * deltaTime;
	//velocity.x += speed;
	enycl = cl.getElapsedTime().asSeconds();

	if (enycl <= 3.0f)
	{
		velocity.x += speed * 0.5;
	}
	else if (enycl <= 6.0f && enycl >= 3.0f)
	{
		velocity.x = 0;

	}

	else if (enycl <= 9.0f && enycl >= 6.0f)
	{
		velocity.x -= speed * 0.5;
		enycl = 0.0f;
	}

	else {

		cl.restart();
	}

	if (velocity.x == 0.0f)
	{
		row = 0; // idle
		if (imageCount.x >= 5)
			imageCount.x = 0;
	}
	else {
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;//หันหน้าไปทางซ้าย
	}

	totaltime += deltaTime;
	//hurt
	
		
		if (hurt == true)
		{
			
			velocity.x = 0.0f;
			row = 5;
			animationEnemy.hurt = true;
			hitTime += deltaTime;
			if (hitTime > hitCooldown)
			{
				hitTime = 0;
				hurt = false;
			}
		}
	



	animationEnemy.Update(row, deltaTime, faceRight);
	body.setTextureRect(animationEnemy.uvRect);
	body.move(velocity * deltaTime);//Before : velocity * deltaTime
	//hurt bound
	bound.setTextureRect(animationEnemy.uvRect);
	bound.setPosition(body.getPosition());//Before : velocity * deltaTime
}

void enemy::Draw(sf::RenderWindow& window)
{
	//window.draw(hitbox);

	window.draw(body);
	window.draw(bound);
}

void enemy::OncollisionEnemy(sf::Vector2f direction)
{

	if (direction.x < 0.0f) {
		//collision on the left
		velocity.x = -velocity.x;
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f) {
		//collision on the right
		velocity.x = -velocity.x;
		velocity.x = 0.0f;

	}
	if (direction.y <= 0.0f) {
		//collision on the bottom

		velocity.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//collision on the top
		velocity.y = 0.0f;

	}
}

sf::Vector2f enemy::SetPosition(sf::Vector2f randPos)
{
	body.setPosition(randPos);
	return body.getPosition();
}

sf::Vector2f enemy::SetPositionBounce(float moveX)
{
	body.setPosition(body.getPosition().x + moveX, body.getPosition().y);
	return body.getPosition();
}

void enemy::setHp(int dmg)
{
	this->hp -= dmg;
}



void enemy::setDie(bool isDie)
{
	this->isDieBool = isDie;
}

void enemy::setDieSpawn(bool isDieSpawn)
{
	this->isDieSpawnBool = isDieSpawn;
}
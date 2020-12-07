#include "animationEnemyDeath.h"
animationEnemyDeath::animationEnemyDeath(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;//at row Frame 
	uvRect.width = texture->getSize().x / float(imageCount.x);//widyth of sprite
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

animationEnemyDeath::~animationEnemyDeath()
{
}

void animationEnemyDeath::Update(int row, float deltaTime, bool faceRight)
{
	if (play == true)
	{
		currentImage.y = row;
		totalTime += deltaTime;

		if (totalTime >= switchTime) { // for smooth frame
			totalTime -= switchTime;
			currentImage.x++;
			if (currentImage.x >= 6) {
				currentImage.x = 6;
			}
		}

		uvRect.top = currentImage.y * uvRect.height;
		if (faceRight) {
			uvRect.left = currentImage.x * uvRect.width;
			uvRect.width = abs(uvRect.width);
		}
		else {
			uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
			uvRect.width = -abs(uvRect.width);
		}
	}

}
#pragma once
#include <SFML\Graphics.hpp>
class animationPrincess
{

public:
	animationPrincess(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~animationPrincess();
	void Update(int row, float deltaTime, bool faceRight);
	sf::IntRect uvRect;

public:

	bool play = false;
	//enemy movement

	sf::Clock cl;
	float anicl;

	sf::Vector2u currentImage;
	sf::Vector2u imageCount;

	float totalTime;
	float switchTime;
private:

};
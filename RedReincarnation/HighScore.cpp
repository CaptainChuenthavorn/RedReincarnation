#include "HighScore.h"

HighScore::HighScore(unsigned long long score, std::string name)
{
		this->score = score;
		this->name = name;
}

HighScore::~HighScore()
{
}

unsigned long long HighScore::getScore()
{
	
		return this->score;
	
}

std::string HighScore::getName()
{
	return this->name;
}

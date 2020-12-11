#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
class HighScore
{
private:
	unsigned long long score;
	std::string name;
public:
	//Constructor
	HighScore(unsigned long long score, std::string name);
	
	~HighScore();

	//Accessor
	unsigned long long getScore();

	std::string getName();
	

	bool operator <(HighScore a)
	{
		return (!(this->score < a.getScore()));
	}

};

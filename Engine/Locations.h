#pragma once

using namespace std;

class Location
{
public:
	
	bool operator<(const Location& OoL)
	{
		return x < OoL.x && y < OoL.y;
	}

	bool operator>(const Location& OoL) // OoL -> Operation on Location
	{
		return x > OoL.x && y > OoL.y;
	}


	int x;
	int y;
	int width;
	int height;
};
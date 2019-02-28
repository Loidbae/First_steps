#pragma once

using namespace std;

class Coordinates
{
public:
	
	Coordinates() = default;

	bool operator<(const Coordinates& OoL)
	{
		return x < OoL.x && y < OoL.y;
	}

	bool operator>(const Coordinates& OoL) // OoL -> Operation on Location
	{
		return x > OoL.x && y > OoL.y;
	}


	float x;
	float y;
	float h;
	float w;
	float v;
};
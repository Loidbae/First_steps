#pragma once

using namespace std;

class Coordinates
{
public:
	
	bool operator<(const Coordinates& OoL)
	{
		return X < OoL.X && Y < OoL.Y;
	}

	bool operator>(const Coordinates& OoL) // OoL -> Operation on Location
	{
		return X > OoL.X && Y > OoL.Y;
	}


	float X;
	float Y;
	float Sp;
	float Width;
	float Height;
};
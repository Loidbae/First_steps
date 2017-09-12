#pragma once
class Location
{
public:


	bool operator<(const Location& OpL)
	{
		return x < OpL.x && y < OpL.y;
	}
	
	bool operator>(const Location& OpL) // OpL -> Operation on Location
	{
		return x > OpL.x && y > OpL.y;
	}


	int x;
	int y;
};
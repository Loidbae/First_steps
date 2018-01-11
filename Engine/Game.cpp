/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 *****************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& Wnd)
	:
	_Wnd(Wnd),
	_Gfx(Wnd),
	_Rng(_Rd())
	
{
	for (int i = 0; i < Dex; i++)
	{
		_Platform[i].InitBoxes(_Rng);
	}
}

void Game::Go()
{
	_Gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	_Gfx.EndFrame();
}



void Game::UpdateModel()
{	//Note to myself, collsion calculation always AFTER Objectmovement.
	const float Dt = _Ft.Mark();

	_Character.move(_Wnd.kbd);

	for (int i = 0; i < Dex; i++)
	{
		_Platform[i].checksection(_Character);
		_Platform[i].updateboxcol(_Character);
	}
	_Character.wndborder();
	
}

void Game::ComposeFrame()
{
	_Character.draw(_Gfx);

	for (int i = 0; i < Dex; i++)
	{
		_Platform[i].drawbox(_Gfx);
		_Platform[i].checkinboxvisualtest(_Gfx, _Character);
	}
	
} 

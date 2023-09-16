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
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 300.0f), Vec2(200.0f, 200.0f)),
	Walls(0.0f, 0.0f, float(gfx.ScreenWidth), float(gfx.ScreenHeight)),
	soundBallCollition(L"Sounds\\arkpad.wav"),
	brick(Rect(50.0f, 50.0f, 200.0f, 100.0f), Colors::Cyan),
	paddle(Vec2(400.0f,400.0f),200.0f,50.0f,7.0f,Colors::Green)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.mark();
	ball.update(dt);
	paddle.update(wnd.kbd,dt);

	if (paddle.detectBallCollition(ball)) {
		soundBallCollition.Play();
	}
	paddle.detectWallCollition(Walls);
	
	if (brick.detectBallCollition(ball)) {
		soundBallCollition.Play();
	}
	if (ball.detectWallCollition(Walls)) {
		soundBallCollition.Play();
	}
	
	
}

void Game::ComposeFrame()
{
	ball.draw(gfx);
	brick.draw(gfx);
	paddle.draw(gfx);
	
}

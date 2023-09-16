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
	paddle(Vec2(400.0f,400.0f),200.0f,50.0f,7.0f,Colors::Green)
{
	Vec2 startingGridPoint(0.0f, 0.0f);
	Vec2 brickDimension(40.0f, 20.0f);

	Color colors[6] = { Colors::Blue,Colors::Cyan, Colors::Magenta, Colors::Red,Colors::Gray,Colors::Yellow};

	for (int i = 0; i < numBricksRow; i++) {
		for (int y = 0; y < numBricksColumn; y++) {
			bricks[i][y] = Brick(Rect(startingGridPoint.x,startingGridPoint.y,
				startingGridPoint.x + brickDimension.x, startingGridPoint.y + brickDimension.y),
				colors[i]);
			startingGridPoint.x += brickDimension.x;
			
		}
		
		startingGridPoint.x = 0.0f;
		startingGridPoint.y += brickDimension.y;
	}

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

	for (int row1 = 0; row1 < numBricksRow; row1++) {
		for (int col1 = 0; col1 < numBricksColumn; col1++) {
			if (bricks[row1][col1].detectBallCollition(ball)) {
				soundBallCollition.Play();
			}

		}

	}
	

	if (paddle.detectBallCollition(ball)) {
		soundBallCollition.Play();
	}
	paddle.detectWallCollition(Walls);
	
	
	if (ball.detectWallCollition(Walls)) {
		soundBallCollition.Play();
	}
	
	
}

void Game::ComposeFrame()
{
	
	ball.draw(gfx);
	paddle.draw(gfx);
	for (int row = 0; row < numBricksRow; row++) {
		for (int col = 0; col < numBricksColumn; col++) {
			bricks[row][col].draw(gfx);
			
		}

	}
	
}

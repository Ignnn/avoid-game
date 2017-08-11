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
#include "Graphics.h"
#include <cmath>
#include <random>
#include "Surroundings.h"
#include "triag.h"
#include "rect.h"
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	sp(2, 4),
	xDist(50,750),
	c1(50, 255),
	c2(50, 255),
	c3(50, 255)

	{
		for (int j = 0; j < n; j++)
		{
			ractang[j].Init(xDist(rng), sp(rng),c1(rng),c2(rng),c3(rng));
		}

start = false;
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
		if (start) {

			for (int j = 0; j < n; j++)
			{
				ractang[j].RectExist();
				ractang[j].Update();
			}

			if (!triang.GetTouched())
			{
				for (int j = 0; j < n; j++)
				{
					ractang[j].Collision(triang);
				}
				triang.Update(wnd.kbd);
			}

			// Atstatomas trikampis, jei paspaudžiama "R"
			triang.Restart(wnd.kbd);
		}

		// Svarbu praleisti pirmąją iteraciją, nes pirmiausia turėtų būti nupiešiamos figūros (piešimo metu fiksuojamos pirmosios koordinatės),
		start = true;
	}

	void Game::ComposeFrame()
	{
		for (int j = 0; j < n; j++)
		{
			ractang[j].draw_rect(gfx);
		}

		if (!triang.GetTouched())
		{
			triang.draw_triang(gfx);
		}

		Surroundings(gfx);
	}
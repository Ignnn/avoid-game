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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{

	for (int j = 0; j < n; j++)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> xDist(50, 750);

		ractang[j].center_x = ractang[j].size / 2;
		ractang[j].center_y = ractang[j].size / 2;
		ractang[j].y_in = 50;
		ractang[j].x_in = xDist(rng);
		std::uniform_int_distribution<int> c1(50, 255);
		std::uniform_int_distribution<int> c2(50, 255);
		std::uniform_int_distribution<int> c3(50, 255);
		ractang[j].color[0] = c1(rng);
		ractang[j].color[1] = c2(rng);
		ractang[j].color[2] = c3(rng);
		ii[j] = 0;


		std::uniform_int_distribution<int> sp(2, 4);
		ractang[j].speedcoef = sp(rng);

	}

	triang.y_in = 500- triang.size;
	triang.x_in = 400 - (triang.size / 2);
	triang.color[0] = 255;
	triang.color[1] = 255;
	triang.color[2] = 255;
	array_s_ractang  = sizeof(ractang[0].area) / sizeof(*ractang[0].area);
	array_s_triag = sizeof(triang.area) / sizeof(*triang.area);
	touch = false;

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

}

void Game::ComposeFrame()
{
	

	for (int j = 0; j < n; j++)
	{

		if (ii[j] == 0)
		{
			ractang[j].draw_rect(gfx);
		}


		if (!ractang[j].exist)
		{

			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> c1(50, 255);
			std::uniform_int_distribution<int> c2(50, 255);
			std::uniform_int_distribution<int> c3(50, 255);
			
		
			std::uniform_int_distribution<int> degree(50, 255);

			ractang[j].color[0] = c1(rng);
			ractang[j].color[1] = c2(rng);
			ractang[j].color[2] = c3(rng);
			ractang[j].exist = true;
			std::uniform_int_distribution<int> xDist(45, 745);
			ractang[j].x_in = xDist(rng);
			ractang[j].y_in = 20;
			ractang[j].draw_rect(gfx);
			std::uniform_int_distribution<int> sp(2, 4);
			ractang[j].speedcoef = sp(rng);

		}


		if (ractang[j].exist)
		{
			ractang[j].y_in += ractang[j].speedcoef;
			//ractang[j].y_in += 10;
			ractang[j].angle += 0.01*ractang[j].speedcoef;

			if (ractang[j].y_in > 530)
			{
				ractang[j].exist = false;
			}
		}

	}





	// APLINKA

	for (int i = 0; i < 800; ++i)
	{
		for (int j = 0; j < 50; j++)
		{
			gfx.PutPixel(i, j, 0, 0, 0);
		}
	}


	for (int i=0; i < 800; ++i)
	{
		for (int j = 500; j < 600;j++)
		{
			gfx.PutPixel(i, j, 0, 0, 0);
		}
}


	for (int i = 100; i < 700; ++i)
	{
		for (int j = 500; j < 502; j++)
		{
			gfx.PutPixel(i, j, 255, 0, 0);
		}
	}

	

	if (!touch)
	{

		bool xt;
		bool yt;

		for (int j = 0; j < n; j++)
		{
			// Tikrinama ar trikampio pirma koordinatė su kažkuom sutampa
			for (int jj = 0; jj < array_s_triag; jj++)
			{
				for (int jjj = 0; jjj < array_s_ractang; jjj++)
				{
					xt = ractang[j].area[jjj][0] == triang.area[jj][0];
					yt = ractang[j].area[jjj][1] == triang.area[jj][1];
					touch = touch || (xt && yt);
				}

			}

		}

		/*
		for (int j = 0; j < n; j++)
		{
			x_t = triang.x_in - (triang.size/2) > ractang[j].x_in && triang.x_in + (triang.size / 2) < ractang[j].x_in + ractang[j].size;
			y_t = triang.y_in < ractang[j].y_in && triang.y_in > ractang[j].y_in - ractang[j].size;
			touch = touch || (x_t && y_t);
		}*/



		triang.draw_triang(gfx);


		if (triang.x_in < 695) {
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				triang.x_in += 5;
			}
		}

		if (triang.x_in > 100) {
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				triang.x_in -= 5;
			}
		}


	}




	if (wnd.kbd.KeyIsPressed('R'))
	{
		touch = false;
	}









}
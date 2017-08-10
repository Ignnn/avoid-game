#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class triag
{
public:

	void draw_triang(Graphics& gfx);
	void Update(Keyboard& kbd);
	void Restart(Keyboard& kbd);

	static const int size = 15;
	double angle = 0;
	double center_x = size / 2;
	double center_y = size / 2;
	int area[size*size][2];
	bool kryptis = true;
	bool exist = true;
	int color[3] = { 255,255,255 };
	int speedcoef = 5;
	bool touched = false;

	double y_in = 500 - size;
	double x_in = 400 - (size / 2);


};
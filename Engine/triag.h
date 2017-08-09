#pragma once

#include "Graphics.h"

class triag
{
public:
	void draw_triang(Graphics& gfx);

	static const int size = 15;
	double x_in = 300;
	double y_in = 300;
	double angle = 0;
	double center_x = size / 2;
	double center_y = size / 2;
	int area[size*size][2];
	bool kryptis = true;
	bool exist = true;
	int color[3] = { 0,255,255 };
	int speedcoef = 5;
	bool touched = false;

};
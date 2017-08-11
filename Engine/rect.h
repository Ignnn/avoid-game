#pragma once

#include "Graphics.h"
#include "triag.h"
class rect
{
public:

// Functions
	void Init(double x, int speedcoef_in, int c1, int c2, int c3);
	void Update();
	void RectExist();
	void Collision(triag& triang);
	void draw_rect(Graphics& gfx);
	

private:	
	int speedcoef = 5;
	double x_in;
	double angle = 0;
	bool exist = true;
	static const int size = 35;
	int area[size*size][2];
	double y_in = 50;
	double center_x = size / 2;
	double center_y = size / 2;
	int color[3];
};
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
	static const int size = 20;
	float area[(size - 1) * 4][2] = { 0 }; // Fiksuojami tik kvadrato �oniniai ta�kai. Svarbu inicijuoti kaip 0.
	float y_in = 50;
	float center_x = size / 2;
	float center_y = size / 2;
	int color[3];
};
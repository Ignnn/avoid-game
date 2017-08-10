#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class triag
{
public:

	void draw_triang(Graphics& gfx);
	void Update(Keyboard& kbd);
	void Restart(Keyboard& kbd);
	
	bool GetTouched() const ;
	void SetTouched(bool x);

	static const int size = 15;
	int area[size*size][2];

private:
	double y_in = 500 - size;
	double x_in = 400 - (size / 2);
	double angle = 0;
	double center_x = size / 2;
	double center_y = size / 2;
	int color[3] = { 255,255,255 };
	int speedcoef = 5;
	bool touched = false;	
};
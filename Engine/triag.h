#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class triag
{
public:

	void draw_triang(Graphics& gfx);
	
	//Control functions
	void Update(Keyboard& kbd);
	void Restart(Keyboard& kbd);
	//


	// Setter and getter
	bool GetTouched() const ;
	void SetTouched(bool x);
	//

	typedef int (*int_arrays)[2];
	int_arrays GetArea(){return area;};

private:
	static const int size = 15;
	//int area[size*size][2] = { 0 };
	int area[1+ size-2+size-2-1+size*2][2] = { 0 };
	double y_in = 500 - size;
	double x_in = 400 - (size / 2);
	double angle = 0;
	float center_x = size / 2;
	float center_y = size / 2;
	int color[3] = { 255,255,255 };
	int speedcoef = 5;
	bool touched = false;	
};
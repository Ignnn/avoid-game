#include "triag.h"
#include "rect.h"
#include <cmath>

void triag::draw_triang(Graphics & gfx)
{

	double j;
	double x;
	double y;
	double xp;
	double yp;
	double c_poss;
	double radius;
	int index = 0;


	for (int i = 0; i < size; i++)
	{

		// i tai aukstis
	

		j = i; 
		y = i + y_in; // nupiešiama pirmoji virš?n?s koordinat?

		for (int jj = -1 * j; jj <= j; jj++)
		{

			x = jj + x_in;

			radius = std::sqrt(
				((x_in + center_x - x) * 	(x_in + center_x - x)) +
				((y_in + center_y - y) * 	(y_in + center_y - y))
			);

			c_poss = atan2(y - (center_y + y_in), x - (center_x + x_in));
			xp = (cos(c_poss + angle) * radius) + x_in + center_x + size;
			yp = (sin(c_poss + angle) * radius) + y_in + center_y;


			gfx.PutPixel(xp, yp, color[0], color[1], color[2]);
		/*
		area[index][0] = xp;
			area[index][1] = yp;
			
			index++;
		*/
			
			// Šiomis IF sąlygomis užtikrinama, kad būtų fiksuojamos tik kvadrato kraštinių taškų koordinatės.
		
			if ((i == 0) || (i == size-1))
			{
				// Fiksuojamos visos koordinatės (viršus ir apačia)
				area[index][0] = xp;
				area[index][1] = yp;
				index++;
			}
			else if ((jj == -1 * j) || (jj == 1 * j))
			{
				// Fiksuojamos 2 koordinatės (šoniniai taškai)
				area[index][0] = xp;
				area[index][1] = yp;
				index++;
			}
			
			/* AKIŲ PIEŠIMAS*/

			if ((i == size / 3) || (i == size / 2))
			{
				if (((jj >= -size / 2) && (jj < 0)) || (jj <= size / 2) && (jj > 0))
				{
					gfx.PutPixel(xp, yp, 255, 0, 0);
				}	
			}
			else if ((i > (size / 4)) && (i < size / 2))
			{
				if ((jj == (-1*size / 2)) || (jj == (size / 2)) || (jj == 0))
				{
					gfx.PutPixel(xp, yp, 255, 0, 0);
				}
			}			
		}
	}
}

void triag::Update(Keyboard& kbd)
{
		if (x_in < 695) {
			if (kbd.KeyIsPressed(VK_RIGHT))
			{
				x_in += 5;
			}
		}

		if (x_in > 100) {
			if (kbd.KeyIsPressed(VK_LEFT))
			{
				x_in -= 5;
			}
		}
}

void triag::Restart(Keyboard & kbd)
{
	if (kbd.KeyIsPressed('R'))
	{
		touched = false;
	}
}




bool triag::GetTouched() const
{
	return touched;
}

void triag::SetTouched(bool x)
{
	touched = x;
}























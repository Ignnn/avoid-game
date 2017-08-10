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

		j = i;
		y = i + y_in; // nupie�iama pirmoji vir�?n?s koordinat?

		for (int jj = -1 * j; jj <= j; jj++)
		{

			x = jj + x_in;

			radius = std::sqrt(
				((x_in + center_x - x) * 	(x_in + center_x - x)) +
				((y_in + center_y - y) * 	(y_in + center_y - y))
			);



			//c_poss = atan2((center_x + x_in) - x, (center_y + y_in) - y); //originalus
			c_poss = atan2(y - (center_y + y_in), x - (center_x + x_in));
			xp = (cos(c_poss + angle) * radius) + x_in + center_x + size;
			yp = (sin(c_poss + angle) * radius) + y_in + center_y;

			area[index][0] = xp;
			area[index][1] = yp;

			index++;

			gfx.PutPixel(xp, yp, color[0], color[1], color[2]);

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













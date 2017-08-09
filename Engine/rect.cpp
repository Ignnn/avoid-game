
#include "Graphics.h"
#include <cmath>
#include "rect.h"



	void rect::draw_rect(Graphics& gfx)
	{
		double c_poss;
		double radius;
		double x;
		double y;
		int index = 0;

		for (int j = 0; j <= (size)-1; ++j)
		{
			for (int i = 0; i <= (size)-1; ++i)
			{
				x = i + x_in;
				y = j + y_in;

				radius = std::sqrt(
					((x_in + center_x - x) * 	(x_in + (center_x)-x)) +
					((y_in + center_y - y) * 	(y_in + (center_y)-y))
				);
				c_poss = atan2((center_x + x_in) - x, (center_y + y_in) - y);

				x = (sin(c_poss + angle) * radius) + x_in + center_x;
				y = (cos(c_poss + angle) * radius) + y_in + center_y;

				area[index][0] = x;
				area[index][1] = y;

				index++;

				gfx.PutPixel(x, y, color[0], color[1], color[2]);
			}
		}



}

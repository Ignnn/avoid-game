
#include "Graphics.h"
#include <cmath>
#include "rect.h"
#include "triag.h"
#include <random>


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

void rect::RectExist()
{
	if (!exist)
	{

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> c1(50, 255);
		std::uniform_int_distribution<int> c2(50, 255);
		std::uniform_int_distribution<int> c3(50, 255);


		std::uniform_int_distribution<int> degree(50, 255);

		color[0] = c1(rng);
		color[1] = c2(rng);
		color[2] = c3(rng);
		exist = true;
		std::uniform_int_distribution<int> xDist(45, 745);
		x_in = xDist(rng);
		y_in = 20;
		std::uniform_int_distribution<int> sp(2, 4);
		speedcoef = sp(rng);
	}
}

void rect::Update()
{
	if (exist)
	{
		y_in += speedcoef;
		angle += 0.01*speedcoef;

		if (y_in > 530)
		{
			exist = false;
		}
	}


}



void rect::Collision(triag& triang)
{

	int array_s_ractang;
	int array_s_triag;
	int xt;
	int yt;

	array_s_ractang = sizeof(area) / sizeof(*area);
	array_s_triag = sizeof(triang.GetArea()) / sizeof(*triang.GetArea());

	for (int jj = 0; jj < array_s_triag; jj++)
	{
		for (int jjj = 0; jjj < array_s_ractang; jjj++)
		{
			xt = area[jjj][0] == triang.GetArea()[jj][0];
			yt = area[jjj][1] == triang.GetArea()[jj][1];
			triang.SetTouched(triang.GetTouched() || (xt && yt));
		}
	}
}

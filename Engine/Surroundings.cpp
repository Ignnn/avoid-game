
#include "Surroundings.h"
#include "Graphics.h"

void Surroundings(Graphics& gfx)
{



	// Upper black rectangle is drawn
	for (int i = 0; i < 800; ++i)
	{
		for (int j = 0; j < 50; j++)
		{
			gfx.PutPixel(i, j, 0, 0, 0);
		}
	}

	// Lower black rectangle is drawn
	for (int i = 0; i < 800; ++i)
	{
		for (int j = 500; j < 600; j++)
		{
			gfx.PutPixel(i, j, 0, 0, 0);
		}
	}


	// Red base line is drawn
	for (int i = 100; i < 700; ++i)
	{
		for (int j = 500; j < 502; j++)
		{
			gfx.PutPixel(i, j, 255, 0, 0);
		}
	}

}

#include <stdio.h>
#include "keyBtn.h"


int getKey()
{
	int key = getch();

	if (key == 224)
	{
		int n = getch();
		switch (n)
		{
			case UP :
				return UP;
			break;

			case DOWN :
				return DOWN;
			break;

			case LEFT :
				return LEFT;
			break;

			case RIGHT :
				return RIGHT;
			break;

			case ENTER :
				return ENTER;
			break;

		}
	}
}
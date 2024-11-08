#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"
#include "keyBtn.h"
#include "Menu.h"








void GoToStd()
{
	int select = 1;
	
	drawingStdMenu(select);// 메뉴 띄우기
	
	
	while (1)
	{
		int key = getKey();

		switch (key)
		{
			case UP:
				if (select <= 1)
				{
					select = 1;
				}
				else
				{
					select--;
				}
				break;

			case DOWN:
				if (select >= MAX_MENU)
				{
					select = MAX_MENU;
				}

				else
				{
					select++;
				}
				break;

			case ENTER:
			{
				selectStdMenu(&select);
			}
			return;

		}

		drawingStdMenu(select);

	}


}







void GoToPro()
{
	int select = 1;

	drawingProMenu(select);


	while (1)
	{
		int key = getKey();

		switch (key)
		{
			case UP:
				if (select <= 1)
				{
					select = 1;
				}
				else
				{
					select--;
				}
				break;

			case DOWN:
				if (select >= MAX_MENU)
				{
					select = MAX_MENU;
				}

				else
				{
					select++;
				}
				break;

			case ENTER:
			{
				selectProMenu(&select);
			}
			return;

		}

		drawingProMenu(select);

	}
}


void GoToMajo()
{
	int select = 1;

	drawingMajoMenu(select);


	while (1)
	{
		int key = getKey();

		switch (key)
		{
		case UP:
			if (select <= 1)
			{
				select = 1;
			}
			else
			{
				select--;
			}
			break;

		case DOWN:
			if (select >= MAX_MENU)
			{
				select = MAX_MENU;
			}

			else
			{
				select++;
			}
			break;

		case ENTER:
		{
			selectMajoMenu(&select);
		}
		return;

		}

		drawingMajoMenu(select);

	}
}



void GoToLect()
{
	int select = 1;

	drawingLectMenu(select);


	while (1)
	{
		int key = getKey();

		switch (key)
		{
		case UP:
			if (select <= 1)
			{
				select = 1;
			}
			else
			{
				select--;
			}
			break;

		case DOWN:
			if (select >= MAX_MENU)
			{
				select = MAX_MENU;
			}

			else
			{
				select++;
			}
			break;

		case ENTER:
		{
			selectLectMenu(&select);
		}
		return;

		}

		drawingLectMenu(select);

	}
}





void mainMenu()
{
	int select = 1;
	fontColor(LIGHT_GREEN);
	

	drawingMainMenu(select);
	

	while (1)
	{
		
		int key = getKey();
		switch (key)
		{
			case UP:
				if (select <= 1)
				{
					select = 1;
				}
				else
				{
					select--;
					
				}

				break;

			case DOWN:
				if (select >= MAX_MENU_MAIN)
				{
					select = MAX_MENU_MAIN;
				}
				else
				{
					select++;
					
				}
				break;


			case ENTER:
				selectMenu(&select);
			break;
		}
		
		if (select == 9)
		{
			return;
		}
		drawingMainMenu(select);//메뉴를 다시 출력
	}

}
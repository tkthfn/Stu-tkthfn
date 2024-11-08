#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"



int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	DrawingFristScreen(LIGHT_CYAN); // 첫화면 출력

	printf("\n");
	system("pause");//첫화면 출력하고 키 누르때 까지 첫화면 표시
	system("cls");

	mainMenu();

}





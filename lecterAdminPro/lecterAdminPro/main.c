#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"



int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	DrawingFristScreen(LIGHT_CYAN); // ùȭ�� ���

	printf("\n");
	system("pause");//ùȭ�� ����ϰ� Ű ������ ���� ùȭ�� ǥ��
	system("cls");

	mainMenu();

}





#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"

void DrawingCaption(int x, int y)
{
	printf("����������������������������������������������");
	GotoXY(x, y + 1);
	printf("��                                                                                      ��");
	GotoXY(x, y + 2);
	printf("��                                                                                      ��");
	GotoXY(x, y + 3);
	printf("��                                                                                      ��");
	GotoXY(x, y + 4);
	printf("��                                                                                      ��");
	GotoXY(x, y + 5);
	printf("��                                                                                      ��");
	GotoXY(x, y + 6);
	printf("��                                                                                      ��");
	GotoXY(x, y + 7);
	printf("��                                                                                      ��");
	GotoXY(x, y + 8);
	printf("��                                                                                      ��");
	GotoXY(x, y + 9);
	printf("��                                                                                      ��");
	GotoXY(x, y + 10);
	printf("��                                                                                      ��");
	GotoXY(x, y + 11);
	printf("��                                                                                      ��");
	GotoXY(x, y + 12);
	printf("��                                                                                      ��");
	GotoXY(x, y + 13);
	printf("��                                                                                      ��");
	GotoXY(x, y + 14);
	printf("����������������������������������������������\n");

	GotoXY(x + 35, y + 5);
	printf("����Ʈ �л� ���� V 2.5");
	GotoXY(x + 35, y + 7);
	printf("��¥ : 2024�� 11�� 6��");
	GotoXY(x + 28, y + 9);
	printf("��  �� : �� �� ��, �� �� ��, �� �� ��");
}



void fontColor(FONT_COLOR color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void DrawingFristScreen(FONT_COLOR color)
{
	int x = 70;
	int y = 12;
	
	fontColor(LIGHT_CYAN); //�۾��� ����
	
	GotoXY(70, y + 0);
	DrawingCaption(x, y); //���� �׸���
	
	GotoXY(x, y + 17);//Ŀ�� ����
	printf("�ءء� ���� �ءء�");

	GotoXY(x, y + 19);
	printf("�л������޴� : �л������� �����ϴ� �޴��Դϴ�.");

	GotoXY(x, y + 21);
	printf("�л������޴� : �л������� �����ϴ� �޴��� �̵��մϴ�.");
	GotoXY(x, y + 23);
	printf("������������ : ���� ������ �����ϴ� �޴��� �̵��մϴ�.");
	GotoXY(x, y + 25);
	printf("����������� : ���� ������ �����ϴ� �޴��� �̵��մϴ�.");
	GotoXY(x, y + 27);
	printf("���������Է� : ���������� �����ϴ� �޴��� �̵��մϴ�.");
	
	GotoXY(x, y + 33);
	printf("�޴��� �̵� �Ͻ÷��� �ƹ�Ű�� �����ʽÿ�.");
	
}



void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//Ŀ������
}
#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"

void DrawingCaption(int x, int y)
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	GotoXY(x, y + 1);
	printf("■                                                                                      ■");
	GotoXY(x, y + 2);
	printf("■                                                                                      ■");
	GotoXY(x, y + 3);
	printf("■                                                                                      ■");
	GotoXY(x, y + 4);
	printf("■                                                                                      ■");
	GotoXY(x, y + 5);
	printf("■                                                                                      ■");
	GotoXY(x, y + 6);
	printf("■                                                                                      ■");
	GotoXY(x, y + 7);
	printf("■                                                                                      ■");
	GotoXY(x, y + 8);
	printf("■                                                                                      ■");
	GotoXY(x, y + 9);
	printf("■                                                                                      ■");
	GotoXY(x, y + 10);
	printf("■                                                                                      ■");
	GotoXY(x, y + 11);
	printf("■                                                                                      ■");
	GotoXY(x, y + 12);
	printf("■                                                                                      ■");
	GotoXY(x, y + 13);
	printf("■                                                                                      ■");
	GotoXY(x, y + 14);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

	GotoXY(x + 35, y + 5);
	printf("스마트 학사 관리 V 2.5");
	GotoXY(x + 35, y + 7);
	printf("날짜 : 2024년 11월 6일");
	GotoXY(x + 28, y + 9);
	printf("작  성 : 조 승 현, 전 도 현, 이 진 영");
}



void fontColor(FONT_COLOR color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void DrawingFristScreen(FONT_COLOR color)
{
	int x = 70;
	int y = 12;
	
	fontColor(LIGHT_CYAN); //글씨색 변경
	
	GotoXY(70, y + 0);
	DrawingCaption(x, y); //제목 그리기
	
	GotoXY(x, y + 17);//커서 지정
	printf("※※※ 도움말 ※※※");

	GotoXY(x, y + 19);
	printf("학생관리메뉴 : 학생정보를 관리하는 메뉴입니다.");

	GotoXY(x, y + 21);
	printf("학생관리메뉴 : 학생정보를 관리하는 메뉴로 이동합니다.");
	GotoXY(x, y + 23);
	printf("교수정보관리 : 교수 정보를 관리하는 메뉴로 이동합니다.");
	GotoXY(x, y + 25);
	printf("전공과목관리 : 전공 과목을 관리하는 메뉴로 이동합니다.");
	GotoXY(x, y + 27);
	printf("수강정보입력 : 수강정보를 관리하는 메뉴로 이동합니다.");
	
	GotoXY(x, y + 33);
	printf("메뉴로 이동 하시려면 아무키나 누르십시오.");
	
}



void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//커서변경
}
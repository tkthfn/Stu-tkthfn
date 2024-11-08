#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"
#include "keyBtn.h"
#include "Menu.h"




void drawingMainMenu(int select)
{
	
	system("cls");
	
	printf("==========================================\n");
	printf("메뉴를 선택하여 주십시오\n");
	printf("==========================================\n");


	printf("\n");
	paintMenu(select);

	printf("\n");
	printf("==========================================\n");
}





void drawingStdMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("학생 관리 메뉴\n");
	printf("==========================================\n");


	printf("메뉴를 선택하여 주십시오\n");

	paintStdMenu(select);

	printf("==========================================\n");

	printf("\n");
}


void drawingProMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("교수 관리 메뉴\n");
	printf("==========================================\n");


	printf("메뉴를 선택하여 주십시오\n");

	paintProMenu(select);

	printf("==========================================\n");

	printf("\n");
}

void drawingMajoMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("전공과목 관리 메뉴\n");
	printf("==========================================\n");


	printf("메뉴를 선택하여 주십시오\n");

	paintMajoMenu(select);

	printf("==========================================\n");

	printf("\n");
}


void drawingLectMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("수강정보 관리 메뉴\n");
	printf("==========================================\n");


	printf("메뉴를 선택하여 주십시오\n");

	paintLectMenu(select);

	printf("==========================================\n");

	printf("\n");
}













void paintMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. 학생관리 메뉴\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("1. 학생관리 메뉴\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. 교수관리 메뉴\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("2. 교수관리 메뉴\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. 전공과목 메뉴\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("3. 전공과목 메뉴\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. 수강정보 메뉴\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("4. 수강정보 메뉴\n");
	}


	if (select == 5)
	{
		fontColor(240);
		printf("5. 프로그램 종료\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("5. 프로그램 종료\n");
	}

}


void paintStdMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. 학생 추가\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. 학생 추가\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. 학생 조회\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. 학생 조회\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. 학생 수정\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. 학생 수정\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. 학생 삭제\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. 학생 삭제\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. 학생 검색\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. 학생 검색\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("뒤로 가기\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("뒤로 가기\n");
	}


}


void paintProMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. 교수 추가\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. 교수 추가\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. 교수 조회\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. 교수 조회\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. 교수 수정\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. 교수 수정\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. 교수 삭제\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. 교수 삭제\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. 교수 검색\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. 교수 검색\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("뒤로 가기\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("뒤로 가기\n");
	}



}



void paintMajoMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. 전공 추가\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. 전공 추가\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. 전공 조회\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. 전공 조회\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. 전공 수정\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. 전공 수정\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. 전공 삭제\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. 전공 삭제\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. 전공 검색\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. 전공 검색\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("뒤로 가기\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("뒤로 가기\n");
	}

}


void paintLectMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. 수강 정보 추가\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. 수강 정보 추가\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. 수강 정보 조회\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. 수강 정보 조회\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. 수강 정보 수정\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. 수강 정보 수정\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. 수강 정보 삭제\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. 수강 정보 삭제\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. 수강 정보 검색\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. 수강 정보 검색\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("뒤로 가기\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("뒤로 가기\n");
	}

}

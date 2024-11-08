#include "def.h"
#include <stdio.h>
#include <windows.h>
#include "cui.h"
#include "keyBtn.h"
#include "Menu.h"


void selectStdMenu(int* select)
{

	switch (*select)
	{
	case ST_ADD:
		AddStd();
		break;

	case ST_READ:
		ReadStd();
		break;

	case ST_EDIT:
		UpdateStd();
		break;

	case ST_DEL:
		DelStd();
		break;

	case ST_SEARCH:
		SearchStd();
		break;

	case BACK :
		return;
		break;


	}
	system("pause");
}


void selectProMenu(int* select)
{

	switch (*select)
	{
	case PRO_ADD:
		AddPro();
		break;

	case PRO_READ:
		ReadPro();
		break;

	case PRO_EDIT:
		UpdatePro();
		break;

	case PRO_DEL:
		DelPro();
		break;

	case PRO_SEARCH:
		SearchPro();
		break;

	case BACK:
		return;
	}
	system("pause");
}

void selectMajoMenu(int* select)
{

	switch (*select)
	{
	case MAJO_ADD:
		AddMaj();
		break;

	case MAJO_READ:
		ReadMaj();
		break;

	case MAJO_EDIT:
		UpdateMaj();
		break;

	case MAJO_DEL:
		DelMaj();
		break;

	case MAJO_SEARCH:
		SearchMaj();
		break;
	case BACK:
		return;
	}
	system("pause");
}


void selectLectMenu(int* select)
{
	switch (*select)
	{
	case LECT_ADD:
		LectAdd();
		printf("전공 추가");
		break;

	case LECT_READ:
		LectRead();
		printf("전공 조회");
		break;

	case LECT_EDIT:
		UpdateLect();
		printf("전공 수정");
		break;

	case LECT_DEL:
		LectDel();
		printf("전공 삭제");
		break;

	case MAJO_SEARCH:
		SearchLect();
		printf("전공 검색");
		break;
	
	case BACK:
		return;
	}
	system("pause");
}









void selectMenu(int* select)
{

	switch (*select)//입력받은 선택번호
	{
	case MA_STD:
		GoToStd(); //학생관련 서브 메뉴
		break;

	case MA_PRO:
		GoToPro();//교수관련 서브 메뉴
		break;

	case MA_MAJOR:
		GoToMajo();//전공관련 서브 메뉴
		break;

	case MA_LECT:
		GoToLect();//수강정보 서브 메뉴
		break;

	case MA_EXIT:
	{
		printf("프로그램을 종료합니다.");
		*select = 9;
	}
	break;


	}
}
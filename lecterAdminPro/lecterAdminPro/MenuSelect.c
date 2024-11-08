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
		printf("���� �߰�");
		break;

	case LECT_READ:
		LectRead();
		printf("���� ��ȸ");
		break;

	case LECT_EDIT:
		UpdateLect();
		printf("���� ����");
		break;

	case LECT_DEL:
		LectDel();
		printf("���� ����");
		break;

	case MAJO_SEARCH:
		SearchLect();
		printf("���� �˻�");
		break;
	
	case BACK:
		return;
	}
	system("pause");
}









void selectMenu(int* select)
{

	switch (*select)//�Է¹��� ���ù�ȣ
	{
	case MA_STD:
		GoToStd(); //�л����� ���� �޴�
		break;

	case MA_PRO:
		GoToPro();//�������� ���� �޴�
		break;

	case MA_MAJOR:
		GoToMajo();//�������� ���� �޴�
		break;

	case MA_LECT:
		GoToLect();//�������� ���� �޴�
		break;

	case MA_EXIT:
	{
		printf("���α׷��� �����մϴ�.");
		*select = 9;
	}
	break;


	}
}
#include "def.h"
#include <stdio.h>
#include "Major.h"
#include "FileUtil.h"



typedef struct check
{
	MAJOR maj;
	int index;
}CHECK;



int searchMaj(MAJOR majArr[], CHECK chk[], int index, char* name)
{
	int foundIdx = 0;
	for (int i = 0; i < index; i++)
	{
		if (strcmp(majArr[i].name, name) == 0)
		{
			chk[foundIdx].maj = majArr[i];
			chk[foundIdx].index = i;
			foundIdx++;
		}
	}

	return foundIdx;

}


MAJOR displayMajUpdateFrom(MAJOR upSt)
{
	printf("===========================================================================================");
	printf("�����̸�\n");
	printf("�̸� : %s\n", upSt.name);
	printf("===========================================================================================");

	printf("\n");

	printf("������ ������ �Է����ּ���. * ������ ���� �������� '/no'�� �Է��ϰ� ���͸� �����ּ���. *\n\n");
	char chInput[70];

	printf("�̸��� �Է����ּ���.");
	scanf("%s", chInput);
	if (strcmp("/nu", chInput) != 0)
	{
		strcpy(upSt.name, chInput);
	}

	return upSt;
}



void displayMajInfo(int num, MAJOR maj)
{
	printf("\n");
	printf("��ȣ : %d\n\n", num);
	printf("�̸� : %s\n", maj.name);
	printf("���� : %d\n", maj.hackjum);
	printf("\n\n");
}




void AddMaj()
{
	MAJOR maj = { 0 };

	system("cls");
	printf("�̸� : ");
	scanf("%s", maj.name);

	printf("���� : ");
	scanf("%d", &maj.hackjum);

	if (majWrite(maj) != NULL)
	{
		printf("���� ����� �����Ͽ����ϴ�.");
	}
	else
	{
		printf("�������� ����� �����Ͽ����ϴ�.\n");//���� ������ ����
	}
}



void ReadMaj()
{
	MAJOR majArr[100];
	int index = majRead(majArr);
	int num = 1;
	if (index == 0)
	{
		printf("���� ����� �������� �ʽ��ϴ�.");
	}
	system("cls");
	for (int i = 0; i < index; i++)
	{
		MAJOR pro = majArr[i];
		displayMajInfo(num, pro);

		printf("\n");
		num++;
	}
}


void DelMaj()
{
	MAJOR majArr[100];
	MAJOR delArr[100];
	CHECK chk[100];
	char delName[20];
	system("cls");
	printf("������ ���� �̸��� �Է��ϼ���.");
	scanf("%s", &delName);

	int index = majRead(majArr);
	int delIndex = 0;
	int exceNum;


	int foundIndex = searchMaj(majArr, chk, index, delName);
	if (foundIndex == 0)
	{
		printf("������ ������ �������� �ʽ��ϴ�.");
		return;
	}
	int num = 1;
	if (foundIndex >= 2)
	{
		printf("������ ���������� �ֽ��ϴ�.\n");

		for (int i = 0; i < foundIndex; i++)
		{
			printf("�����̸� : %s\n", chk[i].maj.name);
			printf("\n\n");
			num++;
		}

		printf("������ �������� ��ȣ�� �Է����ּ���.");
		scanf("%d", &num);

		exceNum = chk[num - 1].index;//������ �����Ҷ� ������ �ε���

	}

	else
	{
		exceNum = chk[num - 1].index;//������ �����Ҷ� ������ �ε���
	}



	for (int i = 0; i < index; i++)
	{
		if (i != exceNum)//������ �ε����� �����ϰ� delArr�迭�� �����ϰ� ���ϰ���
		{
			delArr[delIndex] = majArr[i];
			delIndex++;
		}
	}
	majFileUpdate(delArr, delIndex);
	printf("%s ������ �����Ͽ����ϴ�.\n", delName);
}






void UpdateMaj()
{
	MAJOR foundArr[100];
	MAJOR majArr[100];
	CHECK che[100];
	MAJOR upSt;


	char upName[20];
	system("cls");
	printf("������ ���������� �̸��� �Է����ּ���.");
	scanf("%s", upName);
	int index = majRead(majArr);//�л������� �� ����
	int num = 1;//������ �����͸� �����ϱ����� ����
	int foundIdx = searchMaj(majArr, che, index, upName);//������ �л��� �˻��Ͽ� �迭�� ����
	if (foundIdx == 0)
	{
		printf("������ ������ �������� �ʽ��ϴ�.");
		return;
	}
	int finNum;



	if (foundIdx >= 2)
	{
		printf("\n");
		printf("���� ���������� �߰��Ͽ����ϴ�.\n\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�����̸� : %s\n", che[i].maj.name);
			printf("\n\n");
			num++;
		}


		printf("������ ���� ��ȣ�� �Է����ּ���. ");

		scanf("%d", &num);

		upSt = che[num - 1].maj;
		finNum = che[num - 1].index; //�л��迭 ���� ��ġ�� �Ѱܹ���

		printf("%d�� ������ �����ϼ̽��ϴ�.", num);

	}

	else
	{
		upSt = che[num - 1].maj;
		finNum = che[num - 1].index;//�л��迭 ���� ��ġ�� �Ѱܹ���
	}

	upSt = displayMajUpdateFrom(upSt);//������ ������ ���� �Է¶�
	majArr[finNum] = upSt; //������ �����͸� �л������� �迭�� ���� ����
	majFileUpdate(majArr, index);//������Ʈ�� �����͸� ����
	printf("%s ������ �����Ͽ����ϴ�. \n", upName);

	printf("");

}




void SearchMaj()
{
	MAJOR majArr[100];
	char seaName[20];
	int index = majRead(majArr);
	int num = 1;
	int found = 0;
	system("cls");
	printf("�˻��� ������ �Է��ϼ���.");
	scanf("%s", seaName);


	for (int i = 0; i < index; i++)
	{
		if (strcmp(majArr[i].name, seaName) == 0)
		{
			MAJOR maj = majArr[i];
			displayMajInfo(num, maj);
			num++;
			found = 1;
		}
	}

	if (found == 0)
	{
		printf("������ �������� �ʽ��ϴ�.\n");
	}

}
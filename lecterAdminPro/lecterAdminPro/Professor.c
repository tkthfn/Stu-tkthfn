#include "def.h"
#include <stdio.h>
#include "Professor.h"
#include "FileUtil.h"

typedef struct Check {
	PROFESSOR pro;
	int index;

}CHECK;



int searchPro(PROFESSOR proArr[], CHECK chk[], int index, char* name)
{
	int foundIdx = 0;
	
	for (int i = 0; i < index; i++)
	{
		if (strcmp(proArr[i].name, name) == 0)
		{
			chk[foundIdx].pro = proArr[i];
			chk[foundIdx].index = i;
			foundIdx++;
		}
	}

	return foundIdx;

}










void displayProInfo(int num, PROFESSOR pro)
{
	printf("\n");
	printf("��ȣ : %d\n\n", num);
	printf("�̸� : %s\n", pro.name);
	printf("�������� : %s\n", pro.major);
	printf("��ȭ��ȣ : %s\n", pro.tel);
	printf("�̸��� : %s\n", pro.email);
	printf("\n\n");
}



PROFESSOR displayProUpdateFrom(PROFESSOR upSt)
{
	printf("===========================================================================================");
	printf("���� ����\n");
	printf("�̸� : %s\n", upSt.name);
	printf("�������� : %s\n", upSt.major);
	printf("��ȭ��ȣ : %s\n", upSt.tel);
	printf("�̸��� : %s\n", upSt.email);
	printf("===========================================================================================");

	printf("\n");

	printf("������ ������ �Է����ּ���. * ������ ���� �������� '/no'�� �Է��ϰ� ���͸� �����ּ���. *\n\n");
	char chInput[70];

	printf("�̸��� �Է����ּ���.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.name, chInput);
	}


	printf("�̸����� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.email, chInput);
	}

	printf("���������� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.major, chInput);
	}


	printf("��ȭ��ȣ�� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.tel, chInput);
	}



	return upSt;


}





void AddPro()
{
	PROFESSOR pro = { 0 };

	system("cls");
	printf("�̸� : ");
	scanf("%s", pro.name);

	printf("�������� : ");
	scanf("%s", pro.major);

	printf("�̸��� : ");
	scanf("%s",pro.email);

	printf("��ȭ��ȣ : ");
	scanf("%s", pro.tel);

	
	if (proWrite(pro) != NULL)
	{
		printf("�������� ����� �����Ͽ����ϴ�.");
	}
	else
	{
		printf("�������� ����� �����Ͽ����ϴ�.\n");//���� ������ ����
	}
}



void ReadPro()
{
	PROFESSOR proArr[100];
	int index = proRead(proArr);
	int num = 1;
	system("cls");
	if (index == 0)
	{
		printf("���� ����� �������� �ʽ��ϴ�.");
		return;
	}
	for (int i = 0; i < index; i++)
	{
		PROFESSOR pro = proArr[i];
		displayProInfo(num, pro);

		printf("\n");
		num++;
	}
}


void DelPro()
{
	PROFESSOR proArr[100];
	PROFESSOR delArr[100];
	CHECK chk[100];
	char delName[20];
	system("cls");
	printf("������ ���� �̸��� �Է��ϼ���.");
	scanf("%s", &delName);

	int index = proRead(proArr);
	int delIndex = 0;
	int exceNum;


	int foundIndex = searchPro(proArr, chk, index, delName);
	if (foundIndex == 0)
	{
		printf("������ ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	int num = 1;
	if (foundIndex >= 2)
	{
		printf("�������� ������ �ֽ��ϴ�.\n");

		for (int i = 0; i < foundIndex; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", chk[i].pro.name);
			printf("�������� : %s\n", chk[i].pro.major);
			printf("��ȭ��ȣ : %s\n", chk[i].pro.tel);
			printf("�̸��� : %s\n", chk[i].pro.email);
			printf("\n\n");
			num++;
		}

		printf("������ ������ ��ȣ�� �Է����ּ���.");
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
			delArr[delIndex] = proArr[i];
			delIndex++;
		}
	}
	proFileUpdate(delArr, delIndex);
	printf("%s ������ �����Ͽ����ϴ�.\n", delName);
}






void UpdatePro()
{
	PROFESSOR foundArr[100];
	PROFESSOR proArr[100];
	CHECK che[100];
	PROFESSOR upSt;


	char upName[20];
	system("cls");
	printf("������ ������ �̸��� �Է����ּ���.");
	scanf("%s", upName);
	int index = proRead(proArr);//�л������� �� ����
	int num = 1;//������ �����͸� �����ϱ����� ����
	int foundIdx = searchPro(proArr, che, index, upName);//������ �л��� �˻��Ͽ� �迭�� ����
	if (foundIdx == 0)
	{
		printf("������ ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	int finNum;



	if (foundIdx >= 2)
	{
		printf("\n");
		printf("�������� ������ �߰��Ͽ����ϴ�.\n\n");
		
		for (int i = 0; i < foundIdx; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", che[i].pro.name);
			printf("�������� : %s\n", che[i].pro.major);
			printf("��ȭ��ȣ : %s\n", che[i].pro.tel);
			printf("�̸��� : %s\n", che[i].pro.email);
			printf("\n\n");
			num++;
		}


		printf("������ ������ ��ȣ�� �Է����ּ���. ");

		scanf("%d", &num);

		upSt = che[num - 1].pro;
		finNum = che[num - 1].index; //�л��迭 ���� ��ġ�� �Ѱܹ���

		printf("%d�� ������ �����ϼ̽��ϴ�.", num);

	}

	else
	{
		upSt = che[num - 1].pro;
		finNum = che[num - 1].index;//�л��迭 ���� ��ġ�� �Ѱܹ���
	}

	upSt = displayProUpdateFrom(upSt);//������ ������ ���� �Է¶�
	proArr[finNum] = upSt; //������ �����͸� �л������� �迭�� ���� ����
	proFileUpdate(proArr, index);//������Ʈ�� �����͸� ����
	

	printf("%s ������ �����Ͽ����ϴ�.\n", upName);

}




void SearchPro()
{
	PROFESSOR proArr[100];
	char seaName[20];
	int index = proRead(proArr);
	int num = 1;
	int found = 0;
	system("cls");
	printf("�˻��� ������ �̸��� �Է��ϼ���.");
	scanf("%s", seaName);
	

	for (int i = 0; i < index; i++)
	{
		if (strcmp(proArr[i].name, seaName) == 0)
		{
			PROFESSOR pro = proArr[i];
			displayProInfo(num, pro);
			num++;
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("������ �������� �ʽ��ϴ�.\n");
	}

}
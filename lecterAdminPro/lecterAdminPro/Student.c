#include "def.h"
#include <stdio.h>
#include "Student.h"
#include "FileUtil.h"


typedef struct Check{
	STUDENT std;
	int index;

}CHECK;






int searchStd(STUDENT stuArr[], CHECK chk[], int index, char* name)
{
	int foundIdx = 0;
	for (int i = 0; i < index; i++)
	{
		if (strcmp(stuArr[i].name, name) == 0)
		{
			chk[foundIdx].std = stuArr[i];
			chk[foundIdx].index = i;
			foundIdx++;
		}
	}

	return foundIdx;

}

void displayStdInfo(int num, STUDENT st)
{
	
	printf("\n");
	printf("��ȣ : %d\n\n", num);
	printf("�̸� : %s\n", st.name);
	printf("�й� : %d\n", st.std_id);
	printf("���� : %d\n", st.age);
	printf("�������� : %s\n", st.major);
	printf("��ȭ��ȣ : %s\n", st.tel);
	printf("�ּ� : %s\n", st.addr);
	printf("�̸��� : %s\n", st.email);
	printf("\n\n");
}




STUDENT displayUpdateFrom(STUDENT upSt)
{
	printf("===========================================================================================");
	printf("�л� ����\n");
	printf("�̸� : %s\n", upSt.name);
	printf("�й� : %d\n", upSt.std_id);
	printf("���� : %d\n", upSt.age);
	printf("�������� : %s\n", upSt.major);
	printf("��ȭ��ȣ : %s\n", upSt.tel);
	printf("�ּ� : %s\n", upSt.addr);
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

	printf("���̸� �Է��ϼ���. ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		int num = atoi(chInput);
		upSt.age = num;
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

	printf("�ּҸ� �Է��ϼ���. ");
	getchar();
	gets_s(chInput, sizeof(char) * 40);

	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.addr, chInput);
	}

	printf("�̸����� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.email, chInput);
	}

	return upSt;


}




void AddStd() 
{
	STUDENT st = { 0 };


		system("cls");
		printf("�̸� : ");
		scanf("%s", st.name);

		printf("�й� : ");
		scanf("%d", &st.std_id);
		

		printf("���� : ");
		scanf("%d", &st.age);
		

		printf("�������� : ");
		scanf("%s", st.major);
	

		printf("��ȭ��ȣ : ");
		scanf("%s", st.tel);
	

		printf("�ּ� : ");
		getchar();
		gets_s(st.addr, sizeof(char) * 40);
		

		printf("�̸��� : ");
		scanf("%s", st.email);
	




		if (stdWrite(st) != NULL)
		{
			printf("�л������� ���������� ����Ǿ����ϴ�.\n");//������ ���������� ����
		}
		else
		{
			printf("�л����� ��Ͽ� �����Ͽ����ϴ�.\n");//���� ������ ����
		}
}



void ReadStd()
{
	STUDENT stArr[100];
	int index = stdRead(stArr);
	int num = 1;
	system("cls");
	if (index == 0)
	{
		printf("�л� ����� �������� �ʽ��ϴ�.");
		return;
	}
	for (int i = 0; i < index; i++)
	{
		STUDENT st = stArr[i];
		displayStdInfo(num, st);

		printf("\n");
		num++;
	}
}


void DelStd()
{
	STUDENT stArr[100];
	STUDENT delArr[100];
	CHECK chk[100];
	char delName[20];
	system("cls");
	printf("������ �л� �̸��� �Է��ϼ���.");
	scanf("%s", &delName);

	int index = stdRead(stArr);
	
	int delIndex = 0;
	int exceNum;

	
	int foundIndex = searchStd(stArr, chk, index, delName); // �Է��� �̸��� ���Ͽ��� �ҷ��� ������ �迭�� ����
	if (foundIndex == 0)
	{
		printf("������ �л��� �������� �ʽ��ϴ�.\n");//�̸��� ã���� ������ ����
		return;
	}
	int num = 1;
	if (foundIndex >= 2)//���� �̸��� 2�� ������� ������ �̸��� ��ȣ�� �Է¹޾� ����
	{
		printf("�������� �л��� �ֽ��ϴ�.\n");
		
		for (int i = 0; i < foundIndex; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", chk[i].std.name);
			printf("�й� : %d\n", chk[i].std.std_id);
			printf("���� : %d\n", chk[i].std.age);
			printf("�������� : %s\n", chk[i].std.major);
			printf("��ȭ��ȣ : %s\n", chk[i].std.tel);
			printf("�ּ� : %s\n", chk[i].std.addr);
			printf("�̸��� : %s\n", chk[i].std.email);
			printf("\n\n");
			num++;
		}

		printf("������ �л��� ��ȣ�� �Է����ּ���.");
		scanf("%d", &num);

		exceNum = chk[num - 1].index;//�л��迭���� ������ ��ġ�� ������ ����

	}

	else
	{
		exceNum = chk[num - 1].index;//�л��迭���� ������ ��ġ�� ������ ����
	}

	
	
	for (int i = 0; i < index; i++)
	{
		if(i != exceNum)//
		{
			delArr[delIndex] = stArr[i];//�����ϴ� �����Ͱ� �ƴѰ�� ������ ����
			delIndex++;
		}
	}
	stdFileUpdate(delArr, delIndex);
	printf("%s �л��� �����Ͽ����ϴ�.\n", delName);
}


//void DelStd()
//{
//	STUDENT stArr[100];
//	STUDENT delArr[100];
//	STUDENT foundArr[100];
//	char delName[20];
//	int dataNumArr[100];
//
//	printf("������ �л� �̸��� �Է��ϼ���.");
//	scanf("%s", &delName);
//
//	int index = stdRead(stArr);
//	int delIndex = 0;
//	int exceNum;
//
//
//	int foundIndex = searchStd(stArr, foundArr, index, delName, dataNumArr);
//	int num = 1;
//	if (foundIndex >= 2)
//	{
//		printf("�������� �л��� �ֽ��ϴ�.");
//
//		for (int i = 0; i < foundIndex; i++)
//		{
//			printf("��ȣ : %d\n\n", num);
//			printf("�̸� : %s\n", foundArr[i].name);
//			printf("�й� : %d\n", foundArr[i].std_id);
//			printf("���� : %d\n", foundArr[i].age);
//			printf("�������� : %s\n", foundArr[i].major);
//			printf("��ȭ��ȣ : %s\n", foundArr[i].tel);
//			printf("�ּ� : %s\n", foundArr[i].addr);
//			printf("�̸��� : %s\n", foundArr[i].email);
//			printf("\n\n");
//			num++;
//		}
//
//		printf("������ �л��� ��ȣ�� �Է����ּ���.");
//		scanf("%d", &num);
//
//		exceNum = dataNumArr[num - 1];
//
//	}
//
//	else
//	{
//		exceNum = dataNumArr[num - 1];
//	}
//
//
//
//	for (int i = 0; i < index; i++)
//	{
//		if (i != exceNum)
//		{
//			delArr[delIndex] = stArr[i];
//			delIndex++;
//		}
//	}
//	stdFileUpdate(delArr, delIndex);
//
//}




//void DelStd()
//{
//	STUDENT stArr[100];
//	STUDENT delArr[100];
//	char delName[20];
//
//	printf("������ �л� �̸��� �Է��ϼ���.");
//	scanf("%s", &delName);
//
//	int index = stdRead(stArr);
//	int delIndex = 0;
//
//	for (int i = 0; i < index; i++)
//	{
//		if (strcmp(stArr[i].name, delName) != 0)
//		{
//			delArr[delIndex] = stArr[i];
//			delIndex++;
//		}
//	}
//
//
//	stdFileUpdate(delArr, delIndex);
//
//}

void UpdateStd()
{
	STUDENT foundArr[100];
	STUDENT stArr[100];
	CHECK che[100];
	STUDENT upSt;
	

	char upName[20];
	system("cls");
	printf("������ �л��� �̸��� �Է����ּ���.");
	scanf("%s", upName);
	int index = stdRead(stArr);//�л������� �� ����
	int num = 1;
	int foundIdx = searchStd(stArr, che, index, upName);//������ �л��� �˻��Ͽ� �迭�� ����
	if (foundIdx == 0)
	{
		printf("������ �л��� �������� �ʽ��ϴ�.\n");
		return;
	}
	int finNum;

	

	if (foundIdx >= 2)
	{
		printf("\n");
		printf("�������� �л��� �߰��Ͽ����ϴ�.\n\n");
		
		for (int i = 0; i < foundIdx; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", che[i].std.name);
			printf("�й� : %d\n", che[i].std.std_id);
			printf("���� : %d\n", che[i].std.age);
			printf("�������� : %s\n", che[i].std.major);
			printf("��ȭ��ȣ : %s\n", che[i].std.tel);
			printf("�ּ� : %s\n", che[i].std.addr);
			printf("�̸��� : %s\n", che[i].std.email);
			printf("\n\n");
			num++;
		}

		
		printf("������ �л��� ��ȣ�� �Է����ּ���. ");
		
		scanf("%d", &num);

		upSt   = che[num - 1].std;
		finNum = che[num - 1].index; //�л��迭 ���� ��ġ�� �Ѱܹ���

		printf("%d�� �л��� �����ϼ̽��ϴ�.",  num);
		
	}

	else
	{
		upSt = che[num - 1].std;
		finNum = che[num - 1].index;//�л��迭 ���� ��ġ�� �Ѱܹ���
	}

	upSt = displayUpdateFrom(upSt);//������ ������ ���� �Է¶�
	stArr[finNum] = upSt; //������ �����͸� �л������� �迭�� ���� ����
	stdFileUpdate(stArr, index);//������Ʈ�� �����͸� ����
	printf("%s�л� ������ �Ϸ��Ͽ����ϴ�.\n", upName);
	
	printf("");
	
}



void SearchStd()
{
	STUDENT stArr[100];
	char seaName[20];
	int index = stdRead(stArr);
	int num = 1;
	system("cls");
	printf("�˻��� �л��� �̸��� �Է��ϼ���.");
	scanf("%s", seaName);
	int found = 0;

	for (int i = 0; i < index; i++)
	{
		if (strcmp(stArr[i].name, seaName) == 0)
		{
			STUDENT st = stArr[i];
			displayStdInfo(num, st);
			num++;
			found = 1;
		}
	}

	if (found == 0)
	{
		printf("�л��� �������� �ʽ��ϴ�.");
	}

}
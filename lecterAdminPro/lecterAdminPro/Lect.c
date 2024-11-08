#include "def.h"
#include <stdio.h>
#include "Lecture.h"
#include "FileUtil.h"
#include <time.h>
#define SEARCH 1
#define NOSEARCH 0


typedef struct check
{
	LECT lect;
	int index;

}CHECK;



int searchLect(LECT lectArr[], CHECK chk[], int index, char* name)
{
	int foundIdx = 0;
	for (int i = 0; i < index; i++)
	{
		if (strcmp(lectArr[i].std.name, name) == 0)
		{
			chk[foundIdx].lect = lectArr[i];
			chk[foundIdx].index = i;
			foundIdx++;
		}
	}

	return foundIdx;

}









getTime(char tinfo[])
{
	time_t timer;
	struct tm* t;

	timer = time(NULL);
	t = localtime(&timer);

	char buf[40] = { 0 };

	sprintf(buf, "%d��%d��%d��-%d��%d��%d��",
		t->tm_year
		, t->tm_mon
		, t->tm_mday
		, t->tm_hour
		, t->tm_min
		, t->tm_sec);

	strcpy(tinfo, buf);

}


void displayLectInfo(int num, LECT lect)
{
	printf("\n");
	
	printf("------------���� �л� ����-------------\n");
	
	printf("��ȣ : %d\n", num);
	printf("�й� : %d\n", lect.std.std_id);
	printf("�̸� : %s\n", lect.std.name);
	printf("�����а� :%s\n", lect.std.major);
	printf("��ȭ��ȣ :%s\n", lect.std.tel);
	printf("�ּ�: %s\n", lect.std.addr);
	printf("�̸��� %s\n", lect.std.email);
	printf("\n\n");
	
	printf("------------��� ���� ����-------------\n");
	printf("�̸� :%s\n", lect.pro.name);
	printf("���� :%s\n", lect.pro.major);
	printf("��ȭ��ȣ:%s\n", lect.pro.tel);
	printf("Email:%s\n", lect.pro.email);
	printf("\n\n");


	printf("------------��û�� �������-------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("����%d: %s, ����: %d\n", i + 1 ,lect.maj[i].name, lect.maj[i].hackjum);
	}
	printf("\n\n");

	printf("��û��¥:%s\n", lect.date);
	printf("���ǽ�:%s\n", lect.classRoom);

}




LECT displayLectUpdateFrom(LECT upSt)
{
	printf("\n");

	printf("------------���� �л� ����-------------\n");

	printf("�й� : %d\n", upSt.std.std_id);
	printf("�̸� : %s\n", upSt.std.name);
	printf("�����а� :%s\n", upSt.std.major);
	printf("��ȭ��ȣ :%s\n", upSt.std.tel);
	printf("�ּ�: %s\n", upSt.std.addr);
	printf("�̸��� %s\n", upSt.std.email);
	printf("\n\n");

	printf("------------��� ���� ����-------------\n");
	printf("�̸� :%s\n", upSt.pro.name);
	printf("���� :%s\n", upSt.pro.major);
	printf("��ȭ��ȣ:%s\n", upSt.pro.tel);
	printf("Email:%s\n", upSt.pro.email);
	printf("\n\n");


	printf("------------��û�� �������-------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("����%d: %s, ����: %d\n", i + 1, upSt.maj[i].name, upSt.maj[i].hackjum);
	}
	printf("\n\n");

	printf("��û��¥:%s\n", upSt.date);
	printf("���ǽ�:%\n", upSt.classRoom);

	
	
	printf("������ ������ �Է����ּ���. * ������ ���� �������� '/no'�� �Է��ϰ� ���͸� �����ּ���. *\n\n");
	char chInput[70];

	
	printf("---------------------------�л����� ����------------------------------------------------\n");
	
	
	
	printf("�̸��� �Է����ּ���.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.name, chInput);
	}


	printf("�̸����� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.email, chInput);
	}

	printf("���������� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.major, chInput);
	}


	printf("��ȭ��ȣ�� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.tel, chInput);
	}


	printf("�ּҸ� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.addr, chInput);
	}

	



	printf("------------------------���� ���� ����---------------------------\n");

	printf("�̸��� �Է����ּ���.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.name, chInput);
	}


	printf("�̸����� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.email, chInput);
	}

	printf("���������� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.major, chInput);
	}


	printf("��ȭ��ȣ�� �Է��ϼ��� ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.tel, chInput);
	}




	printf("----------------------��û�� �������� ����-----------------------\n");
	printf("������ ������û ������ �Է����ּ��� ������ ���� �������� '/no'�� �Է����ּ���.\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("%d��° ������ �Է��ϼ��� \n", i + 1);
		scanf("%s", chInput);
		if (strcmp("/no", chInput) != 0)
		{
			strcpy(upSt.maj[i].name, chInput);
		}

		//printf("%d��° ������ �Է��ϼ��� \n", i + 1);
		//scanf("%d", &chInput);
		//if (strcmp("/no", chInput) != 0)
		//{
		//	int num = atoi(chInput);
		//	upSt.maj[i].hackjum;
		//}
	}
	
	printf("������ ���ǽ��� �Է��ϼ���.\n");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.classRoom, chInput);
	}

	
	return upSt;


}








int checkStu(STUDENT stuArr[], LECT* lect ,int index, char seaName[])
{
	for (int i = 0; i < index; i++)
	{
		if (strcmp(stuArr[i].name, seaName) == 0)
		{
			lect->std = stuArr[i];
			return SEARCH;
		}
	}

	return NOSEARCH;

}


int checkPro(PROFESSOR proArr[], LECT* lect ,int index, char seaName[])
{
	for (int i = 0; i < index; i++)
	{
		if (strcmp(proArr[i].name, seaName) == 0)
		{
			lect->pro = proArr[i];
			return SEARCH;
		}
	}

	return NOSEARCH;

}

int checkMaj(MAJOR majArr[], LECT* lect,int majIndex, int takeIndex ,char seaName[])
{
	for (int i = 0; i < majIndex; i++)
	{
		if (strcmp(majArr[i].name, seaName) == 0)
		{
			lect->maj[takeIndex] = majArr[i];
			return SEARCH;
		}
	}
	return NOSEARCH;

}


void LectAdd()
{
	LECT lect = { 0 };
	PROFESSOR proArr[100] = {0};
	STUDENT stuArr[100] = {0};
	MAJOR majArr[100] = { 0 };
	int proIndex = proRead(proArr);
	int stdIndex = stdRead(stuArr);
	int majIndex = majRead(majArr);
	int found = NOSEARCH;
	do 
	{
		found = NOSEARCH;
		printf("�л��̸��� �Է��ϼ���.");
		char seaName[20];
		scanf("%s", seaName);
		found = checkStu(stuArr, &lect ,stdIndex, seaName);
		if (found == SEARCH)
		{
			printf("%s �л��� ����Ͽ����ϴ�.\n", seaName);
		}
		else
		{
			printf("�ش� �л��� �������� �ʽ��ϴ�.\n");
		}

	} while (found != SEARCH);


	do
	{
		found = NOSEARCH;
		printf("���� �̸��� �Է��ϼ���.");
		char seaName[20];
		scanf("%s", seaName);

		found = checkPro(proArr, &lect ,proIndex, seaName);

		if (found == SEARCH)
		{
			printf("%s ������ ����Ͽ����ϴ�.\n", lect.std.name);
		}
		else
		{
			printf("�ش� ������ �������� �ʽ��ϴ�.\n");
		}
	} while (found != SEARCH);


	int index = 0;
	do
	{
		found = NOSEARCH;
		printf("%d��° ���������� �Է��ϼ���.", index + 1);
		char seaName[20];
		scanf("%s", seaName);
		found = checkMaj(majArr, &lect ,majIndex, index ,seaName);
		
		if (found == SEARCH)
		{
			printf("�ش� ���������� ��ϵǾ����ϴ�.\n");
			index++;
		}

		else
		{
			printf("�ش� ���������� ���������ʽ��ϴ�.\n");
		}


	} while (index < 3);

	
	
	
	getTime(lect.date);
	printf("���ǽ��� �Է��ϼ���.");
	scanf("%s", lect.classRoom);

	if (LectFileWrite(lect) != NULL)
	{
		printf("���������� ���������� ��ϵǾ����ϴ�.");
	}

	else
	{
		printf("������������� �����߽��ϴ�.");
	}
}




void LectRead()
{
	LECT lectArr[100];
	int index = LectFileRead(lectArr);
	int num = 1;
	system("cls");
	for (int i = 0; i < index; i++)
	{
		LECT lect = lectArr[i];
		displayLectInfo(num, lect);

		printf("\n");
		num++;
	}
}






void LectDel()
{
	LECT lectArr[100];
	LECT delArr[100];
	CHECK chk[100] = { 0 };
	char delName[20];
	system("cls");
	printf("������ �������� �л� �̸��� �Է��ϼ���.");
	scanf("%s", &delName);

	int index = LectFileRead(lectArr);
	int delIndex = 0;
	int exceNum;


	int foundIdx = searchLect(lectArr, chk, index, delName);
	int num = 1;
	if (foundIdx == 0)
	{
		printf("������ ���������� �������� �ʽ��ϴ�.");
		return;
	}
	if (foundIdx >= 2)
	{
		printf("�������� �л������� �ֽ��ϴ�.\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", chk[i].lect.std.name);
			printf("�й� : %d\n", chk[i].lect.std.std_id);
			printf("\n\n");
			num++;
		}

		printf("������ �л��� ��ȣ�� �Է����ּ���.");
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
			delArr[delIndex] =lectArr[i];
			delIndex++;
		}
	}
	LectFileUpdate(delArr, delIndex);
	printf("%s �л��� �����Ͽ����ϴ�.\n", delName);
}










void UpdateLect()
{
	LECT foundArr[100];
	LECT lectArr[100];
	CHECK che[100];
	LECT upSt;


	char upName[20];
	system("cls");
	printf("������ ���������� �л��̸��� �Է����ּ���.");
	scanf("%s", upName);
	int index = LectFileRead(lectArr);//�л������� �� ����
	int num = 1;//������ �����͸� �����ϱ����� ����
	int foundIdx = searchLect(lectArr, che, index, upName);//������ �л��� �˻��Ͽ� �迭�� ����
	int finNum;
	if (foundIdx == 0)
	{
		printf("������ ���������� �������� �ʽ��ϴ�.");
		return;
	}

	if (foundIdx >= 2)
	{
		printf("\n");
		printf("�������� �л��� �߰��Ͽ����ϴ�.\n\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("��ȣ : %d\n\n", num);
			printf("�̸� : %s\n", che[i].lect.std.name);
			printf("�й� : %d\n", che[i].lect.std.std_id);
			printf("\n\n");
			num++;
		}


		printf("������ �л��� ��ȣ�� �Է����ּ���. ");

		scanf("%d", &num);

		upSt = che[num - 1].lect;
		finNum = che[num - 1].index; //�л��迭 ���� ��ġ�� �Ѱܹ���

		printf("%d�� �л��� �����ϼ̽��ϴ�.", num);

	}

	else
	{
		upSt = che[num - 1].lect;
		finNum = che[num - 1].index;//�л��迭 ���� ��ġ�� �Ѱܹ���
	}

	upSt = displayLectUpdateFrom(upSt);//������ ������ ���� �Է¶�
	lectArr[finNum] = upSt; //������ �����͸� �л������� �迭�� ���� ����
	LectFileUpdate(lectArr, index);//������Ʈ�� �����͸� ����
	printf("%s �л��� �����Ͽ����ϴ�.\n", upName);

	printf("");

}







void SearchLect()
{
	LECT lectArr[100];
	char seaName[20];
	int index = LectFileRead(lectArr);
	int num = 1;
	int found = 0;
	system("cls");
	printf("�˻��� �������� �л��� �̸��� �Է��ϼ���.");
	scanf("%s", seaName);


	for (int i = 0; i < index; i++)
	{
		if (strcmp(lectArr[i].std.name, seaName) == 0)
		{
			LECT lect = lectArr[i];
			displayLectInfo(num, lect);
			num++;
			found = 1;
		}
	}

	if (found == 0)
	{
		printf("���������� �������� �ʽ��ϴ�.");
	}

}
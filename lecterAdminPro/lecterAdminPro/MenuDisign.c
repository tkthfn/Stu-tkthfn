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
	printf("�޴��� �����Ͽ� �ֽʽÿ�\n");
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
	printf("�л� ���� �޴�\n");
	printf("==========================================\n");


	printf("�޴��� �����Ͽ� �ֽʽÿ�\n");

	paintStdMenu(select);

	printf("==========================================\n");

	printf("\n");
}


void drawingProMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("���� ���� �޴�\n");
	printf("==========================================\n");


	printf("�޴��� �����Ͽ� �ֽʽÿ�\n");

	paintProMenu(select);

	printf("==========================================\n");

	printf("\n");
}

void drawingMajoMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("�������� ���� �޴�\n");
	printf("==========================================\n");


	printf("�޴��� �����Ͽ� �ֽʽÿ�\n");

	paintMajoMenu(select);

	printf("==========================================\n");

	printf("\n");
}


void drawingLectMenu(int select)
{
	system("cls");
	printf("==========================================\n");
	printf("�������� ���� �޴�\n");
	printf("==========================================\n");


	printf("�޴��� �����Ͽ� �ֽʽÿ�\n");

	paintLectMenu(select);

	printf("==========================================\n");

	printf("\n");
}













void paintMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. �л����� �޴�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("1. �л����� �޴�\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. �������� �޴�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("2. �������� �޴�\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. �������� �޴�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("3. �������� �޴�\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. �������� �޴�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("4. �������� �޴�\n");
	}


	if (select == 5)
	{
		fontColor(240);
		printf("5. ���α׷� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("5. ���α׷� ����\n");
	}

}


void paintStdMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. �л� �߰�\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. �л� �߰�\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. �л� ��ȸ\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. �л� ��ȸ\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. �л� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. �л� ����\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. �л� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. �л� ����\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. �л� �˻�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. �л� �˻�\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("�ڷ� ����\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("�ڷ� ����\n");
	}


}


void paintProMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. ���� �߰�\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. ���� �߰�\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. ���� ��ȸ\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. ���� ��ȸ\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. ���� ����\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. ���� ����\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. ���� �˻�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. ���� �˻�\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("�ڷ� ����\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("�ڷ� ����\n");
	}



}



void paintMajoMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. ���� �߰�\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. ���� �߰�\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. ���� ��ȸ\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. ���� ��ȸ\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. ���� ����\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. ���� ����\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. ���� �˻�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. ���� �˻�\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("�ڷ� ����\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("�ڷ� ����\n");
	}

}


void paintLectMenu(int select)
{
	if (select == 1)
	{
		fontColor(240);
		printf("1. ���� ���� �߰�\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("1. ���� ���� �߰�\n");
	}

	if (select == 2)
	{
		fontColor(240);
		printf("2. ���� ���� ��ȸ\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("2. ���� ���� ��ȸ\n");
	}

	if (select == 3)
	{
		fontColor(240);
		printf("3. ���� ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("3. ���� ���� ����\n");
	}

	if (select == 4)
	{
		fontColor(240);
		printf("4. ���� ���� ����\n");
		fontColor(LIGHT_GREEN);
	}

	else
	{
		printf("4. ���� ���� ����\n");
	}

	if (select == 5)
	{
		fontColor(240);
		printf("5. ���� ���� �˻�\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("5. ���� ���� �˻�\n");
	}


	if (select == 6)
	{
		fontColor(240);
		printf("�ڷ� ����\n");
		fontColor(LIGHT_GREEN);
	}
	else
	{
		printf("�ڷ� ����\n");
	}

}

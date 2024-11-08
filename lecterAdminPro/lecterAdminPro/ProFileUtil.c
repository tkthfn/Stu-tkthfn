#include "def.h"
#include <stdio.h>
#include "Professor.h"
#include "FileUtil.h"






FILE* proWrite(PROFESSOR pro)
{
	FILE* fp = fopen(FILE_PRO, "ab");


	if (fp == NULL)
	{
		printf("���� ������ �����߽��ϴ�.");
		return fp;
	}

	fwrite(&pro, sizeof(PROFESSOR), 1, fp);
	fclose(fp);
	return fp;
}



int proRead(PROFESSOR proArr[])
{
	FILE* fp = fopen(FILE_PRO, "rb");
	PROFESSOR pr = { 0 };
	if (fp == NULL)
	{
		printf("������ ���� ���� �����ϴ�.");
		return;
	}

	int index = 0;

	while (fread(&pr, sizeof(PROFESSOR), 1, fp))
	{
		proArr[index] = pr;
		index++;
	}

	fclose(fp);
	return index;
}




void proFileUpdate(PROFESSOR pro[], int index)
{
	FILE* fp = fopen(FILE_PRO, "wb");
	if (fp == NULL)
	{
		printf("���� ������ �����߽��ϴ�.");
		return;
	}

	for (int i = 0; i < index; i++)
	{
		fwrite(&pro[i], sizeof(PROFESSOR), 1, fp);
	}

	fclose(fp);
}

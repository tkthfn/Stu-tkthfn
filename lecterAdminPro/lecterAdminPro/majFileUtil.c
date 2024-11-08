#include "def.h"
#include <stdio.h>
#include "Major.h"
#include "FileUtil.h"


FILE* majWrite(MAJOR maj)
{
	FILE* fp = fopen(FILE_MAJ, "ab");


	if (fp == NULL)
	{
		printf("���� ������ �����߽��ϴ�.");
		return fp;
	}

	fwrite(&maj, sizeof(MAJOR), 1, fp);
	fclose(fp);
	return fp;
}




void majFileUpdate(MAJOR maj[], int index)
{
	FILE* fp = fopen(FILE_MAJ, "wb");
	if (fp == NULL)
	{
		printf("���� ������ �����߽��ϴ�.");
		return;
	}

	for (int i = 0; i < index; i++)
	{
		fwrite(&maj[i], sizeof(MAJOR), 1, fp);
	}

	fclose(fp);
}



int majRead(MAJOR proArr[])
{
	FILE* fp = fopen(FILE_MAJ, "rb");
	MAJOR maj = { 0 };
	if (fp == NULL)
	{
		printf("������ ���� ���� �����ϴ�.");
		return;
	}

	int index = 0;

	while (fread(&maj, sizeof(MAJOR), 1, fp))
	{
		proArr[index] = maj;
		index++;
	}

	fclose(fp);
	return index;
}
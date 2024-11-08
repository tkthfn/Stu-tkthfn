#include "def.h"
#include <stdio.h>
#include "Student.h"
#include "FileUtil.h"




FILE* stdWrite(STUDENT st)
{
	FILE* fp = fopen(FILE_STU, "ab");


	if (fp == NULL)
	{
		printf("파일 생성에 실패했습니다.");
		return fp;
	}

	fwrite(&st, sizeof(STUDENT), 1, fp);
	fclose(fp);
	return fp;
}





void stdFileUpdate(STUDENT st[], int index)
{
	FILE* fp = fopen(FILE_STU, "wb");
	if (fp == NULL)
	{
		printf("파일 생성에 실패했습니다.");
		return;
	}

	for (int i = 0; i < index; i++)
	{
		fwrite(&st[i], sizeof(STUDENT), 1, fp);
	}

	fclose(fp);
}




int stdRead(STUDENT stArr[])
{
	FILE* fp = fopen(FILE_STU, "rb");
	STUDENT st = { 0 };
	if (fp == NULL)
	{
		printf("파일을 읽을 수가 없습니다.");
		return;
	}

	int index = 0;

	while (fread(&st, sizeof(STUDENT), 1, fp))
	{
		stArr[index] = st;
		index++;
	}

	fclose(fp);
	return index;
}

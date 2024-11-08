#include "def.h"
#include <stdio.h>
#include "Lecture.h"
#include "FileUtil.h"








FILE* LectFileWrite(LECT lect)
{
	FILE* fp = fopen(FILE_LECT, "ab");


	if (fp == NULL)
	{
		printf("파일 생성에 실패했습니다.");
		return fp;
	}

	fwrite(&lect, sizeof(LECT), 1, fp);
	fclose(fp);

	return fp;
}




void LectFileUpdate(LECT lectArr[], int index)
{
	FILE* fp = fopen(FILE_LECT, "wb");
	if (fp == NULL)
	{
		printf("파일 생성에 실패했습니다.");
		return;
	}

	for (int i = 0; i < index; i++)
	{
		fwrite(&lectArr[i], sizeof(LECT), 1, fp);
	}

	fclose(fp);
}



int LectFileRead(LECT lectArr[])
{
	FILE* fp = fopen(FILE_LECT, "rb");
	LECT lect = { 0 };
	if (fp == NULL)
	{
		printf("파일을 읽을 수가 없습니다.");
		return;
	}

	int index = 0;

	while (fread(&lect, sizeof(LECT), 1, fp))
	{
		lectArr[index] = lect;
		index++;
	}

	fclose(fp);
	return index;
}
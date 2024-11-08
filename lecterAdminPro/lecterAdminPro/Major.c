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
	printf("과목이름\n");
	printf("이름 : %s\n", upSt.name);
	printf("===========================================================================================");

	printf("\n");

	printf("수정할 정보를 입력해주세요. * 수정을 하지 않으려면 '/no'을 입력하고 엔터를 눌러주세요. *\n\n");
	char chInput[70];

	printf("이름을 입력해주세요.");
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
	printf("번호 : %d\n\n", num);
	printf("이름 : %s\n", maj.name);
	printf("학점 : %d\n", maj.hackjum);
	printf("\n\n");
}




void AddMaj()
{
	MAJOR maj = { 0 };

	system("cls");
	printf("이름 : ");
	scanf("%s", maj.name);

	printf("학점 : ");
	scanf("%d", &maj.hackjum);

	if (majWrite(maj) != NULL)
	{
		printf("전공 등록이 성공하였습니다.");
	}
	else
	{
		printf("전공정보 등록이 실패하였습니다.\n");//파일 생성이 실패
	}
}



void ReadMaj()
{
	MAJOR majArr[100];
	int index = majRead(majArr);
	int num = 1;
	if (index == 0)
	{
		printf("전공 목록이 존재하지 않습니다.");
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
	printf("삭제할 전공 이름을 입력하세요.");
	scanf("%s", &delName);

	int index = majRead(majArr);
	int delIndex = 0;
	int exceNum;


	int foundIndex = searchMaj(majArr, chk, index, delName);
	if (foundIndex == 0)
	{
		printf("삭제할 전공이 존재하지 않습니다.");
		return;
	}
	int num = 1;
	if (foundIndex >= 2)
	{
		printf("동명의 전공과목이 있습니다.\n");

		for (int i = 0; i < foundIndex; i++)
		{
			printf("과목이름 : %s\n", chk[i].maj.name);
			printf("\n\n");
			num++;
		}

		printf("삭제할 전공과목 번호를 입력해주세요.");
		scanf("%d", &num);

		exceNum = chk[num - 1].index;//파일을 갱신할때 제외할 인덱스

	}

	else
	{
		exceNum = chk[num - 1].index;//파일을 갱신할때 제외할 인덱스
	}



	for (int i = 0; i < index; i++)
	{
		if (i != exceNum)//삭제할 인덱스를 제외하고 delArr배열에 저장하고 파일갱신
		{
			delArr[delIndex] = majArr[i];
			delIndex++;
		}
	}
	majFileUpdate(delArr, delIndex);
	printf("%s 전공을 삭제하였습니다.\n", delName);
}






void UpdateMaj()
{
	MAJOR foundArr[100];
	MAJOR majArr[100];
	CHECK che[100];
	MAJOR upSt;


	char upName[20];
	system("cls");
	printf("수정할 전공과목의 이름을 입력해주세요.");
	scanf("%s", upName);
	int index = majRead(majArr);//학생데이터 총 갯수
	int num = 1;//수정할 데이터를 선택하기위한 변수
	int foundIdx = searchMaj(majArr, che, index, upName);//수정할 학생을 검색하여 배열에 담음
	if (foundIdx == 0)
	{
		printf("수정할 전공이 존재하지 않습니다.");
		return;
	}
	int finNum;



	if (foundIdx >= 2)
	{
		printf("\n");
		printf("동명 전공과목을 발견하였습니다.\n\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("과목이름 : %s\n", che[i].maj.name);
			printf("\n\n");
			num++;
		}


		printf("수정할 전공 번호를 입력해주세요. ");

		scanf("%d", &num);

		upSt = che[num - 1].maj;
		finNum = che[num - 1].index; //학생배열 최종 위치를 넘겨받음

		printf("%d번 과목을 선택하셨습니다.", num);

	}

	else
	{
		upSt = che[num - 1].maj;
		finNum = che[num - 1].index;//학생배열 최종 위치를 넘겨받음
	}

	upSt = displayMajUpdateFrom(upSt);//데이터 수정을 위한 입력란
	majArr[finNum] = upSt; //수정한 데이터를 학생데이터 배열에 덮어 씌움
	majFileUpdate(majArr, index);//업데이트한 데이터를 적용
	printf("%s 전공을 수정하였습니다. \n", upName);

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
	printf("검색할 과목을 입력하세요.");
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
		printf("전공이 존재하지 않습니다.\n");
	}

}
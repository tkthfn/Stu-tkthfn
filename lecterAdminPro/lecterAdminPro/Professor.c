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
	printf("번호 : %d\n\n", num);
	printf("이름 : %s\n", pro.name);
	printf("전공과목 : %s\n", pro.major);
	printf("전화번호 : %s\n", pro.tel);
	printf("이메일 : %s\n", pro.email);
	printf("\n\n");
}



PROFESSOR displayProUpdateFrom(PROFESSOR upSt)
{
	printf("===========================================================================================");
	printf("교수 정보\n");
	printf("이름 : %s\n", upSt.name);
	printf("전공과목 : %s\n", upSt.major);
	printf("전화번호 : %s\n", upSt.tel);
	printf("이메일 : %s\n", upSt.email);
	printf("===========================================================================================");

	printf("\n");

	printf("수정할 정보를 입력해주세요. * 수정을 하지 않으려면 '/no'을 입력하고 엔터를 눌러주세요. *\n\n");
	char chInput[70];

	printf("이름을 입력해주세요.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.name, chInput);
	}


	printf("이메일을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.email, chInput);
	}

	printf("전공과목을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.major, chInput);
	}


	printf("전화번호를 입력하세요 ");
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
	printf("이름 : ");
	scanf("%s", pro.name);

	printf("전공과목 : ");
	scanf("%s", pro.major);

	printf("이메일 : ");
	scanf("%s",pro.email);

	printf("전화번호 : ");
	scanf("%s", pro.tel);

	
	if (proWrite(pro) != NULL)
	{
		printf("교수정보 등록이 성공하였습니다.");
	}
	else
	{
		printf("교수정보 등록이 실패하였습니다.\n");//파일 생성이 실패
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
		printf("교수 목록이 존재하지 않습니다.");
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
	printf("삭제할 교수 이름을 입력하세요.");
	scanf("%s", &delName);

	int index = proRead(proArr);
	int delIndex = 0;
	int exceNum;


	int foundIndex = searchPro(proArr, chk, index, delName);
	if (foundIndex == 0)
	{
		printf("삭제할 교수가 존재하지 않습니다.\n");
		return;
	}
	int num = 1;
	if (foundIndex >= 2)
	{
		printf("동명인의 교수가 있습니다.\n");

		for (int i = 0; i < foundIndex; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", chk[i].pro.name);
			printf("전공과목 : %s\n", chk[i].pro.major);
			printf("전화번호 : %s\n", chk[i].pro.tel);
			printf("이메일 : %s\n", chk[i].pro.email);
			printf("\n\n");
			num++;
		}

		printf("삭제할 교수의 번호를 입력해주세요.");
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
			delArr[delIndex] = proArr[i];
			delIndex++;
		}
	}
	proFileUpdate(delArr, delIndex);
	printf("%s 교수을 삭제하였습니다.\n", delName);
}






void UpdatePro()
{
	PROFESSOR foundArr[100];
	PROFESSOR proArr[100];
	CHECK che[100];
	PROFESSOR upSt;


	char upName[20];
	system("cls");
	printf("수정할 교수의 이름을 입력해주세요.");
	scanf("%s", upName);
	int index = proRead(proArr);//학생데이터 총 갯수
	int num = 1;//수정할 데이터를 선택하기위한 변수
	int foundIdx = searchPro(proArr, che, index, upName);//수정할 학생을 검색하여 배열에 담음
	if (foundIdx == 0)
	{
		printf("수정할 교수가 존재하지 않습니다.\n");
		return;
	}
	int finNum;



	if (foundIdx >= 2)
	{
		printf("\n");
		printf("동명인의 교수를 발견하였습니다.\n\n");
		
		for (int i = 0; i < foundIdx; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", che[i].pro.name);
			printf("전공과목 : %s\n", che[i].pro.major);
			printf("전화번호 : %s\n", che[i].pro.tel);
			printf("이메일 : %s\n", che[i].pro.email);
			printf("\n\n");
			num++;
		}


		printf("수정할 교수의 번호를 입력해주세요. ");

		scanf("%d", &num);

		upSt = che[num - 1].pro;
		finNum = che[num - 1].index; //학생배열 최종 위치를 넘겨받음

		printf("%d번 교수를 선택하셨습니다.", num);

	}

	else
	{
		upSt = che[num - 1].pro;
		finNum = che[num - 1].index;//학생배열 최종 위치를 넘겨받음
	}

	upSt = displayProUpdateFrom(upSt);//데이터 수정을 위한 입력란
	proArr[finNum] = upSt; //수정한 데이터를 학생데이터 배열에 덮어 씌움
	proFileUpdate(proArr, index);//업데이트한 데이터를 적용
	

	printf("%s 교수를 수정하였습니다.\n", upName);

}




void SearchPro()
{
	PROFESSOR proArr[100];
	char seaName[20];
	int index = proRead(proArr);
	int num = 1;
	int found = 0;
	system("cls");
	printf("검색할 교수의 이름을 입력하세요.");
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
		printf("교수가 존재하지 않습니다.\n");
	}

}
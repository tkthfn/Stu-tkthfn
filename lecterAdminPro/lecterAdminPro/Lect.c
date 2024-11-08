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

	sprintf(buf, "%d년%d월%d일-%d시%d분%d초",
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
	
	printf("------------수강 학생 정보-------------\n");
	
	printf("번호 : %d\n", num);
	printf("학번 : %d\n", lect.std.std_id);
	printf("이름 : %s\n", lect.std.name);
	printf("전공학과 :%s\n", lect.std.major);
	printf("전화번호 :%s\n", lect.std.tel);
	printf("주소: %s\n", lect.std.addr);
	printf("이메일 %s\n", lect.std.email);
	printf("\n\n");
	
	printf("------------담당 교수 정보-------------\n");
	printf("이름 :%s\n", lect.pro.name);
	printf("전공 :%s\n", lect.pro.major);
	printf("전화번호:%s\n", lect.pro.tel);
	printf("Email:%s\n", lect.pro.email);
	printf("\n\n");


	printf("------------신청한 전공목록-------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("전공%d: %s, 학점: %d\n", i + 1 ,lect.maj[i].name, lect.maj[i].hackjum);
	}
	printf("\n\n");

	printf("신청날짜:%s\n", lect.date);
	printf("강의실:%s\n", lect.classRoom);

}




LECT displayLectUpdateFrom(LECT upSt)
{
	printf("\n");

	printf("------------수강 학생 정보-------------\n");

	printf("학번 : %d\n", upSt.std.std_id);
	printf("이름 : %s\n", upSt.std.name);
	printf("전공학과 :%s\n", upSt.std.major);
	printf("전화번호 :%s\n", upSt.std.tel);
	printf("주소: %s\n", upSt.std.addr);
	printf("이메일 %s\n", upSt.std.email);
	printf("\n\n");

	printf("------------담당 교수 정보-------------\n");
	printf("이름 :%s\n", upSt.pro.name);
	printf("전공 :%s\n", upSt.pro.major);
	printf("전화번호:%s\n", upSt.pro.tel);
	printf("Email:%s\n", upSt.pro.email);
	printf("\n\n");


	printf("------------신청한 전공목록-------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("전공%d: %s, 학점: %d\n", i + 1, upSt.maj[i].name, upSt.maj[i].hackjum);
	}
	printf("\n\n");

	printf("신청날짜:%s\n", upSt.date);
	printf("강의실:%\n", upSt.classRoom);

	
	
	printf("수정할 정보를 입력해주세요. * 수정을 하지 않으려면 '/no'을 입력하고 엔터를 눌러주세요. *\n\n");
	char chInput[70];

	
	printf("---------------------------학생정보 수정------------------------------------------------\n");
	
	
	
	printf("이름을 입력해주세요.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.name, chInput);
	}


	printf("이메일을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.email, chInput);
	}

	printf("전공과목을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.major, chInput);
	}


	printf("전화번호를 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.tel, chInput);
	}


	printf("주소를 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.std.addr, chInput);
	}

	



	printf("------------------------교수 정보 수정---------------------------\n");

	printf("이름을 입력해주세요.");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.name, chInput);
	}


	printf("이메일을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.email, chInput);
	}

	printf("전공과목을 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.major, chInput);
	}


	printf("전화번호를 입력하세요 ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.pro.tel, chInput);
	}




	printf("----------------------신청한 전공과목 수정-----------------------\n");
	printf("수정할 수강신청 과목을 입력해주세요 수정을 하지 않으려면 '/no'를 입력해주세요.\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 과목을 입력하세요 \n", i + 1);
		scanf("%s", chInput);
		if (strcmp("/no", chInput) != 0)
		{
			strcpy(upSt.maj[i].name, chInput);
		}

		//printf("%d번째 학점을 입력하세요 \n", i + 1);
		//scanf("%d", &chInput);
		//if (strcmp("/no", chInput) != 0)
		//{
		//	int num = atoi(chInput);
		//	upSt.maj[i].hackjum;
		//}
	}
	
	printf("수정할 강의실을 입력하세요.\n");
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
		printf("학생이름을 입력하세요.");
		char seaName[20];
		scanf("%s", seaName);
		found = checkStu(stuArr, &lect ,stdIndex, seaName);
		if (found == SEARCH)
		{
			printf("%s 학생을 등록하였습니다.\n", seaName);
		}
		else
		{
			printf("해당 학생은 존재하지 않습니다.\n");
		}

	} while (found != SEARCH);


	do
	{
		found = NOSEARCH;
		printf("교수 이름을 입력하세요.");
		char seaName[20];
		scanf("%s", seaName);

		found = checkPro(proArr, &lect ,proIndex, seaName);

		if (found == SEARCH)
		{
			printf("%s 교수를 등록하였습니다.\n", lect.std.name);
		}
		else
		{
			printf("해당 교수는 존재하지 않습니다.\n");
		}
	} while (found != SEARCH);


	int index = 0;
	do
	{
		found = NOSEARCH;
		printf("%d번째 수강과목을 입력하세요.", index + 1);
		char seaName[20];
		scanf("%s", seaName);
		found = checkMaj(majArr, &lect ,majIndex, index ,seaName);
		
		if (found == SEARCH)
		{
			printf("해당 수강과목이 등록되었습니다.\n");
			index++;
		}

		else
		{
			printf("해당 수강과목은 존재하지않습니다.\n");
		}


	} while (index < 3);

	
	
	
	getTime(lect.date);
	printf("강의실을 입력하세요.");
	scanf("%s", lect.classRoom);

	if (LectFileWrite(lect) != NULL)
	{
		printf("수강정보가 성공적으로 등록되었습니다.");
	}

	else
	{
		printf("수강정보등록이 실패했습니다.");
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
	printf("삭제할 수강정보 학생 이름을 입력하세요.");
	scanf("%s", &delName);

	int index = LectFileRead(lectArr);
	int delIndex = 0;
	int exceNum;


	int foundIdx = searchLect(lectArr, chk, index, delName);
	int num = 1;
	if (foundIdx == 0)
	{
		printf("삭제할 수강정보가 존재하지 않습니다.");
		return;
	}
	if (foundIdx >= 2)
	{
		printf("동명인의 학생정보가 있습니다.\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", chk[i].lect.std.name);
			printf("학번 : %d\n", chk[i].lect.std.std_id);
			printf("\n\n");
			num++;
		}

		printf("삭제할 학생의 번호를 입력해주세요.");
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
			delArr[delIndex] =lectArr[i];
			delIndex++;
		}
	}
	LectFileUpdate(delArr, delIndex);
	printf("%s 학생을 삭제하였습니다.\n", delName);
}










void UpdateLect()
{
	LECT foundArr[100];
	LECT lectArr[100];
	CHECK che[100];
	LECT upSt;


	char upName[20];
	system("cls");
	printf("수정할 수강정보의 학생이름을 입력해주세요.");
	scanf("%s", upName);
	int index = LectFileRead(lectArr);//학생데이터 총 갯수
	int num = 1;//수정할 데이터를 선택하기위한 변수
	int foundIdx = searchLect(lectArr, che, index, upName);//수정할 학생을 검색하여 배열에 담음
	int finNum;
	if (foundIdx == 0)
	{
		printf("수정할 수강정보가 존재하지 않습니다.");
		return;
	}

	if (foundIdx >= 2)
	{
		printf("\n");
		printf("동명인의 학생을 발견하였습니다.\n\n");

		for (int i = 0; i < foundIdx; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", che[i].lect.std.name);
			printf("학번 : %d\n", che[i].lect.std.std_id);
			printf("\n\n");
			num++;
		}


		printf("수정할 학생의 번호를 입력해주세요. ");

		scanf("%d", &num);

		upSt = che[num - 1].lect;
		finNum = che[num - 1].index; //학생배열 최종 위치를 넘겨받음

		printf("%d번 학생를 선택하셨습니다.", num);

	}

	else
	{
		upSt = che[num - 1].lect;
		finNum = che[num - 1].index;//학생배열 최종 위치를 넘겨받음
	}

	upSt = displayLectUpdateFrom(upSt);//데이터 수정을 위한 입력란
	lectArr[finNum] = upSt; //수정한 데이터를 학생데이터 배열에 덮어 씌움
	LectFileUpdate(lectArr, index);//업데이트한 데이터를 적용
	printf("%s 학생을 수정하였습니다.\n", upName);

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
	printf("검색할 수강정보 학생의 이름을 입력하세요.");
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
		printf("수강정보가 존재하지 않습니다.");
	}

}
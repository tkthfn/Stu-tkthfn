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
	printf("번호 : %d\n\n", num);
	printf("이름 : %s\n", st.name);
	printf("학번 : %d\n", st.std_id);
	printf("나이 : %d\n", st.age);
	printf("전공과목 : %s\n", st.major);
	printf("전화번호 : %s\n", st.tel);
	printf("주소 : %s\n", st.addr);
	printf("이메일 : %s\n", st.email);
	printf("\n\n");
}




STUDENT displayUpdateFrom(STUDENT upSt)
{
	printf("===========================================================================================");
	printf("학생 정보\n");
	printf("이름 : %s\n", upSt.name);
	printf("학번 : %d\n", upSt.std_id);
	printf("나이 : %d\n", upSt.age);
	printf("전공과목 : %s\n", upSt.major);
	printf("전화번호 : %s\n", upSt.tel);
	printf("주소 : %s\n", upSt.addr);
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

	printf("나이를 입력하세요. ");
	scanf("%s", chInput);
	if (strcmp("/no", chInput) != 0)
	{
		int num = atoi(chInput);
		upSt.age = num;
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

	printf("주소를 입력하세요. ");
	getchar();
	gets_s(chInput, sizeof(char) * 40);

	if (strcmp("/no", chInput) != 0)
	{
		strcpy(upSt.addr, chInput);
	}

	printf("이메일을 입력하세요 ");
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
		printf("이름 : ");
		scanf("%s", st.name);

		printf("학번 : ");
		scanf("%d", &st.std_id);
		

		printf("나이 : ");
		scanf("%d", &st.age);
		

		printf("전공과목 : ");
		scanf("%s", st.major);
	

		printf("전화번호 : ");
		scanf("%s", st.tel);
	

		printf("주소 : ");
		getchar();
		gets_s(st.addr, sizeof(char) * 40);
		

		printf("이메일 : ");
		scanf("%s", st.email);
	




		if (stdWrite(st) != NULL)
		{
			printf("학생정보가 성공적으로 저장되었습니다.\n");//파일이 성공적으로 생성
		}
		else
		{
			printf("학생정보 등록에 실패하였습니다.\n");//파일 생성이 실패
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
		printf("학생 목록이 존재하지 않습니다.");
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
	printf("삭제할 학생 이름을 입력하세요.");
	scanf("%s", &delName);

	int index = stdRead(stArr);
	
	int delIndex = 0;
	int exceNum;

	
	int foundIndex = searchStd(stArr, chk, index, delName); // 입력한 이름과 파일에서 불러온 같으면 배열에 저장
	if (foundIndex == 0)
	{
		printf("삭제할 학생이 존재하지 않습니다.\n");//이름을 찾은게 없으면 종료
		return;
	}
	int num = 1;
	if (foundIndex >= 2)//같은 이름이 2개 있을경우 삭제할 이름의 번호를 입력받아 삭제
	{
		printf("동명인의 학생이 있습니다.\n");
		
		for (int i = 0; i < foundIndex; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", chk[i].std.name);
			printf("학번 : %d\n", chk[i].std.std_id);
			printf("나이 : %d\n", chk[i].std.age);
			printf("전공과목 : %s\n", chk[i].std.major);
			printf("전화번호 : %s\n", chk[i].std.tel);
			printf("주소 : %s\n", chk[i].std.addr);
			printf("이메일 : %s\n", chk[i].std.email);
			printf("\n\n");
			num++;
		}

		printf("삭제할 학생의 번호를 입력해주세요.");
		scanf("%d", &num);

		exceNum = chk[num - 1].index;//학생배열에서 삭제된 위치는 제외할 변수

	}

	else
	{
		exceNum = chk[num - 1].index;//학생배열에서 삭제된 위치는 제외할 변수
	}

	
	
	for (int i = 0; i < index; i++)
	{
		if(i != exceNum)//
		{
			delArr[delIndex] = stArr[i];//삭제하는 데이터가 아닌경우 데이터 갱신
			delIndex++;
		}
	}
	stdFileUpdate(delArr, delIndex);
	printf("%s 학생을 삭제하였습니다.\n", delName);
}


//void DelStd()
//{
//	STUDENT stArr[100];
//	STUDENT delArr[100];
//	STUDENT foundArr[100];
//	char delName[20];
//	int dataNumArr[100];
//
//	printf("삭제할 학생 이름을 입력하세요.");
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
//		printf("동명인의 학생이 있습니다.");
//
//		for (int i = 0; i < foundIndex; i++)
//		{
//			printf("번호 : %d\n\n", num);
//			printf("이름 : %s\n", foundArr[i].name);
//			printf("학번 : %d\n", foundArr[i].std_id);
//			printf("나이 : %d\n", foundArr[i].age);
//			printf("전공과목 : %s\n", foundArr[i].major);
//			printf("전화번호 : %s\n", foundArr[i].tel);
//			printf("주소 : %s\n", foundArr[i].addr);
//			printf("이메일 : %s\n", foundArr[i].email);
//			printf("\n\n");
//			num++;
//		}
//
//		printf("삭제할 학생의 번호를 입력해주세요.");
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
//	printf("삭제할 학생 이름을 입력하세요.");
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
	printf("수정할 학생의 이름을 입력해주세요.");
	scanf("%s", upName);
	int index = stdRead(stArr);//학생데이터 총 갯수
	int num = 1;
	int foundIdx = searchStd(stArr, che, index, upName);//수정할 학생을 검색하여 배열에 담음
	if (foundIdx == 0)
	{
		printf("수정할 학생이 존재하지 않습니다.\n");
		return;
	}
	int finNum;

	

	if (foundIdx >= 2)
	{
		printf("\n");
		printf("동명인의 학생을 발견하였습니다.\n\n");
		
		for (int i = 0; i < foundIdx; i++)
		{
			printf("번호 : %d\n\n", num);
			printf("이름 : %s\n", che[i].std.name);
			printf("학번 : %d\n", che[i].std.std_id);
			printf("나이 : %d\n", che[i].std.age);
			printf("전공과목 : %s\n", che[i].std.major);
			printf("전화번호 : %s\n", che[i].std.tel);
			printf("주소 : %s\n", che[i].std.addr);
			printf("이메일 : %s\n", che[i].std.email);
			printf("\n\n");
			num++;
		}

		
		printf("수정할 학생의 번호를 입력해주세요. ");
		
		scanf("%d", &num);

		upSt   = che[num - 1].std;
		finNum = che[num - 1].index; //학생배열 최종 위치를 넘겨받음

		printf("%d번 학생을 선택하셨습니다.",  num);
		
	}

	else
	{
		upSt = che[num - 1].std;
		finNum = che[num - 1].index;//학생배열 최종 위치를 넘겨받음
	}

	upSt = displayUpdateFrom(upSt);//데이터 수정을 위한 입력란
	stArr[finNum] = upSt; //수정한 데이터를 학생데이터 배열에 덮어 씌움
	stdFileUpdate(stArr, index);//업데이트한 데이터를 적용
	printf("%s학생 수정을 완료하였습니다.\n", upName);
	
	printf("");
	
}



void SearchStd()
{
	STUDENT stArr[100];
	char seaName[20];
	int index = stdRead(stArr);
	int num = 1;
	system("cls");
	printf("검색할 학생의 이름을 입력하세요.");
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
		printf("학생이 존재하지 않습니다.");
	}

}
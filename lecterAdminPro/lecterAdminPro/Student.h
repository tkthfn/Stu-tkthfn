#include "def.h"
#include <stdio.h>


#ifndef __Student__

	

	

#endif // !__Student__

	
typedef struct _STUDENT
{
	int std_id;
	char name[20];
	int age;
	char major[40];
	char tel[20];
	char addr[70];
	char email[40];

}STUDENT;


	extern void AddStd();//학생 추가
	extern void UpdateStd(char name[20]);//학생 수정
	extern void DelStd(char name[20]);//학생 삭제
	extern void ReadStd();//학생 조회
	extern void SearchStd(char name[20]);//학생 검색
	
	







#include "def.h"
#include <stdio.h>

typedef struct _major {
	char name[40];
	int hackjum;
}MAJOR;



extern void AddMajor();//전공과목 추가
extern void UpdateMajor(char name[20]);//전공과목 수정
extern void DeleteMajor(char name[20]);//전공 과목 삭제
extern void ReadMajor();//전공과목 조회
extern void SearchMajor(char name[20]);
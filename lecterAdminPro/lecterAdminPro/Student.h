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


	extern void AddStd();//�л� �߰�
	extern void UpdateStd(char name[20]);//�л� ����
	extern void DelStd(char name[20]);//�л� ����
	extern void ReadStd();//�л� ��ȸ
	extern void SearchStd(char name[20]);//�л� �˻�
	
	







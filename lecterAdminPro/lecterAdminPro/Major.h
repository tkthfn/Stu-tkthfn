#include "def.h"
#include <stdio.h>

typedef struct _major {
	char name[40];
	int hackjum;
}MAJOR;



extern void AddMajor();//�������� �߰�
extern void UpdateMajor(char name[20]);//�������� ����
extern void DeleteMajor(char name[20]);//���� ���� ����
extern void ReadMajor();//�������� ��ȸ
extern void SearchMajor(char name[20]);
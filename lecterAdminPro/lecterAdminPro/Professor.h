#include "def.h"
#include <stdio.h>

typedef struct _PROFESSOR
{
	char name[20];
	char tel[20];
	char major[40];
	char email[40];

}PROFESSOR;

extern void AddPro();
extern void UpdatePro(char name[20]);
extern void DelPro(char name[20]);
extern void ReadPro();
extern void SearchPro(char name[20]);



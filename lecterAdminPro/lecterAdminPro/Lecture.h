#include "def.h"
#include <stdio.h>
#include "Student.h"
#include "Professor.h"
#include "Major.h"

typedef struct _LECTURE
{
	STUDENT std;
	PROFESSOR pro;
	MAJOR maj[3];
	char date[40];
	char classRoom[30];

}LECT;

extern void AddLect();
extern void UpdateLect(char name[20]);
extern void DelLect(char name[20]);
extern void ReadLect();
extern void SearchLect(char name[20]);
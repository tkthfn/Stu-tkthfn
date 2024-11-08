#include "def.h"
#include <stdio.h>

#define MAX_MENU 6
#define MAX_MENU_MAIN 5



typedef enum {

	MA_STD = 1
   ,MA_PRO
   ,MA_MAJOR
   ,MA_LECT
   ,MA_EXIT

}MAINMENU;


typedef enum {
	ST_ADD = 1
   ,ST_READ
   ,ST_EDIT
   ,ST_DEL
   ,ST_SEARCH
   ,BACK
}STDMENU;



typedef enum {

	PRO_ADD = 1
   ,PRO_READ
   ,PRO_EDIT
   ,PRO_DEL
   ,PRO_SEARCH

}PROMENU;


typedef enum {

	MAJO_ADD = 1
   ,MAJO_READ
   ,MAJO_EDIT
   ,MAJO_DEL
   ,MAJO_SEARCH

}MAJO;


typedef enum {

	LECT_ADD = 1
   ,LECT_READ
   ,LECT_EDIT
   ,LECT_DEL
   ,LECT_SEARCH

}LECT;



extern void GoToStd();
extern void GoToPro();
extern void GotoMajo();
extern void GoToLect();
extern void mainMenu();
extern void selectMenu(int* select);
extern void selectStdMenu(int* select);
extern void selectProMenu(int* select);
extern void selectMajoMenu(int* select);
extern void selectLectMenu(int* select);



extern void drawingMainMenu(int select);
extern void drawingStdMenu(int select);
extern void drawingProMenu(int select);
extern void drawingLectMenu(int select);


extern void paintMenu(int select);
extern void paintStdMenu(int select);
extern void paintProMenu(int select);
extern void paintMajoMenu(int select);
extern void paintLectMenu(int select);

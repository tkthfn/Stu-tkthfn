#include "def.h"
#include <stdio.h>

#ifndef  __CUI_H__
#define  __CUI_H__

typedef enum {
	NOCURSOR
   ,SOLID_CURSOR
   ,NORMAL_CURSOR
};


typedef enum {
	  BLACK
	, BLUE
	, GREEN
	, CYAN
	, RED
	, PURPLE
	, YELLOW
	, WHITE
	, GRAY
	, LIGHT_BLUE
	, LIGHT_GREEN
	, LIGHT_CYAN
	, LIGHT_RED
	, LIGHT_PURPLE
	, LIGHT_YELLOW
	, LIGHT_GRAY
}FONT_COLOR;




#endif // ! __CUI_H__

extern void DrawingFristScreen(FONT_COLOR color);
extern void GotoXY(int x, int y);
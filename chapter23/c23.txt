#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point point;
struct Point{
	int xpos;
	int ypos;
};

typedef struct Rectangle rectangle;
struct Rectangle{
	point pos1;	// north west
	point pos2;	// south east
};

void q1(void);
void changepoint(point*, point*);

void q2(void);
void areasize(rectangle);
void otherrecpos(rectangle);

int main(int argc, char *argv[]){

	int nMainQuest = 0;

	if (argc != 2 || *argv[1] < '0' || *argv[1] > '9'){
		printf("enter question number : ");
		scanf("%d", &nMainQuest);
		getchar();
	}
	else{
		nMainQuest = atoi(argv[1]);
	}

	switch (nMainQuest)
	{
	case 1:
		q1();
		break;

	case 2:
		q2();
		break;

	default:
		break;
	}

	return 0;
}	// end of main

void q1(void){
	point pos1 = { 2, 4 };
	point pos2 = { 5, 7 };
	point *ptr1 = &pos1;
	point *ptr2 = &pos2;

	printf("X1 : %d, Y1 : %d\n", pos1.xpos, pos1.ypos);
	printf("X2 : %d, Y2 : %d\n", pos2.xpos, pos2.ypos);
	printf("\n");

	changepoint(ptr1, ptr2);

	printf("X1 : %d, Y1 : %d\n", pos1.xpos, pos1.ypos);
	printf("X2 : %d, Y2 : %d\n", pos2.xpos, pos2.ypos);
	printf("\n");
}	// end of q1

void changepoint(point *point1, point *point2){
	point temp = { (*point1).xpos, (*point1).ypos };	// init

	(*point1).xpos = (*point2).xpos;
	(*point1).ypos = (*point2).ypos;
	
	(*point2).xpos = temp.xpos;
	(*point2).ypos = temp.ypos;
}

void q2(void){
	// init
	rectangle recpos;
	memset(&recpos, 0, sizeof(recpos));
	do{
		printf("enter 1st position (X & Y) (0 ~ 100) : \n");
		scanf("%d %d", &recpos.pos1.xpos, &recpos.pos1.ypos);
	} while (0 > recpos.pos1.xpos || recpos.pos1.xpos > 100 || 0 > recpos.pos1.ypos || recpos.pos1.ypos > 100);
	do{
		printf("enter 2nd position (X & Y) (0 ~ 100) : \n");
		scanf("%d %d", &recpos.pos2.xpos, &recpos.pos2.ypos);
	} while (0 > recpos.pos2.xpos || recpos.pos2.xpos > 100 || 0 > recpos.pos2.ypos || recpos.pos2.ypos > 100);

	areasize(recpos);
	otherrecpos(recpos);
}	// end of q2

void areasize(rectangle recpos){
	int xlen = 0, ylen = 0;	// init
	int areasize = 0;

	if (recpos.pos1.xpos - recpos.pos2.xpos > 0){	// If sign is plus,
		xlen = recpos.pos1.xpos - recpos.pos2.xpos;	// do not change sign.
	}
	else{
		xlen = recpos.pos2.xpos - recpos.pos1.xpos;	// change sign
	}

	if (recpos.pos1.ypos - recpos.pos2.ypos > 0){	// If sign is plus,
		ylen = recpos.pos1.ypos - recpos.pos2.ypos;	// do not change sign.
	}
	else{
		ylen = recpos.pos2.ypos - recpos.pos1.ypos;	// change sign
	}

	areasize = xlen * ylen;	// calc areasize
	printf("Size : %d\n", areasize);	// print areasize
}	// end of areasize

void otherrecpos(rectangle recpos){
	rectangle recpos2;	// init

	recpos2.pos1.xpos = recpos.pos2.xpos;	// set pos
	recpos2.pos1.ypos = recpos.pos1.ypos;	// set pos
	recpos2.pos2.xpos = recpos.pos1.xpos;	// set pos
	recpos2.pos2.ypos = recpos.pos2.ypos;	// set pos

	printf("X1 : %2d, Y1 : %2d\n", recpos2.pos1.xpos, recpos2.pos1.ypos);	// print pos1
	printf("X2 : %2d, Y2 : %2d\n", recpos2.pos2.xpos, recpos2.pos2.ypos);	// print pos2
}	// end of otherrecpos
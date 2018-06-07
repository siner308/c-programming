#include <stdio.h>
#include <stdlib.h>

#define BUF_MAX 1000

void q0(void);
void q1(void);
void q1_1(void);
void q1_2(void);
void q1_3(void);
void q2(void);



int main(int argc, char *argv[]){
	int nMainQuest = 0;

	if (argc != 2 || *argv[1] < '0' || *argv[1] > '2'){
		printf("enter question number ( 1 ~ 2 ): ");
		scanf("%d", &nMainQuest);
		getchar();
	}
	else{
		nMainQuest = atoi(argv[1]);
	}

	switch (nMainQuest)
	{
	case 0:
		q0();
		break;

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
}

void q0(void){
	FILE *read = fopen("trance.mp3", "rb");
	FILE *write = fopen("copy.mp3", "wb");
	char buf[BUF_MAX];
	int readCnt;

	if (read == NULL || write == NULL){
		puts("open failed");
	}

	while (1){
		readCnt = fread((void*)buf, 1, sizeof(buf), read);

		if (readCnt < sizeof(buf)){
			if (feof(read) != 0){
				fwrite((void*)buf, 1, readCnt, write);
				puts("copy completed");
				break;
			}
			else{
				puts("copy failed");
			}
	
			break;
		}

		fwrite((void*)buf, 1, sizeof(buf), write);
	}

	fclose(read);
	fclose(write);
}

void q1(void){
	int nSubQuest = 1;	// init subquestion number

	while (nSubQuest){
		printf("enter sub question number ( 0 to quit ) : ");
		scanf("%d", &nSubQuest);	// enter subquestion number
		if (nSubQuest < 0 || nSubQuest > 3){
			printf("enter appropriate number\n");
			continue;
		}

		switch (nSubQuest)
		{
		case 1:
			q1_1();
			break;

		case 2:
			q1_2();
			break;

		case 3:
			q1_3();
			break;

		default:
			break;
		}
	}
}

void q1_1(void){
	FILE *mystory = fopen("mystory.txt", "w");	// open stream

	fputs("#Name     : Siner\n", mystory);
	fputs("#ID       : 920308-1234567\n", mystory);
	fputs("#Phone    : 010-1234-5678\n", mystory);

	fclose(mystory);	// close stream
	printf("complete!\n");
}	// end of q1

void q1_2(void){
	FILE *mystory = fopen("mystory.txt", "a");	// open stream

	fputs("#Fav food : Pizza\n", mystory);
	fputs("#Hobby    : Game\n", mystory);

	fclose(mystory);	// close stream
	printf("complete!\n");
}	// end of q1_2

void q1_3(void){
	char chStory = 0;	// init

	FILE *mystory = fopen("mystory.txt", "r");	// open stream

	while (1){
		chStory = fgetc(mystory);	// Get char from mystory
		if (chStory == EOF){	// If chStory meet EOF, break.
			break;
		}

		putchar(chStory);
	}

	fclose(mystory);
}

void q2(void){
	int fpos = 0;	// init

	FILE *test = fopen("test.txt", "r");	// open stream
	fseek(test, -1, SEEK_END);	// seek final word
	fpos = ftell(test);	// set position
	printf("File Size : %2d Byte\n", fpos + 1);	// print position and plus one (because this number starts from 0)
	fseek(test, 0, SEEK_SET);	// seek origin position and set
	fclose(test);	// close stream
}	// end of q2
#include <stdio.h>
#include <stdlib.h>

#define BUF_MAX 1000

void q2(void);
void q2_1(void);
char *setstr(void);
void q2_2(void);
int *setnum(void);
//void itoa(int, char[]);

int main(int argc, char *argv[]){
	int nMainQuest = 0;

	if (argc != 2 || *argv[1] > '9' || *argv[1] < '0'){
		printf("enter main question number : ");
		scanf("%d", &nMainQuest);
		getchar();
	}
	else{
		nMainQuest = atoi(argv[1]);
	}

	switch (nMainQuest)
	{
	case 1:
		printf("This is not a coding question.");
		break;

	case 2:
		q2();
		break;

	default:
		break;
	}
	
	
	return 0;
}	// end of main

void q2(void){
	int nSubQuest = 1;

	while (nSubQuest != 0){

		printf("enter sub question number : ");
		scanf("%d", &nSubQuest);

		switch (nSubQuest)
		{
		case 1:
			q2_1();
			break;
		
		case 2:
			q2_2();
			break;

		default:
			break;
		}
	}
}

void q2_1(void){
	// init
	char *str;
	int nCntChar = 0;
	int i = 0, j = 0;

	str = setstr();	// get string
	
	for (i = 9; i >= 0; i--){	// Until meet blank,

		nCntChar++;

		if (str[i] == ' '){	// If you meet blank,
			for (j = 0; j < nCntChar - 1; j++){
				printf("%c", str[i + j + 1]);	// print characters before you met.
			}

			printf(" ");
			nCntChar = 0;
		}

		if (i == 0){
			for (j = 0; j < nCntChar; j++){
				printf("%c", str[i + j]);	// print characters before you met.
			}
			printf(" ");
		}
	}
}	// end of q2

char *setstr(void){
	char *str = (char *)malloc(sizeof(char) * 10);	// init

	printf("enter 'ten characters'\n");
	gets(str);
	free(str);

	return str;
}

void q2_2(void){
	// init
	int *nNum;
	int i = 0;

	nNum = setnum();	// set array from malloc

	while (nNum[i] != -1){	// while meet -1
		printf("%d", nNum[i]);	// print array
		i++;	// next array
	}

	printf("\n");
}

int *setnum(void){
	// init
	int i = 0, j = 0, nLen = 5;
	int *ptr = (int *)malloc(sizeof(int) * nLen);	// init by malloc
	char str[BUF_MAX];
	
	while (1){	// while -1 is entered
		printf("enter number : ");
		scanf("%s", str);	// add character
		getchar();
		j = 0;

		while (1){
			//printf("str[%d] = %c\n", j, str[j]);
			if (str[j] == '\0'){	// If str[j] is NULL, finish checking.
				break;
			}

			if ((str[j] < '-') || ((str[j] > '-') && (str[j] < '0')) || (str[j] > '9')){	// If it is not number or negative sign,
				printf("enter number again : ");
				scanf("%s", str);	// enter again
				getchar();
				j = -1;	// init j (pre subtraction for j++)
			}
		
			j++;
		}
		ptr[i] = atoi(str);	// ASCII to int

		if (ptr[i] == -1){	// If -1 is entered,
			break;	// finish entering
		}

		if (i == nLen - 1){	// if length over
			nLen += 3;	// add 3 length
			ptr = (int *)realloc(ptr, sizeof(int) * nLen);	// add more length
		}

		i++;	// next array
	}

	free(ptr);	// free

	return ptr;
}

//void itoa(int num, char arr[BUF_MAX]){
//	char arrrev[BUF_MAX];
//	int i = 0;
//	int nCnt = 0;
//	int fSign = 1;	// 1 = positive, 0 = negative
//
//	if (num < 0){
//		num *= -1;
//		fSign = 0;
//	}
//
//	while (num > 0){
//		arr[i] = (num % 10) + '0';
//		num = (num - (num % 10)) / 10;
//		i++;
//		nCnt++;
//	}
//	if (fSign = 0){
//		arr[i] = '-';
//	}
//
//	for (i = 0; i < nCnt; i++){
//		arrrev[i] = arr[nCnt - 1 - i];
//	}
//
//	for (i = 0; i < nCnt; i++){
//		arr[i] = arrrev[i];
//	}
//}	// end of itoa
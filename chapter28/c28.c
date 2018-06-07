#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 1000
#define CNT_1 3
#define CNT_2 3

typedef struct Book book;
struct Book{
	char author[BUF_MAX];
	char title[BUF_MAX];
	int page;
};

typedef struct Ptrbook ptrbook;
struct Ptrbook{
	book *info;
};

typedef struct Comnum comnum;
struct Comnum{
	double real;
	double imagine;
};

typedef struct List list;
struct List{
	char name[BUF_MAX];
	char number[BUF_MAX];
};

typedef struct Whitepage whitepage;
struct Whitepage{
	int count;
	list *plist;
};

void q1(void);
void q2(void);
void q3(void);
comnum addcom(comnum, comnum);
comnum multicom(comnum, comnum);
void q4(void);
void q5(void);
void q6(void);
void fInsert(whitepage*);
void fDelete(whitepage*);
void fSearch(whitepage*);
void fPrintAll(whitepage*);
void q7(void);

int main(int argc, char **argv){
	char strMainQuest[BUF_MAX];
	int nMainQuest = 0;

	if (argc != 2 || (*argv[1] < '0' || *argv[1] > '9')){
		while (strMainQuest[0] < '0' || strMainQuest[0] > '9'){
			printf("enter main question number : ");
			scanf("%s", strMainQuest);
			getchar();
		}
		nMainQuest = atoi(strMainQuest);
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

	case 3:
		q3();
		break;

	case 4:
		q4();
		break;

	case 5:
		q5();
		break;

	case 6:
		q6();
		break;

	case 7:
		q7();
		break;

	default:
		break;
	}

	return 0;
}

void q1(void){
	// init
	int i = 0;
	book book[3];
	
	for (i = 0; i < CNT_1; i++){	// enter 3 times
		printf("enter author, title, page (%d)\n", i + 1);
		scanf("%s %s %d", book[i].author, book[i].title, &book[i].page);	// enter book information
	}

	for (i = 0; i < CNT_1; i++){	// print 3 times
		printf("Book %d\n", i);	// book number
		printf("Author : %s\n", book[i].author);
		printf("Title  : %s\n", book[i].title);
		printf("Page   : %d\n", book[i].page);
	}
}

void q2(void){
	// init
	int i = 0;
	book mybook[3];
	ptrbook *pbook = (ptrbook*)malloc(sizeof(ptrbook) * 3);

	for (i = 0; i < CNT_2; i++){	// 0 to 2
		pbook[i].info = &mybook[i];
	}

	// enter info
	for (i = 0; i < CNT_2; i++){	// 0 to 2
		printf("enter author, title, page (%d)\n", i);
		scanf("%s %s %d", (pbook[i].info)->author, (pbook[i].info)->title, &(pbook[i].info)->page);
	}

	// print book
	for (i = 0; i < CNT_2; i++){	// 0 to 2
		printf("Book %d\n", i);
		printf("Author : %s\n", (pbook[i].info)->author);
		printf("Title  : %s\n", (pbook[i].info)->title);
		printf("Page   : %d\n\n", (pbook[i].info)->page);

		free(pbook);
	}
}	// end of q2

void q3(void){
	// init
	int i = 0;
	comnum num[2];
	comnum ret[2];
	
	for (i = 0; i < 2; i++){	// enter 2 complex numbers
		printf("number %d\n", i);
		printf("real    : ");
		scanf("%lf", &num[i].real);
		getchar();
		printf("imagine : ");
		scanf("%lf", &num[i].imagine);
		getchar();
		printf("\n");
	}

	// calc & print
	printf("Addition\n");
	printf("Real    : %g\n", addcom(num[0], num[1]).real);
	printf("Amagine : %g\n\n", addcom(num[0], num[1]).imagine);

	printf("Multiple\n");
	printf("Real    : %g\n", multicom(num[0], num[1]).real);
	printf("Amagine : %g\n\n", multicom(num[0], num[1]).imagine);
}	// end of q3

comnum addcom(comnum num1, comnum num2){
	comnum retVal = { 0, 0 };	// init
	
	// calc
	retVal.real = num1.real + num2.real;
	retVal.imagine = num1.imagine + num2.imagine;

	return retVal;
}	// end of addcom

comnum multicom(comnum num1, comnum num2){
	comnum retVal = { 0, 0 };	// init

	// calc
	retVal.real = (num1.real * num2.real) - (num1.imagine * num2.imagine);
	retVal.imagine = (num1.real * num2.imagine) + (num1.imagine * num2.real);

	return retVal;
}	// end of multicom

void q4(void){
	// init
	char str[BUF_MAX][BUF_MAX];	// words
	char name[BUF_MAX];	// file name
	int i = 0;
	int nCntA = 0, nCntP = 0;	// count check
	FILE *fp;

	printf("enter file name : ");
	scanf("%s", name);	// enter file name

	fp = fopen(name, "r");	// open stream
	
	while (1){
		fscanf(fp, "%s", str[i]);	// read words
		fputs(str[i], stdout);
		printf("\n");
		
		if (str[i][0] == 'a' || str[i][0] == 'A'){	// If first character is A or a,
			nCntA++;	// count up
		}
		
		if (str[i][0] == 'p' || str[i][0] == 'P'){	// If first character is P or p,
			nCntP++;	// count up
		}
		
		if (*str[i] == '\0'){	// If NULL
			break;	// finish repeat
		}

		i++;	// next word
	}

	fclose(fp);	// close stream
	printf("A : %d, P : %d\n", nCntA, nCntP);	// print result
}	// end of q4

void q5(void){
	// init
	char cpytxt[2] = 'a';	// file1,2 character
	char name[2][BUF_MAX];	// file name
	int i = 0;
	FILE *fp[2];

	for (i = 0; i < 2; i++){	// enter file names
		printf("enter file name (%d) : ", i);
		scanf("%s", name[i]);
	}

	for (i = 0; i < 2; i++){
		fp[i] = fopen(name[i], "r");	// HOW TO EXPRESS STREAM NAME BY ARRAY?!
	}

	while (cpytxt[0] == cpytxt[1]){
		for (i = 0; i < 2; i++){
			cpytxt[i] = fgetc(fp[i]);

			if (cpytxt[0] == -1){	// If there is no character to check
				printf("these two files are completely same!!\n");
				break;	// finish checking successfully.
			}

			i++;
		}
	}

	if (cpytxt[0] != cpytxt[1]){
		printf("there is some difference\n");
		printf("test1.txt : %c (%d th)\n", cpytxt[0], cpytxt[0], i);
		printf("test2.txt : %c (%d th)\n", cpytxt[1], cpytxt[1], i);
	}

	fclose(fp[0]);
	fclose(fp[1]);
}	// end of q5

void q6(void){
	char strMenu[BUF_MAX];	// menu string
	int nMenu = 1;	 // menu integer
	list *mylist;
	mylist = (list *)malloc(sizeof(list) * BUF_MAX);	// save whitepage
	whitepage *phonebook = (whitepage *)malloc(sizeof(whitepage) * 1);
	//whitepage *ptr = &phonebook;	// init pointer

	phonebook->count = 0;	// set count to 0
	phonebook->plist = &mylist[BUF_MAX];	// for use this data type in function

	while (nMenu != 5){	// if it is not 5
		do{
			printf("1.Insert / 2.Delete / 3.Search / 4.Print All / 5.Exit\n");
			printf("Choose the item : ");
			scanf("%s", strMenu);	// enter number
			printf("\n");
		} 
		while (strMenu[0] < '1' || strMenu[0] > '5');	// range : 1 to 5

		nMenu = atoi(strMenu);	// atoi
		//printf("Address nMenu   : %d\n", &nMenu);
		//printf("Address strMenu : %d\n", &strMenu);
		
		switch (nMenu)
		{
		case 1:
			fInsert(phonebook);
			break;
		
		case 2:
			fDelete(phonebook);
			break;
		
		case 3:
			fSearch(phonebook);
			break;
		
		case 4:
			fPrintAll(phonebook);
			break;

		default:
			break;
		}
	}

	free(mylist);
	free(phonebook);
}

void fInsert(whitepage *phonebook){	// insert	
	printf("enter name : ");
	scanf("%s", phonebook->plist[phonebook->count].name);	// enter name
	printf("enter number : ");
	scanf("%s", phonebook->plist[phonebook->count].number);	// enter number

	phonebook->count++;	// count up
}	// end of fInsert

void fDelete(whitepage *phonebook){	// delete
	char strname[BUF_MAX];	// init name
	int i = 0, j = 0, k = 0;	// check count
	int fDeleted = 0;

	printf("enter name you want to delete ( 0 to quit ) : ");
	scanf("%s", strname);	// enter name

	while (strname[0] != '0'){	// if name is not '0', find name
		//printf("%s",(phonebook->plist[i]).name);	// print name for check

		while (strname[j] == (phonebook->plist[i]).name[j]){	// check characters
			if (strname[j] == '\0'){
				//printf("these are completely same!\n");

				k = i;

				while (k + 1 != phonebook->count){
					(phonebook->plist[k]) = (phonebook->plist[k + 1]);	// initialize

					//printf("%d : %s\n", k, phonebook->plist[k]);

					//printf("remake list\n");

					k++;
				}

				phonebook->count--;	// count down
				printf("D E L E T E D ! !\n\n");	// print
				fDeleted = 1;	// change flag value
				break;
			}

			j++;	// next charancter
		}

		if (fDeleted == 1){	// if list is deleted, break
			break;
		}
		else{
			i++;	// next array
			if (i > (phonebook->count)){	// if there is no name, break
				printf("there is no name like this\n");
				break;
			}
		}
	}
}	// end of fDelete

void fSearch(whitepage *phonebook){	// search
	char strname[BUF_MAX];	// init 
	int i = 0, j = 0;	// check count
	int fFound = 0;

	printf("enter name you want to search ( 0 to quit ) : ");
	scanf("%s", strname);	// enter name 
	//printf("searching...\n");	// checkpoint
	//printf("%s\n", strname);	// print string for check

	while (strname[0] != '0'){	// name is not '0'
		//printf("%d : ", i);	// print for check
		//printf("%s\n", (phonebook->plist[i]).name);	// print struct for check

		while (strname[j] == (phonebook->plist[i]).name[j]){	// is it same?
			//printf("same\n");	// checking where is flow

			if (strname[j] == '\0'){	// if we meet NULL, print our statement
				//printf("these are completely same!\n");

				printf("Name   : %s\n", (phonebook->plist[i]).name);	// print for check
				printf("Number : %s\n", (phonebook->plist[i]).number);	// print for check

				fFound = 1;	// change flag value
				break;
			}
			j++;	// next character
		}

		if (fFound == 1){	// if we found
			//printf("we found it!\n");	// print for check
			break;
		}
		else{
			i++;	// count up
			if (i + 1 > (phonebook->count)){	// if count is exceeded, break 
				printf("There is no name like this\n");
				break;
			}
		}
	}
}	// end of fSearch

void fPrintAll(whitepage *phonebook){	// print all
	int i = 0;	// print count

	for (i = 0; i < phonebook->count; i++){	// 
		printf("Member ID : %d\n", i + 1);	// print current number in list
		printf("Name      : %s\n", (phonebook->plist[i]).name);	// print name
		printf("Number    : %s\n", (phonebook->plist[i]).number);	// print number
		printf("-----------------------------\n");
	}
	printf("\n");
}	// end of fPrintAll

void q7(void){

}
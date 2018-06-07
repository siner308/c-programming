#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 1000

void q1(void);

void q2(void);

void q2_1(void);

void q2_2(void);
int getLength(char *);

void q2_3(void);
int getNameLength(char *);
int getAge(char *);

int main(int argc, char *argv[]){	// enter main question number

	int nMainQuest = 0;	// argv[1]


	if ((argc != 2) || !(('0' <= *argv[1]) && ('9' < *argv[1]))){	// If argc is not 2 and *argv[1] is not 0 to 9,
		printf("not appropriate parameter, enter correct parameters again\n");
		printf("nMainQuest : ");
		scanf("%d", &nMainQuest);	// Enter correct parameter again.
	}
	else{
		nMainQuest = (int)*argv[1] - '0';	// atoi
	}

	switch (nMainQuest){
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

void q1(void){
	
	int cNum = 0;	// init
	
	printf("Question.1\n");	// question number
	cNum = getchar();	// get cNum

	while (1){
		if ((('A' <= cNum) && (cNum <= 'Z')) || (('a' <= cNum) && (cNum <= 'z'))){	// If it is alphabet,
			break;
		}
		else{
			getchar();
			printf("enter correct alphabet again\n");	// enter again
			cNum = getchar();
		}
	}

	if (cNum <= 'Z'){	// If it is uppercase,
		cNum += 'a' - 'A';	// transform to lowercase
	}
	else if (cNum >= 'a'){	// If it is lowercase,
		cNum -= 'a' - 'A';	// transform to uppercase.
	}

	putchar(cNum);	// put cNum

}	// ent of q1

void q2(void){

	int nSubQuest = 0;	// init

	printf("enter question number");
	printf("Question.2 - ");
	scanf("%d", &nSubQuest);	// enter sub question number

	switch (nSubQuest)
	{
	case 1:
		q2_1();
		break;

	case 2:
		q2_2();
		break;

	case 3:
		q2_3();
		break;

	default:
		break;
	}

}	// end of q2

void q2_1(void){

	// init
	char arrStr[BUF_MAX];
	int szStr = 0;
	int i = 0;
	int nTotal = 0;

	getchar();
	printf("enter anything\n");
	fgets(arrStr, BUF_MAX, stdin);	// enter string

	while (arrStr[i] != '\0'){	// Until reach NULL, 
		if (('0' <= arrStr[i]) && (arrStr[i] <= '9')){	// If it is number,
			nTotal += arrStr[i] - '0'; // atoi and add it to nTotal.
		}

		i++;	// next arr
	}

	printf("%d", nTotal);	// print total number


}	// end of q2_1

void q2_2(void){

	// init
	char str1[BUF_MAX];
	char str2[BUF_MAX];
	char str3[BUF_MAX];

	int i = 0;
	int lenstr1 = 0, lenstr2 = 0;

	fputs("enter str1\n", stdout);
	getchar();	// renove \n
	fgets(str1, BUF_MAX, stdin);	// enter string to str1

	lenstr1 = getLength(str1);	// get length

	strncpy(str3, str1, lenstr1);	// copy str1 to str3
	str3[lenstr1] = '\0';	// set null
	
	fputs("\nenter str2\n", stdout);
	//getchar();	// remove first char of str2
	fgets(str2, BUF_MAX, stdin);	// enter string to str2

	lenstr2 = getLength(str2);	// get length

	strncat(str3, str2, lenstr2);	// copy str2 to str3

	printf("\n\nresult : ");
	fputs(str3, stdout);	// print str3

	printf("\n\n");

}	// end of q2_2

int getLength(char arr[BUF_MAX]){

	// init
	int lenarr = 0;
	int i = 0;

	while (arr[i] != '\n'){	// get length
		i++;
		lenarr = i;
	}

	return lenarr;

	// end of getlength
}

void q2_3(void){

	// init
	char str[3][BUF_MAX];
	char name[3][BUF_MAX];
	char strAge[3][BUF_MAX];

	int lenName[3];
	int nAge[3];

	printf("1st (name, age)\n");
	getchar();
	fgets(str[0], BUF_MAX, stdin);	// enter string to str1

	printf("2nd (name, age)\n");
	fgets(str[1], BUF_MAX, stdin);	// enter string to str2

	printf("3rd (name, age)\n");
	fgets(str[2], BUF_MAX, stdin);	// enter string to str3

	printf("\n");

	lenName[0] = getNameLength(str[0]);	// get name length to copy
	lenName[1] = getNameLength(str[1]);	// get name length to copy
	lenName[2] = getNameLength(str[2]);	// get name length to copy

	strncpy(name[0], str[0], lenName[0]);	// copy name to other arr
	strncpy(name[1], str[1], lenName[1]);	// copy name to other arr
	strncpy(name[2], str[2], lenName[2]);	// copy name to other arr

	nAge[0] = getAge(str[0]);	// get age1 from str1
	nAge[1] = getAge(str[1]);	// get age2 from str2
	nAge[2] = getAge(str[2]);	// get age3 from str3

	// check name
	if (strcmp(name[0], name[1]) == 0){	// If these are same string,
		fputs("1 and 2 have same name.\n", stdout);	// print this.
	}
	else{	// If these are not same string,
		fputs("1 and 2 have different name.\n", stdout);	// print this.
	}

	if (strcmp(name[1], name[2]) == 0){	// If these are same string,
		fputs("2 and 3 have same name.\n", stdout);	// print this.
	}
	else{	// If these are not same string,
		fputs("2 and 3 have different name.\n", stdout);	// print this.
	}

	if (strcmp(name[2], name[0]) == 0){	// If these are same string,
		fputs("3 and 1 have same name.\n", stdout);	// print this.
	}
	else{	// If these are not same string,
		fputs("3 and 1 have different name.\n", stdout);	// print this.
	}


	// check age
	if (nAge[0] == nAge[1]){	// If these are same int,
		fputs("1 and 2 have same age.\n", stdout);	// print this.
	}
	else{	// If these are not same int,
		fputs("1 and 2 have different age.\n", stdout);	// print this.
	}

	if (nAge[1] == nAge[2]){	// If these are same int,
		fputs("2 and 3 have same age.\n", stdout);	// print this.
	}
	else{	// If these are not same int,
		fputs("2 and 3 have different age.\n", stdout);	// print this.
	}

	if (nAge[2] == nAge[0]){	// If these are same int,
		fputs("3 and 1 have same age.\n", stdout);	// print this.
	}
	else{	// If these are not same int,
		fputs("3 and 1 have different age.\n", stdout);	// print this.
	}

}	// end of q2_3

int getNameLength(char arr[BUF_MAX]){

	// init
	int i = 0;
	int nLength;

	while (arr[i] != ' '){	// find blank (between name & age)
		i++;
		nLength = i;
	}

	return nLength;

	// end of getNameLength
}

int getAge(char arr[BUF_MAX]){
	
	// init
	char strAge[BUF_MAX];

	int i = 0, j = 0;
	int nNameLength = 0;
	int nAgeLength = 0;
	int nAge = 0;

	while (arr[i] != ' '){	// find blank (between name & age)
		i++;
		nNameLength = i;
	}

	while (arr[i] != '\n'){	// find enter (end of age)
		i++;
		nAgeLength = i;
	}

	for (i = nNameLength + 1; i < nAgeLength; i++){	// make age-string from total-string
		strAge[j] = arr[i];
		j++;
	}

	nAge = atoi(strAge);	// atoi

	return nAge;

}	// end of getAge
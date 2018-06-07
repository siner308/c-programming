#include <stdio.h>
#include <stdlib.h>

#define BUF_MAX 1000
#define CNT_2 3

typedef struct Employee employee;
struct Employee{
	char name[BUF_MAX];
	char id[BUF_MAX];
	int wage;
};

void q1(void);
void removen(char*);

void q2(void);

int main(int argc, char *argv[]){
	int nQuest = 0;	// init
	
	if (argc != 2 || (*argv[1] < '0' || '9' < *argv[1])){
		printf("enter question number : ");
		scanf("%d", &nQuest);
		getchar();	// remove \n
	}
	else{
		nQuest = atoi(argv[1]);
	}

	switch (nQuest)
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
	employee siner; // init

	printf("enter name : ");
	fgets(siner.name, BUF_MAX, stdin);	// enter string
	removen(siner.name);	// remove \n from siner.name

	printf("enter id   : ");
	fgets(siner.id, BUF_MAX, stdin);	// enter string
	removen(siner.id);	// remove \n from siner.id

	printf("enter wage : ");
	scanf("%d", &siner.wage);	// enter number
	
	printf("\n");
	
	printf("Name : %s\n", siner.name);	// print
	printf("ID   : %s\n", siner.id);	// print
	printf("wage : %d\n\n", siner.wage);	// print
}	// end of q1

void removen(char arr[]){
	int i = 0;

	while (1){
		if (arr[i] == '\n'){
			arr[i] = '\0';	
			break;
		}

		i++;
	}
}	// end of removen

void q2(void){
	// init
	int i = 0;
	employee arr[3];

	for (i = 0; i < CNT_2; i++){	// CNT_1 = 3
		printf("enter name : ");
		fgets(arr[i].name, BUF_MAX, stdin);
		removen(arr[i].name);	// remove \n from arr[i].name
		
		printf("enter id   : ");
		fgets(arr[i].id, BUF_MAX, stdin);
		removen(arr[i].id);	// remove \n from arr[i].id
		
		printf("enter wage : ");
		scanf("%d", &arr[i].wage);

		getchar();	// remove \n
	}

	for (i = 0; i < CNT_2; i++){	// CNT_1 = 3
		printf("Name : %s\n", arr[i].name);	// print name
		printf("ID   : %s\n", arr[i].id);	// print id
		printf("wage : %d\n", arr[i].wage);	// print 
		printf("\n");
	}
}	// end of q2
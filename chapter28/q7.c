#include <stdio.h>
#include <string.h>	// strdup
#include <stdlib.h>	// malloc

#define BUF_MAX 1000

typedef struct Node node;
struct Node{
	char *name;
	char *number;
	node *next;
};

// declare function
void init(void);
void file_init(void);
void insert(char*, char*);
void delete(char*);
void search(char*);
void print_all(void);
void free_all(void);

// madder said these are dummy
node *head;
node *tail;
FILE *fp;

int main(void){
	int nMenu = 0;	// init
	char name[BUF_MAX];
	char number[BUF_MAX];

	// initialization
	init();
	file_init();

	// select menu
	while (1){
		printf("1.insert 2.delete 3.search 4.print_all 5.exit\n");
		scanf("%d", &nMenu);

		if (nMenu == 1){
			// enter name & number
			printf("enter name   : ");
			scanf("%s", name);
			printf("enter number : ");
			scanf("%s", number);

			insert(name, number);
		}

		else if (nMenu == 2){
			// enter name
			printf("enter name   : ");
			scanf("%s", name);

			delete(name);
		}

		else if (nMenu == 3){
			// enter name
			printf("enter name   : ");
			scanf("%s", name);

			search(name);
		}

		else if (nMenu == 4){
			print_all();
		}

		else if (nMenu == 5){
			free_all();
			return 0;
		}

		else{

		}
	}
}

void init(){
	// dynamic allocation
	head = (node *)malloc(sizeof(node));
	tail = (node *)malloc(sizeof(node));

	// init
	head->name = NULL;
	head->number = NULL;

	tail->name = NULL;
	tail->number = NULL;

	head->next = tail;
	tail->next = NULL;
}

void file_init(){
	char name[BUF_MAX];
	char number[BUF_MAX];

	fp = fopen("q7.txt", "r");
	
	if (fp == NULL){
		printf("there is no saved data\n");
	}

	else{
		printf("there is saved data\n");	

		while (!feof(fp)){
			fscanf(fp, "%s %s\n", name, number);	// bring name & number from txt
			insert(name, number);	// insert
		}

		fclose(fp);	// close stream
	}
}

void insert(char *name, char *number){
	// declaration
	node *temp_head;
	node *new;

	temp_head = head;	// init

	// dynamic allocation
	new = (node *)malloc(sizeof(node));

	// set name & number
	new->name = strdup(name);
	new->number = strdup(number);

	//if (temp_head->next == tail){	// if tail,		
	//	// insert between temp_head & temp_head->next
	//	new->next = temp_head->next;
	//	temp_head->next = new;
	//}
	//
	//else{	// if not tail, insert	
	//	while (strcmp(new->name, temp_head->next->name) > 0){	// while find right position,
	//		temp_head = temp_head->next;	// go to next list
	//
	//		if (temp_head->next == tail){	// if end of list, break
	//			break;
	//		}
	//	}
	//
	//	// insert
	//	new->next = temp_head->next;
	//	temp_head->next = new;
	//}

	// Lee
	while (temp_head->next != tail) {
		if (strcmp(new->name, temp_head->next->name) < 0) {
			new->next = temp_head->next;
			temp_head->next = new;
			break;
		}

		temp_head = temp_head->next;
	}

	// exception handling
	// if this is first input or new node should be placed at last
	if (temp_head->next == tail) {
		new->next = temp_head->next;
		temp_head->next = new;
	}



}	// end of insert

void delete(char *name){
	node *temp_head;
	node *temp;

	temp_head = head;	// init
	
	while (temp_head->next != tail){	// while not tail
		if (strcmp(temp_head->next->name, name) == 0){	// if find right name
			temp = temp_head->next;	// separate node
			break;
		}

		else{
			temp_head = temp_head->next;	// go to next list
		}
	}

	if (temp_head->next == tail){	// if tail,
		printf("there is no %s\n", name);	// there is no name what we wanted to find
	}

	else{
		temp_head->next = temp_head->next->next;	// re-link
		free(temp);	// free
		printf("deleted!\n");
	}
}	// end of delete

void search(char *name){
	node *temp_head;	// declaration

	temp_head = head;	// init

	while (temp_head->next != tail){	// while not tail
		if (strcmp(temp_head->next->name, name) == 0){	// if we find right name,
			break;
		}

		else{	// if we didn't find right name,
			temp_head = temp_head->next;	// go to next list & keep finding
		}
	}

	if (temp_head->next == tail){	// if tail,
		printf("there is no %s\n", name);	// there is no name what we wanted to find
	}

	else{	// if we found name before we reached tail, print name & number
		printf("Name\t: %s\n", temp_head->next->name);
		printf("Number\t: %s\n\n", temp_head->next->number);
	}

}	// end of search

void print_all(void){
	node *temp_head;	// declaration

	temp_head = head;	// init
	
	while (temp_head->next != tail){	// while not tail, print name & number countinuously
		printf("Name\t: %s\n", temp_head->next->name);
		printf("Number\t: %s\n\n", temp_head->next->number);

		temp_head = temp_head->next;	// go to next list
	}

}	// end of print_all

void free_all(void){
	node *temp_head;	// declaration

	temp_head = head;	// init
	
	remove("q7.txt");	// delete file
	fp = fopen("q7.txt", "w");	// and remake

	//fseek(fp, 0, SEEK_SET);	// set position to 0 for rewrite

	while (temp_head->next != tail){	// while not reach to tail
		fputs(temp_head->next->name, fp);	// put name
		fputc(' ', fp);	// put blank between name & number
		fputs(temp_head->next->number, fp);	// put number
		fputc('\n', fp);	// put enter between lists

		temp_head = temp_head->next;	// go to next list
	}

	fclose(fp);	// if we reached tail, close stream
}	// end of exit
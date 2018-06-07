#include <stdio.h>
#include <string.h>	// strdup
#include <stdlib.h>	// malloc

#define BUF_MAX 1000

typedef struct node node;
struct node{
	char *name;
	char *number;
	node *after;
};

// declare function
void init(void);
void sort(void);
void insert(char*, char*);
void delete(char*);
void search(char*);
void print_all(void);
void free_all(void);

// madder said these are dummy
node *head;
node *tail;

int main(int argc, char **argv){
	int nMenu = 0;	// init
	char name[BUF_MAX];
	char number[BUF_MAX];

	// initialization
	init();

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

	head->after = tail;
	tail->after = NULL;
}

void insert(char* name, char* number){
	// declaration
	node *new;
	// dynamic allocation
	new = (node *)malloc(sizeof(node));

	// init
	new->after = head->after;
	head->after = new;

	new->name = strdup(name);
	new->number = strdup(number);

	sort();	// sorting by name
}	// end of insert

void sort(void){
	// declaration
	int fFin = 0;
	node *temp_head;
	node *temp;

	temp_head = head;	// init

	// sorting
	while (temp_head->after->after != tail){
		if (strcmp(temp_head->after->name, temp_head->after->after->name) > 0){	// If we have to sort,
			temp->name = strdup(temp_head->after->name);
			temp->number = strdup(temp_head->after->number);

			temp_head->after->name = strdup(temp_head->after->after->name);
			temp_head->after->number = strdup(temp_head->after->after->number);

			temp_head->after->after->name = strdup(temp->name);
			temp_head->after->after->number = strdup(temp->number);

			temp_head = head;	// reset temp_head

			continue;	// re-sort
		}

		temp_head = temp_head->after;	// go to next list
	}
}

void delete(char* name){
	// declaration
	node *temp;
	node *temp_head;

	temp_head = head;	// init

	while (temp_head->after != tail){
		if (strcmp(temp_head->after->name, name) == 0){	// If we find name to delete
			temp = temp_head->after;	// transfer to temp
			temp_head->after = temp_head->after->after;	// re-link
			break;
		}
		else{
			temp_head = temp_head->after;	// go to next list
		}
	}

	if (temp_head->after == tail){	// If there is no name.
		printf("there is no %s\n", name);
	}
	else{
		printf("delete completed!\n");	// We found the name.
		free(temp);
	}
}	// end of delete

void search(char* name){
	node *temp_head;	// declaration
	temp_head = head;	// init

	while (temp_head->after != tail){
		if (strcmp(temp_head->after->name, name) == 0){	// If we find what we want, print & break.
			printf("name   : %s\n", temp_head->after->name);
			printf("number : %s\n\n", temp_head->after->number);
			break;
		}
		else{
			temp_head = temp_head->after;	// go to next list
		}
	}

	if (temp_head->after == tail){	// we cannot find the name.
		printf("there is no %s", name);
	}
}	// end of search

void print_all(void){
	node *temp_head;	// declaration

	temp_head = head;	// init

	while (temp_head->after != tail){	// If there is list to print, print it.
		printf("name   : %s\n", temp_head->after->name);
		printf("number : %s\n\n", temp_head->after->number);
		temp_head = temp_head->after;	// next list
	}

	if (temp_head->after == tail){	// If there is no one to print, finish it.
		printf("finish!\n");
	}
}	// end of print_all

void free_all(void){
	// declaration
	node *temp_head;	// for searching
	node *temp;	// for free

	temp_head = head;

	while (temp_head->after != tail){	// If there is list to make free,
		temp = temp_head->after;	// set temp to list
		temp_head->after = temp_head->after->after;	// re-link
		free(temp);	// free temp
	}

	if (temp_head->after == tail){	// If there is no list,
		free(head);	// free head
		free(tail);	// free tail
	}
}	// end of exit
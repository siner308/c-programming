#include <stdio.h>
#include <string.h>	// strdup
#include <stdlib.h>	// malloc

#define BUF_MAX 1000

typedef struct node node;
struct node{
	char *name;
	char *number;
	node *prev;
	node *next;
};

// declare function
void init(void);
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

	head->next = tail;
	tail->next = NULL;

	head->prev = NULL;
	tail->prev = head;
}

void insert(char* name, char* number){
	// declaration
	node *temp_head;	// temp_head
	node *new;			// temp_head->next
	node *temp;			// temp_head->next->next
	node *temp_next;	// temp_head->next->next->next

	new = (node *)malloc(sizeof(node));	// dynamic allocation

	temp_head = head;	// init for sort
	temp = head->next;	// init for insert
	
	//	set prev
	temp->prev = new;
	new->prev = head;
	
	// set next
	head->next = new;
	new->next = temp;
	
	// insert
	new->name = strdup(name);
	new->number = strdup(number);

	while (temp_head->next->next != tail){
		if (strcmp(temp_head->next->name, temp_head->next->next->name) > 0){
			// init
			new = temp_head->next;
			temp = temp_head->next->next;
			temp_next = head->next->next->next;

			// set next
			new->next = temp->next;
			temp->next = new;
			temp_head->next = temp;

			// set prev
			temp->prev = temp_head;
			new->prev = temp;
			temp_next->prev = new;

			temp_head = head;	// reset temp_head
		}
		else{
			temp_head = temp_head->next;	// go to next list
		}
	}
}	// end of insert

void delete(char* name){
	// declaration
	node *temp_head;	// temp_head
	node *temp_target;	// temp_head->next		 (target list to delete)
	node *temp_next;	// temp_head->next->next (temp_target->next)

	// init
	temp_head = head;
	temp_next = head->next->next;

	while (1){
		if (temp_head->next != tail){
			if (strcmp(temp_head->next->name, name) == 0){
				temp_target = temp_head->next;	// set new
				temp_head->next = temp_next;	// re-link for next
				temp_next->prev = temp_head;	// re-link for prev

				free(temp_target);
				break;
			}

			else{
				temp_head = temp_head->next;	// go to next list;
				temp_next = temp_next->next;
			}
		}
		else{
			printf("there is no %s\n", name);
			break;
		}
	}
}	// end of delete

void search(char* name){
	node *temp_head;

	temp_head = head;

	while (temp_head->next != tail){
		if (strcmp(temp_head->next->name, name) == 0){	// if we find, print and break
			printf("Name   : %s\n", temp_head->next->name);
			printf("Number : %s\n\n", temp_head->next->number);
			break;
		}
		else{
			temp_head = temp_head->next;	// go to next list
		}
	}

	if (temp_head->next == tail){
		printf("there is no %s\n", name);
	}
}	// end of search

void print_all(void){
	node *temp_head;
	node *temp_tail;

	temp_head = head;
	temp_tail = tail;

	// next-going
	printf("next-going\n");
	while (temp_head->next != tail){
		printf("Name   : %s\n", temp_head->next->name);
		printf("Number : %s\n\n", temp_head->next->number);
		temp_head = temp_head->next;
	}

	// prev-poing
	printf("prev-going\n");
	while (temp_tail->prev != head){
		printf("Name   : %s\n", temp_tail->prev->name);
		printf("Number : %s\n\n", temp_tail->prev->number);
		temp_tail = temp_tail->prev;
	}
}	// end of print_all

void free_all(void){
	node *temp_head;
	node *new;

	temp_head = head;

	while (temp_head->next != tail){
		new = temp_head->next;
		temp_head->next = temp_head->next->next;
		free(new);
	}

	free(head);
	free(tail);
}	// end of free_all
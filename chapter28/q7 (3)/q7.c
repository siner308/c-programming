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
	char strname[BUF_MAX];
	char strnumber[BUF_MAX];
	node *temp_head;
	node *new;
	node *temp;

	fp = fopen("q7.txt", "r");
	
	if (fp == NULL){
		printf("there is no saved data\n");
	}
	else{
		printf("there is saved data\n");
	}
	
	while (!feof(fp)){
		// declaration
		new	= (node *)malloc(sizeof(node));

		// set list
		new->next = head->next;
		head->next = new;

		fscanf(fp, "%s %s\n", strname, strnumber);

		new->name = strdup(strname);
		new->number = strdup(strnumber);
		printf("%s\t%s\n", strname, strnumber);
	}

	fclose(fp);

	printf("check\n");

	// sorting
	temp_head = head;	// init
	while (temp_head->next->next != tail){
		if (strcmp(temp_head->next->name, temp_head->next->next->name) > 0){
			printf("%s, %s\n", temp_head->next->name, temp_head->next->next->name);

			temp->name = temp_head->next->name;
			temp->number = temp_head->next->number;

			temp_head->next->name = temp_head->next->next->name;
			temp_head->next->number = temp_head->next->next->number;
	
			temp_head->next->next->name = temp->name;
			temp_head->next->next->number = temp->number;

			temp_head = head;	// reset temp_head
		}
	
		else{
			temp_head = temp_head->next;	// go to next list
		}

	}	// end of sorting
}

void insert(char *name, char *number){
	// declaration
	node *temp_head;
	node *new;
	node *temp;

	// dynamic allocation
	new = (node *)malloc(sizeof(node));

	// set list
	new->next = head->next;
	head->next = new;

	// set name & number
	new->name = strdup(name);
	new->number = strdup(number);

	// sorting
	temp_head = head;	// init
	while (temp_head->next->next != tail){
		if (strcmp(temp_head->next->name, temp_head->next->next->name) > 0){
			temp->name = temp_head->next->name;
			temp->number = temp_head->next->number;
			
			temp_head->next->name = temp_head->next->next->name;
			temp_head->next->number = temp_head->next->next->number;
			
			temp_head->next->next->name = temp->name;
			temp_head->next->next->number = temp->number;

			temp_head = head;	// reset temp_head
		}

		else{
			temp_head = temp_head->next;	// go to next list
		}

	}	// end of sorting
}	// end of insert

void delete(char *name){
	node *temp_head;
	node *temp;

	temp_head = head;
	
	while (temp_head->next != tail){
		if (strcmp(temp_head->next->name, name) == 0){
			temp = temp_head->next;	// separate
			break;
		}
		else{
			temp_head = temp_head->next;
		}
	}

	if (temp_head->next == tail){
		printf("there is no %s\n", name);
	}
	else{
		temp_head->next = temp_head->next->next;	// re-link
		free(temp);	// free
		printf("deleted!\n");
	}
}	// end of delete

void search(char *name){
	node *temp_head;

	temp_head = head;

	while (temp_head->next != tail){
		if (strcmp(temp_head->next->name, name) == 0){
			break;
		}
		else{
			temp_head = temp_head->next;
		}
	}

	if (temp_head->next == tail){
		printf("there is no %s\n", name);
	}
	else{
		printf("Name\t: %s\n", temp_head->next->name);
		printf("Number\t: %s\n\n", temp_head->next->number);
	}
}	// end of search

void print_all(void){
	// declaration
	node *temp_head;

	temp_head = head;
	
	while (temp_head->next != tail){
		printf("Name\t: %s\n", temp_head->next->name);
		printf("Number\t: %s\n\n", temp_head->next->number);

		temp_head = temp_head->next;
	}

}	// end of print_all

void free_all(void){
	node *temp_head;
	
	remove("q7.txt");	// delete file

	fp = fopen("q7.txt", "w");	// and remake

	temp_head = head;

	fseek(fp, 0, SEEK_SET);

	while (temp_head->next != tail){
		fputs(temp_head->next->name, fp);
		fputc(' ', fp);
		fputs(temp_head->next->number, fp);
		fputc('\n', fp);

		temp_head = temp_head->next;
	}

	fclose(fp);
}	// end of exit
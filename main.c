/*
Nityananda Gohain
School of Engineering, Tezpur University
2016-2020
*/

#include <stdio.h>
//stdlib.h for dynamic memory allocation using malloc
#include <stdlib.h>
//structure.h contains all the structure in the program

#include "listFunctions.h"
#include "mainFunctions.h"


int main(){
	listNode *head=NULL,*current=NULL;
	loadLinkedList(&head,&current);
	int choice;
	
	printf("Welcome to program\n");
	printf("press 1 to enter data\npress 2 to display all data \n press 3 to search data of specific rollno \npress 4 to display rollno");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			input(&head, &current);
			break;
		case 2:
			display();
			break;
		case 3:
			specific(&head);
			break;
		case 4:
			display_rollno(&head);
			break;
	}
	printf("Done\n");
	return 0;
}











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
	printf("WELCOME\n");
	while(1){
		printf("PRESS\n");
		printf("  1  :Enter\n");
		printf("  2  :DISPLAY ALL ENTRIES\n");
		printf("  3  :SEARCH DATA FOR A ROLLNO\n");
		printf("  4  :DISPLAY ALL ROLLNO's\n");
		printf("  5  :EXIT\n\n");
		printf("CHOICE : ");

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
			case 5:
				exit(-1);
		}
	}
	return 0;
}











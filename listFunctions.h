#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void loadLinkedList(listNode **head,listNode **current){
	FILE *f1=fopen("index.idx","r");

    //This variable readData will temporarily read data for making the linked list
	addressDataStruct readData;

    //Check if the file was opened or not
	if(f1 != NULL){

        //Reading procress starts

        //This will read data starting form file pointer f1 and store itin readData
		fread(&readData, sizeof(readData), 1, f1);
		
        while(!feof(f1)){
			
            listNode *tempNode=(listNode*)malloc(sizeof(listNode));
			
            //for the head Node
            if(*head == NULL){
				tempNode->index.rollno = readData.rollno;
				tempNode->index.address = readData.address;
				*head = tempNode;
				tempNode->next=NULL;
				*current=tempNode;
			}
			//since head cannot be used agin so current is used 
            else{
				tempNode->index.rollno = readData.rollno;
				tempNode->index.address = readData.address;
				(*current)->next=tempNode;
				tempNode->next=NULL;
				(*current)=tempNode;
			}
			fread(&readData, sizeof(add), 1, f1);
		}
	}
	fclose(f1);
}

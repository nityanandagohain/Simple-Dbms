#include <stdio.h>
#include <stdlib.h>


//This data structure contains the primary key and the address of the data in the data.csv file
struct addressDataStruct{
	//here rollno is the primary key
	int rollno;
	int address;
};

//This structure is for the linked list
struct listNode{
	struct addressDataStruct index;
	struct listNode* next;	
}; 

// creating alias to remove the hassele of using struct again and again
typedef struct addressDataStruct addressDataStruct;
typedef struct listNode listNode;



void loadLinkedList(listNode **head, listNode **current){
	FILE *f1=fopen("index.idx", "r");

    //This variable readData will temporarily read data for making the linked list
	addressDataStruct readData;

	if (!f1){
		f1=fopen("index.idx", "w");
		if(!f1){
			printf("SYSTEM ERROR");
		}
		fclose(f1);
		f1=fopen("index.idx", "r");
	}



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
		fread(&readData, sizeof(readData), 1, f1);
	}

	fclose(f1);
}



//write the linked list to file
void write_llist(listNode ***head){
	FILE *f1=fopen("index.idx","w");
	addressDataStruct add;
	if(f1!=NULL){
		listNode *temp=**head;
		while(temp!=NULL){
			add.rollno=temp->index.rollno;
			add.address=temp->index.address;
			fwrite(&add, sizeof(add), 1, f1);
			temp=temp->next;
		}
	}
	fclose(f1);
}


//insert in linked list in sorted oredr before writing to file
void insert_llist(listNode ***head,listNode ***current,int roll,int address){
	listNode *temp=(listNode*)malloc(sizeof(listNode));
	listNode *t1=**head;
	temp->index.rollno=roll;
	temp->index.address=address;
	if(**head==NULL){
		**head=temp;
		temp->next=NULL;
		**current=temp;
	}
	else if(roll<((**head)->index.rollno)){
		temp->next=**head;
		**head=temp;
	}
	else if(((**current)->index.rollno)<roll){
		(**current)->next=temp;
		temp->next=NULL;
		**current=temp;
	}
	else{
		while(t1->next!=NULL){
			if(t1->next->index.rollno==roll){
				printf("Already exist\n");
				return;
			}
			if(t1->index.rollno<roll && t1->next->index.rollno>roll){
				temp->next=t1->next;
				t1->next=temp;
				break;
			}
		}
	}
}


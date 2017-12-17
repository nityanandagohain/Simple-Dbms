// This file contains the different structures for our main program


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

//This structure contains tha main data and is the main data structure of our program
struct data{
	char firstName[10];
	char lastNamme[10];
	char email[20];
	char married;
	int age;
	float height;
};

// creating alias to remove the hassele of using struct again and again
typedef struct addressDataStruct addressDataStruct;
typedef struct listNode listNode;
typedef struct data data;
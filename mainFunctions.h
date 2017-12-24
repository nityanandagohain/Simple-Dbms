//This structure contains tha main data and is the main data structure of our program

struct data{
	char firstName[10];
	char lastName[10];
	char email[20];
	char married;
	int age;
	float height;
};

typedef struct data data;



void input(listNode **head,listNode **current){
	int val,roll,ch;
	data s1;
	FILE *f=fopen("csb16022.txt","a");
	fseek(f, 0, SEEK_END);
	if(f!=NULL){
		do{
			printf("ROLL NO : ");
			scanf("%d",&roll);
			val=ftell(f);
			insert_llist(&head, &current, roll, val);
			printf("FIRST NAME : ");
			scanf("%s", s1.firstName);
			printf("LAST NAME : ");
			scanf("%s", s1.lastName);
			printf("EMAIL : ");
			scanf("%s", s1.email);
			printf("MARRIED (Y/N) : ");
			scanf("\n%c", &s1.married);
			printf("HEIGHT : ");
			scanf("%f", &s1.height);
			
			fwrite(&s1,sizeof(s1),1,f);
			printf("coninue (1/0)\n");
			scanf("%d",&ch);
		}while(ch);
	}
	fclose(f);
	write_llist(&head);
}



void display(){
	FILE *f1=fopen("index.idx","r"),*f2=fopen("csb16022.txt","r");
	data s1;
	addressDataStruct ad1;
	if(f1!=NULL && f2!=NULL){
		fread(&ad1,sizeof(ad1),1,f1);
		while(!feof(f1)){
			fseek(f2, ad1.address, SEEK_SET);
			fread(&s1, sizeof(s1), 1, f2);

			printf("ROLL NO : %d\n", ad1.rollno);
			printf("FIRST NAME : %s\n", s1.firstName);
			printf("LAST NAME : %s\n", s1.lastName);
			printf("EMAIL : %s\n", s1.email);
			printf("MARRIED (Y/N) : %c\n", s1.married);
			printf("HEIGHT : %f\n", s1.height);

			fread(&ad1, sizeof(ad1), 1, f1);
		}
	}
	fclose(f1);
	fclose(f2);
}


void specific(listNode **head){
	int rno;
	printf("Enter ROLLNO : ");
	scanf("%d",&rno);
	data s1;
	listNode *temp=*head;
	while(temp!=NULL){
		if(temp->index.rollno==rno){
			FILE *f=fopen("csb16022.txt","r");
			fseek(f,temp->index.address,SEEK_SET);
			fread(&s1,sizeof(s1),1,f);
			printf("ROLL NO : %d\n", rno);
			printf("FIRST NAME : %s\n", s1.firstName);
			printf("LAST NAME : %s\n", s1.lastName);
			printf("EMAIL : %s\n", s1.email);
			printf("MARRIED (Y/N) : %c\n", s1.married);
			printf("HEIGHT : %f\n", s1.height);

			fclose(f);
			return;
		}
		temp=temp->next;
	}
	printf("Data Not present \n");
}


void display_rollno(listNode **head){
	listNode *temp=*head;
	while(temp!=NULL){
		printf("%d\n",temp->index.rollno);
		temp=temp->next;
	}
}


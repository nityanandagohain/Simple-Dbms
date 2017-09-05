#include <stdio.h>
#include <stdlib.h>

struct address
{
	int rollno;
	int val;
};


struct node
{
	struct address index;
	struct node* next;	
}; 


struct student
{
	char fname[20];
	char lname[20];
	int age;
	float height;
	long bank_bal;
	char eyecolor[20];
	int no_of_cars;
	int no_of_cycle;
	char gf[20];
};

void display();
void load_linked_list(struct node **head,struct node **current);
void write_llist(struct node ***head);
void insert_llist(struct node ***head,struct node ***current,int roll,int value);
void input(struct node **head,struct node **current);
void display();
void specific(struct node **head);
void display_rollno(struct node **head);

//main

int main()
{
	struct node *head=NULL,*current=NULL;
	load_linked_list(&head,&current);
	int choice;
	
	printf("Welcome to program\n");
	printf("press 1 to enter data\npress 2 to display all data \n press 3 to search data of specific rollno \npress 4 to display rollno");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			input(&head,&current);
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


//function to load the index file to linked list
void load_linked_list(struct node **head,struct node **current)
{
	FILE *f1=fopen("index.txt","r");
	struct address add;
	if(f1!=NULL)
	{
		fread(&add,sizeof(add),1,f1);
		while(!feof(f1))
		{
			struct node *temp=(struct node *)malloc(sizeof(struct node));
			if(*head==NULL)
			{
				temp->index.rollno=add.rollno;
				temp->index.val=add.val;
				*head=temp;
				temp->next=NULL;
				*current=temp;
			}
			else
			{
				temp->index.rollno=add.rollno;
				temp->index.val=add.val;
				(*current)->next=temp;
				temp->next=NULL;
				(*current)=temp;
			}
			fread(&add,sizeof(add),1,f1);
		}
	}
	fclose(f1);
}

//write the linked list to file
void write_llist(struct node ***head)
{
	FILE *f1=fopen("index.txt","w");
	struct address add;
	if(f1!=NULL)
	{
		struct node *temp=**head;
		while(temp!=NULL)
		{
			add.rollno=temp->index.rollno;
			add.val=temp->index.val;
			fwrite(&add,sizeof(add),1,f1);
			temp=temp->next;
		}
	}
	fclose(f1);
}


//insert in linked list in sorted oredr before writing to file
void insert_llist(struct node ***head,struct node ***current,int roll,int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	struct node *t1=**head;
	temp->index.rollno=roll;
	temp->index.val=value;
	if(**head==NULL)
	{
		**head=temp;
		temp->next=NULL;
		**current=temp;
	}
	else if(roll<((**head)->index.rollno))
	{
		temp->next=**head;
		**head=temp;
	}
	else if(((**current)->index.rollno)<roll)
	{
		(**current)->next=temp;
		temp->next=NULL;
		**current=temp;
	}
	else
	{
		while(t1->next!=NULL)
		{
			if(t1->next->index.rollno==roll)
			{
				printf("Already exist\n");
				return;
			}
			if(t1->index.rollno<roll && t1->next->index.rollno>roll)
			{
				temp->next=t1->next;
				t1->next=temp;
				break;
			}
		}
	}
}


void input(struct node **head,struct node **current)
{
	int val,roll,ch=1;
	struct student s1;
	FILE *f=fopen("csb16022.txt","a+");
	fseek(f,0,SEEK_END);
	if(f!=NULL)
	{
		while(ch==1)
		{
			printf("Enter rollnumber\n");
			scanf("%d",&roll);
			val=ftell(f);
			insert_llist(&head,&current,roll,val);
			printf("Enter first name and last name\n");
			scanf("%s %s",s1.fname,s1.lname);
			printf("Enter age\n");
			scanf("%d",&s1.age);
			printf("height\n");
			scanf("%f",&s1.height);
			printf("Bank balance\n");
			scanf("%ld",&s1.bank_bal);
			printf("Enter eye color\n");
			scanf("%s",s1.eyecolor);
			printf("No of no_of_cars\n");
			scanf("%d",&s1.no_of_cars);
			printf("No of bycycles\n");
			scanf("%d",&s1.no_of_cycle);
			printf("Gf's name\n");
			scanf("%s",s1.gf);



			fwrite(&s1,sizeof(s1),1,f);
			printf("coninue (1/0)\n");
			scanf("%d",&ch);
		}
	}
	fclose(f);
	write_llist(&head);
}

void display()
{
	FILE *f1=fopen("index.txt","r"),*f2=fopen("csb16022.txt","r");
	struct student s1;
	struct address ad1;
	if(f1!=NULL && f2!=NULL)
	{
		fread(&ad1,sizeof(ad1),1,f1);
		while(!feof(f1))
		{
			fseek(f2,ad1.val,SEEK_SET);
			fread(&s1,sizeof(s1),1,f2);
			printf("rollno:%d \nfname:%s \nlname:%s \nage:%d\n",ad1.rollno,s1.fname,s1.lname,s1.age);
			printf("height %f\n",s1.height);
			printf("Bank balance %ld\n",s1.bank_bal);
			printf("Enter eye color %s\n",s1.eyecolor);
			printf("No of no_of_cars %d\n",s1.no_of_cars);
			printf("No of bycycles %d\n",s1.no_of_cycle);
			printf("Gf's name %s\n",s1.gf);


			fread(&ad1,sizeof(ad1),1,f1);
		}
	}
	fclose(f1);
	fclose(f2);
}


void specific(struct node **head)
{
	int rno;
	printf("Enter the rollno\n");
	scanf("%d",&rno);
	struct student s1;
	struct node *temp=*head;
	while(temp!=NULL)
	{
		if(temp->index.rollno==rno)
		{
			FILE *f=fopen("csb16022.txt","r");
			fseek(f,temp->index.val,SEEK_SET);
			fread(&s1,sizeof(s1),1,f);
			printf("fname:%s \nlname:%s \nage:%d\n",s1.fname,s1.lname,s1.age);
			printf("height %f\n",s1.height);
			printf("Bank balance %ld\n",s1.bank_bal);
			printf("Enter eye color %s\n",s1.eyecolor);
			printf("No of no_of_cars %d\n",s1.no_of_cars);
			printf("No of bycycles %d\n",s1.no_of_cycle);
			printf("Gf's name %s\n",s1.gf);
			fclose(f);
			break;
		}
		temp=temp->next;
	}
}
void display_rollno(struct node **head)
{
	struct node *temp=*head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->index.rollno);
		temp=temp->next;
	}
}

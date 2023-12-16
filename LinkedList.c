#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int key;
int item;
struct node
{
	int data;
	struct node *link;
};
struct node *header;
struct node *temp;
struct node *temp1;
struct node *newnode;
void insert_begin()
{	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data \n ");
	scanf("%d",&item);
	if(header==NULL)
	{
		newnode->link=NULL;
		header=newnode;
		newnode->data=item;	
	}
	else
	{
		temp=header;
		newnode->link=temp;
		header=newnode;
		newnode->data=item;
	}
}
void insert_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data \n ");
	scanf("%d",&item);
	newnode->link=NULL;
	newnode->data=item;
	if(header==NULL)
	{
		 printf("List empty");
	}
	else if(header!=NULL)
	{
		temp=header;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newnode;
	}
}

void insert_key()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data \n ");
	scanf("%d",&item);
	newnode->data=item;
	printf("Enter the key");
	scanf("%d",&key);
	temp=header;
	while(temp->link!=NULL&&temp->data!=key)
	{
		temp=temp->link;
	}
	if(temp->link==NULL&&temp->data!=key)
	{
		printf("Key not found");
	}
	newnode->link =temp->link;
	temp->link=newnode;
}
void delete_begin()
{
	
	if(header==NULL)
	{
		printf("List empty");
	}
	else if(header->link==NULL)
	{
		header=NULL;
		printf("List empty");
	}
	else
	{
		temp=header;
		header=temp->link;
		free(temp);
	}

}
void delete_end()
{

	if(header==NULL)
	{
		printf("List empty");
	}
	temp=header;
	while(temp->link!=NULL)
	{
		temp1=temp;
		temp=temp->link;
	}
	temp1->link=NULL;
	free(temp);
}
void delete_key()
{
	printf("Enter the key");
	scanf("%d",&key);
	if(header==NULL)
	{
		printf("List empty");
	}
	else 
	{
		temp=header;
		while(temp->link!=NULL && temp->data!=key)
		{
			temp1=temp;
			temp=temp->link;
		}
		if(temp->link==NULL&&temp->data!=key)
		{
			printf("Key not found");
		}
		else
		{
			temp1->link=temp->link;
			free(temp);
		}
	}
}
void display()
{
	if(header==NULL)
	{
		printf("List empty");
	}
	else
	{
		temp=header;
		while(temp!=NULL)
		{
			printf("%d \t",temp->data);
			temp=temp->link;
		}
	}
}
void main()
{
	int ch,y;
	do
	{
	printf("\n 1.Insert at begin \n 2.Insert at end \n 3.Insert at Key \n 4.Delete at begin \n 5.Delete at end \n 6.Delete at key  \n 7.Display \n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :insert_begin();
		break;
	case 2 :insert_end();
		break;	
	case 3 :insert_key();
		break;
	case 4 :delete_begin();
		break;
	case 5 :delete_end();
		break;
	case 6 :delete_key();
		break;
	case 7 :display();
		break;
	default :printf("Invalid \n");
		break;
	}
    printf(" \n Do you want to quit click '0' or to continue click '1' ");
    scanf("%d",&y);
	}while(y==1);
}

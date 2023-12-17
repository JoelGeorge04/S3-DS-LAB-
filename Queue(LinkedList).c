#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node *link;
};
int choice,ch,item;
struct node *front,*rear,*temp,*new,*ptr;
void main()
{
	do
	{
		printf("Enter your choice\n1--Enqueue\t2--Dequeue\t3--Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
			break;
			case 2: dequeue();
			break;
			case 3: display();
			break;
			default:
			printf("Enter a Valid choice\n");
		}
		printf("Do you want to continue\n1--YES\t2--NO\n");
		scanf("%d",&ch);
	}while(ch==1);
}
void enqueue()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be inserted\n");
	scanf("%d",&item);
	new->data=item;
	new->link=NULL;
	if (front==NULL)
	{
		front=rear=new;
	}
	else
	{
		rear->link=new;
		rear=new;
	}
}
void dequeue()
{
	if(front==NULL)
	{
		printf("Deletion not possible\n");
	}
	else if(front==rear)
	{
		printf("Deleted item is %d\n",front->data);
		front=rear=NULL;
	}
	else
	{
		temp=front;
		printf("Deleted item is %d\n",temp->data);
		front=front->link;
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Queue elements are:\n");
		ptr=front;
		while(ptr->link!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
		printf("%d\n",ptr->data);
	}
}
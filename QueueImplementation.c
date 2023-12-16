#include<stdio.h>							
#define MAX_SIZE 5							
int front = -1;							
int rear = -1;
int queue[MAX_SIZE];
void enqueue(int item)
{
    if(rear== MAX_SIZE-1)
    {
        printf("The queue is full \t Insertion not possible: \n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear ++;
        queue[rear] = item;
    }
}

void dequeue()
{
    int del_item;
    if(front==-1)
    {
        printf("The queue is empty\n");
    }
    else 
    {
        del_item = queue[front];
        printf("The item %d was deleted \n",del_item);
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void display()
{
    if(front==-1)
    {
        printf("The queue is empty : \n");
    }
    else
    {
        printf("The queue is : ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d  ",queue[i]);
        }
        printf("\n");
    }
}
void main()
{
	int op,item,ch;
    	do
{
    		printf("1--enqueue \t\t2--dequeue \t\t3--Display \n");
    		printf("Enter your choice \n");
    		scanf("%d",&ch);
    		switch(ch)
    		{
       			case 1: printf("Enter the no to be inserted : ");
                    		scanf("%d",&item);
                    		enqueue(item);
                    		break;
        			case 2 : dequeue();
                    		break;
        			case 3 : display();
                   		break;
        			default: printf("INVALID CHOICE \n");
    		}
    		printf("\n");
    		printf("DO YOU WANT TO CONTINUE? (1-- YES) \n");
    		scanf("%d",&op);
	}while(op==1);
}

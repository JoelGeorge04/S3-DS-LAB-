#include<stdio.h>
#define n 5
int rear=-1;
int front=-1;
int queue[n];
void inject()
{	
		//insert at rear
		int x;
		printf("Enter the element \n");
		scanf("%d",&x);
		if(front == (rear+1)%n);
		{
		    printf("Overloading (Full) \n");
		}
		else if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
			queue[rear]=x;
		}
		else
		{
		    rear=(rear+1)%n;
		    queue[rear]=x;
		    printf("Element inserted is :%d",queue[rear]);
		}


}
void pushdq()
{
		//insert at front
		int x;
		printf("Enter the element \n");
		scanf("%d",&x);
		
		if(front==0 && rear==n-1)
		{
			    printf("Overloading (Full) \n");
		}
		else if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;
			queue[front]=x;
		}
		else if(front=0)
		{
			front=n-1;
			queue[front]=x;
		}
		else
		{
			front--;
			queue[front]=x;
		}

}
void popdq()
{
	//remove at front
	if(rear==-1&&front==-1)
	{
    	printf("underflow");
	}
	else if(rear==front)
	{
	    front=-1;
	    rear=-1;
	}
	else 
	{
	    printf("Element removed is :%d",queue[front]);
	    front=(front+1)%n;
	}
}
void eject()
{
	//remove at rear
	if(rear==-1 && front==-1)
	{
	    printf("underflow (Empty) \n");
	}
	else if(rear==front)
	{
	    printf("Element removed is :%d \n",queue[rear]);
	    front=-1;
	    rear=-1;
	}
	else if(rear==0)
	{
	    printf("Element removed is :%d \n",queue[rear]);
	    rear=n-1;
	}
	else
	{	
		printf("Element removed is :%d \n",queue[rear]);
		rear--;
	}
}
void display()
{
int i;
i=front;
while(i!=rear)
{
    printf("%d \t",queue[i]);
    i=(i+1)%n;
}
printf("%d ",queue[rear]);
}
void main()
{

	int ch,y;
	do{
	printf("\nSelect\n 1.Inject \n 2.PushDq \n 3.PopDq \n 4.Eject \n 5.display \n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1 :inject();
	break;
	case 2 :pushdq();
	break;
	case 3 :popdq();
	break;
	case 4 :eject();
	break;
	case 5:display();
	break;
	
	}
    printf(" \n Do you want to quit click '0' or to continue click '1' ");
    scanf("%d",&y);
	}while(y==1);
}

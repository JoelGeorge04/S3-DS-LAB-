#include <stdio.h>
int front=-1,rear=-1,n,item,p;
struct prio
{
	int pr;
	int value;
} Q[10],temp;


void sort(int w){
	for(int i=front;i<w;i++)
    {
		for(int j=front;j<w;j++)
        {
		    if(Q[j].pr<Q[j+1].pr)
            {
			    temp=Q[j];
		    	Q[j]=Q[j+1];
		    	Q[j+1]=temp;
		    }
	    }
	

    }
}

void EnQ()
{
	printf("Enter Item to be Inserted:");
	scanf("%d",&item);
	printf("Enter Priority:");
	scanf("%d",&p);
	if(front==-1 && rear==-1)
    {
		front=0;
		rear=0;
		Q[rear].value=item;		
		Q[rear].pr=p;
	}
	else if(rear>=n-1)
    {
		printf("Queue Full");
	}
	else
    {
		Q[++rear].value=item;
		Q[rear].pr=p;		
	}
	int w;
	w=rear;
	sort(w);
}
void DeQ(){
	if(front==-1 && rear==-1)
    {
			printf("Queue Empty");
	}
	else if(front == rear)
    {
		front=-1;
		rear=-1;
	}
}

void display(){

	for(int i=front;i<=rear;i++)
    {
		printf(" \n %d \n",Q[i].value);
	}
}




void main(){
	int ch;
	
	printf("Enter Number of Elements:");
	scanf("%d",&n);
	do
    {
	printf("1.Enqueue \n2.Dequeue \n3.Display\n");
	printf("Enter your Choice:");
	scanf("%d",&ch);
	    switch (ch)
        {
	    	case 1:EnQ();
	    			break;
	    	case 2:DeQ();
		    	break;
		    case 3:display();
		    	break;
		    default:
				printf("Invalid Option");

	    }
	}while(ch!=4);		
}
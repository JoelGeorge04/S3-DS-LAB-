#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
struct node*temp;
struct node*temp1;
struct node*temp3;
struct node*temp2;
struct node*newnode;
struct node*root=NULL;
int ch,item,flag,key,y;
void buildtree(int item)
{	
	if (root==NULL)
	{		
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=item;
		newnode->lchild=NULL;
		newnode->rchild=NULL;
		root=newnode;
	}
	else
	{
		temp=root;
		flag=0;
		while(temp!=NULL && flag==0)
		{
			if(temp->data==item)
			{
				flag=1;
			}
			else if(temp->data >item)
			{
				temp1=temp;
				temp=temp->lchild;
			}
			else if(temp->data <item)
			{
				temp1=temp;
				temp=temp->rchild;
			}
		}
		if(flag==1)
		{
		    printf("Element found no need to insert \n");
		}
		else
		{
		    newnode=(struct node*)malloc(sizeof(struct node));
		    newnode->data=item;
	 	   newnode->lchild=NULL;
		    newnode->rchild=NULL;
		    if(temp1->data>item)
		    {
		       temp1->lchild=newnode;
		    }
	 	   if(temp1->data<item)
		    {
		        temp1->rchild=newnode;
	 	   }
		}
	}
}
void smallest()
{
	temp=root;
    while(temp!=NULL)
	{
        temp1=temp;
		temp=temp->lchild;
	}
    printf("Smallest Node :%d",temp1->data);
}
struct node*succ(struct node* temp)
{
	temp1=temp->rchild;
	if(temp1!=NULL)
	{
		while(temp1->lchild!=NULL)
		{
			temp1=temp1->lchild;
		}
	return temp1;
	}
}
void delete(int item)
{
	temp=root;
	flag=0;
	while(temp!=NULL && flag==0)
	{
		if(temp->data==item)
		{
			flag=1;
		}
		else if(temp->data >item)
		{
			temp1=temp;
			temp=temp->lchild;
		}
		else if(temp->data <item)
		{
			temp1=temp;
			temp=temp->rchild;
		}
	}
	if(flag==1)
	{
		if(temp->lchild==NULL&&temp->rchild==NULL)
		{
			key=1;
		}
		else if(temp->lchild!=NULL&&temp->rchild!=NULL) 
		{
			key=3;
		}
		else
		{
			key=2;
		}
	}
	else
	{
		printf("Item not found \n");
	}
	if(key==1)
	{
		if(temp1->lchild==temp)
		{
			temp1->lchild=NULL;
		}
		else if(temp1->rchild==temp)
		{
			temp1->rchild=NULL;
		}
	}
	if(key==2)
	{
		if(temp1->rchild==temp)
		{
			if(temp->lchild==NULL)
			{
				temp1->rchild=temp->rchild;
			}
			else
			{
				temp1->rchild=temp->lchild;
			}
		}
		if(temp1->lchild==temp)
		{
			if(temp->lchild==NULL)
			{
				temp1->lchild=temp->rchild;
			}
			else
			{
				temp1->lchild=temp->lchild;
			}
		}
	}

	if(key==3)
		{
			temp2=temp;
    	 		temp3=succ(temp);
			item=temp3->data;
			delete(item);
			temp2->data=item;
		}
	
	}



void main()
{
	
	do
	{
	printf("\n 1.Insert \n2.Delete \n3.Smallest \n ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :	printf("Enter the value to be inserted to the node \n");
				scanf("%d",&item);
			 	buildtree(item);
				break; 
		case 2 : printf("Enter the item to delete \n");
				scanf("%d",&item);
				delete(item);
				break;
		case 3 : smallest();
				break;
	}	
	  printf(" \n Do you want to quit click '0' or to continue click '1' ");
   	  scanf("%d",&y);
	}while(y==1);
}
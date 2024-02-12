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
struct node*temp2,*parent1;
struct node *newnode,*grandparent;
struct node*root=NULL;
int ch,item,flag,key,y,count=0;
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
struct node *parent(struct node* temp,int item)
{
        flag=0;
        while(temp!=NULL && flag==0 )
		{
			if(temp->data==item)
			{
				//printf("%d",temp1->data);
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
		    if(temp1==root||temp1==root->rchild||temp1==root->lchild)
		        printf("No grandparent");
		    else
		        return temp1;
		}
    return NULL;
}
void main()
{
	
	do
	{
	printf("\n 1.Insert \n2.Find grandparent \n ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :printf("Enter the value to be inserted to the node \n");
				scanf("%d",&item);
			 	buildtree(item);
				break; 
		case 2 :count=0;
		        printf("Enter the data \n");
		        int data;
		        scanf("%d",&data);
		        parent1=parent(root,data);
		        grandparent=parent(root,parent1->data);
		        printf("%d ",grandparent->data);
                break;
	}	
	  printf(" \n Do you want to quit click '0' or to continue click '1' ");
   	  scanf("%d",&y);
	}while(y==1);
}

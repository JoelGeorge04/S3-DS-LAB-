#include<stdio.h>
#include<stdlib.h>
#define max 20
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
struct node*temp,*stack[max];
struct node*temp1;
struct node*newnode;
struct node*root=NULL;
int ch,item,flag,key,y,top=-1;
void push(struct node* temp)
{
    if(top>=max)
    {
        return;
    }
    else
    {
        top++;
        stack[top]=temp;
    }
}
struct node* pop()
{
    if(top<=-1)
    {
        return;
    }
    else
    {
        temp1=stack[top];
        top--;
        return temp1;
    }
}
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
void inorder(struct node* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->lchild);
        printf("%d \t",temp->data);
        inorder(temp->rchild);
    }
}
void inorderRecursion(struct node* temp)
{
    while(top>-1 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            push(temp);
            temp=temp->lchild;
        }
        else
        {
            temp=pop();
            printf("%d \t",temp->data);
            temp=temp->rchild;
        }
    }
}
void main()
{
	
	do
	{
	printf("\n 1.Insert \n2.Inorder(using recursion)\n3.Indorer(using recursion)\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :printf("Enter the value to be inserted to the node \n");
				scanf("%d",&item);
			 	buildtree(item);
				break; 
		case 2 : inorder(root); 
				break;
		case 3 :inorderRecursion(root);
				break;
	}	
	  printf(" \n Do you want to quit click '0' or to continue click '1' ");
   	  scanf("%d",&y);
	}while(y==1);
}
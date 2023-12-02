#include<stdio.h>
#include<stdlib.h>
#define n 6
int a[n],i,root,lval,y,Y,rval;
char ch;
void buildtree(int a[],int i,int root)
{
	
	if(i==0)
	{
	return;
	}
	else
	{
		a[i]=root;
		printf("%d",a[i]);
		printf("Do the tree has left child,,?(y/n)");
		__fpurge(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
		printf("Enter the value of the left child \n");
		scanf("%d",&lval);
		buildtree(a,2*i,lval);
		}
		else
		{
		buildtree(a,0,0);
		}
		printf("Do the tree has right child,,?(y/n)");
		__fpurge(stdin);
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
		printf("Enter the value of the right child \n");
		scanf("%d",&rval);
		buildtree(a,(2*i)+1,rval);
		}
		else
		{
		buildtree(a,0,0);
		}
			if(2*i<=n)
			{
			buildtree(a,2*i,lval);
			}
			else
			{
			if(2*i+1<=n)
			{
					buildtree(a,2*i+1,rval);
			}
		}
	
	}
}
void main()
{
	for(i=0;i<n;i++)
	{
	a[i]=0;
	}
	printf("Enter the root node..\n");
	scanf("%d",&root);
	buildtree(a,1,root);
	printf("Binary tree representation..\n");
	for(i=1;i<n;i++)
	{
		if(a[i]!=0)
		{
		printf("%d (%d)\t",a[i],i);
		}
	
		else
		{
		printf("_");
		}
	}
}
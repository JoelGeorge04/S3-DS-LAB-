#include<stdio.h>
#include<string.h>
int n,top=-1;
int stack1[20];
char infix[20],stack[20],postfix[20];
int precedence(char op)
{
	if(op=='+'||op=='-')
	{
		return 1;
	}
	else if(op=='*'||op=='/')
	{
		return 2;
	}
	else if(op=='^')
	{
		return 3;
	}
	else
		return 0;
}
void infix_to_postfix()
{
	int i,j;
	n=strlen(infix);
	for(i=0,j=0;i<n;i++)
	{
	if(infix[i]>='a'&&infix[i]<='z'||infix[i]>='A'&&infix[i]<='Z')
	{
		postfix[j]=infix[i];
		j++;		
	}
	else if(infix[i]=='(')
	{
		stack[++top]=infix[i];	
	}
	else if(infix[i]==')')
	{
		while(stack[top]!='('&&top>-1)
		{
		    if(stack[top]!='('&&top==-1)
		    {
		    	printf("Invalid expression \n");
		    }
			
		    else
            {		
			    postfix[j++]=stack[top--];
			}
		
		}
		top--;	
	}
	else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
	{
		if(precedence(stack[top])>=precedence(infix[i]))
		{
			postfix[j++]=stack[top--];
		}
		else
		{
			stack[++top]=infix[i];
		}
	}
}
	while(top>-1)
	{
	postfix[j++]=stack[top--];
	}
	postfix[j]='\0';
	printf("%s \n",postfix);
	
}
void posteval()
{	
	
	int n1,i,a,b,x,result;
	n1=strlen(postfix);
	for (i=0;i<n1;i++)
	{
		
		if(postfix[i]>='a'&&postfix[i]<='z')
		{
			printf("Enter the value of %c:",postfix[i]);
			scanf("%d",&x);
			stack1[++top]=x;
		}
		else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
		{
			a=stack1[top--];
			b=stack1[top--]; 
			if(postfix[i]=='+')
			{
			    result=b+a;
			}
			else if(postfix[i]=='-')
			{
			    result=b-a;
			}
			else if(postfix[i]=='*')
			{
			    result=b*a;
			}
			else if(postfix[i]=='/')
			{
			    result=b/a;
			}
			else if(postfix[i]=='^')
			{
			    result=b^a;
			}
			stack1[++top]=result;
		}
	}
	printf("Result is : %d \n",stack1[top]);
}
void main()
{
	printf("Enter the expression \n");
	scanf("%s",infix);
	infix_to_postfix();
	posteval();
}
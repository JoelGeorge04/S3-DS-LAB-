#include<stdio.h>
#include<string.h>
int n,n1,top=-1,top1=-1;
char infix[20],stack[20],stack1[20],postfix[20],g,prefix[20];
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
    {
         return 0;
    }
}
void eval()
{
n1=strlen(postfix);
int i,op,op1,op2;
for(i=0;i<n1;i++)
{
    if(postfix[i]>='a'&&postfix[i]<='z'||postfix[i]>='A'&&postfix[i]<='Z')
    {
        printf("Enter the value of %c:",postfix[i]);
         top=top+1;
        scanf("%d",&stack1[top]);
    }
    else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||
             postfix[i]=='/'||postfix[i]=='^')
    {
        g=postfix[i];
        op1=stack1[top];
        op=top-1;
        op2=stack1[top];
        top=top-1;
                switch(g)
            {
                case '+':op=op1+op2;
                         top=top+1;
                        stack1[top]=op;
                        break;
                 case '-':op=op1-op2;
                        top=top+1;
                        stack1[top]=op;
                         break;
                case '*':op=op1*op2;
                        top=top+1;
                        stack1[top]=op;
                        break;
                case '/':op=op1/op2;
                        top=top+1;
                        stack1[top]=op;
                        break;
                case '^':op=op1^op2;
                        top=top+1;
                        stack1[top]=op;
                        break;
            }
       }
    }       
    printf("%d",stack1[top]);
}
void rev()
{
    int i,j;
    i=0;
    j=n-1;
    char r;
    while(i<j)
    {
             r=infix[i];
             infix[i]=infix[j];
             infix[j]=r;
             i++;
             j--;
    }
    for(i=0;i<n;i++)
    {
                if(infix[i]==')')
                {
                   infix[i]='(';
                }
                else if(infix[i]=='(')
                {
                    infix[i]=')';   
                }
    }
    infix[n]='\0';
    printf("Reversed string is: %s \n",infix);
}
void rev1()
{
    int i,j;
    i=0;
    int n2;
    n2=strlen(postfix);
    j=n2-1;
    char r;
    while(i<n2) 
    {
        prefix[i]=postfix[j];
        i++;
        j--;
    }
    prefix[n]='\0';
    printf("Prefix:%s\n",prefix);
}
void infix_to_postfix()
{
    int i,j;
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
            while(stack[top] != '(' && top>-1)
            {
                if(stack[top]!='(' && top==-1)
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
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||
                infix[i]=='^')
        {   
            if(precedence(stack[top])==precedence(infix[i])&&infix[i]!='^')
            {
                stack[++top]=infix[i];
            }
            else
            {
                while(precedence(stack[top])>precedence(infix[i]))
                {
                   postfix[j++]=stack[top--];
                }
            stack[++top]=infix[i];
            }
         }
    }
    while(top>-1)
    {
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
}
void main()
{
    printf("Enter the expression \n");
    scanf("%s",infix);
    n=strlen(infix);
    rev();
    infix_to_postfix();
    printf("Postfix of reversed expression: %s \n",postfix);
    rev1();
    printf("Evaluation---- \n");
    eval();
}

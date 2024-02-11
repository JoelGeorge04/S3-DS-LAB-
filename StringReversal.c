#include<stdio.h>
#include<string.h>
#define max 20
char stack[max],str[max];
int top=-1;
void push(int item)
{
    if(top>=max)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
char pop()
{
    if(top!=-1)
    {
        char ch=stack[top];
        top--;  
        return ch;
    }
}
void main()
{
    printf("Enter the String\n");
    scanf("%s",str);
    int i;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        push(str[i]);
    }
    for(i=0;i<len;i++)
    {
        str[i]=pop();
    }
    printf("Reversed String \n");
    printf("%s",str);
}
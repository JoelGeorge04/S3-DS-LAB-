/* 1.Write a program that reads the name, age and salary of 11 persons and main-tains them in a linked list sorted by name. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char name[10];
    int age;
    float salary;
    struct node* link;
};
struct node *head,*temp,*newnode;
int age;
float salary;
char name[20];
void insert()
{
    printf("Enter your\nName\nAge\nSalary\n");
    scanf("%s%d%f",name,&age,&salary);
    newnode = (struct node* )malloc (sizeof(struct node));    
    strcpy(newnode->name,name);
    newnode->age=age;
    newnode->salary=salary;
    if(head==NULL)
    {
        head = newnode;
        newnode->link=NULL;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)        
        {
            temp=temp->link;      //newnode inserted to the end of linkedlist.
        }
        temp->link = newnode;
        newnode->link=NULL;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List Empty");
    }
    else
    {
        temp=head;
        printf("List ==> \n");
        while(temp!=NULL)
        {
            printf("Nmae=%s\nAge=%d\nSalary=%f\n",temp->name,temp->age,temp->salary);
            temp=temp->link;
        }
    }
}
void main()
{
    int ch;
    do{
        printf("\nEnter your choice\n1.Insert\n2.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 2:display();
                    break;
            default:printf("Invalid \n");
                    break;
        }
    }while(ch!=3);
}

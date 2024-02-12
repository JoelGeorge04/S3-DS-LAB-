#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *head,*temp,*temp1,*temp2,*newnode;
struct node* largest;
int item;
void insert()
{
    printf("Enter the data \n");
    scanf("%d",&item);
    newnode = (struct node* )malloc (sizeof(struct node));    
    newnode->data=item;
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
            temp=temp->link;
        }
        temp->link = newnode;
        newnode->link=NULL;
    }
}
void display()
{
    temp=head;
    printf("List ==>> ");
    while(temp!=NULL)
    {
        printf(" \t %d",temp->data);
        temp=temp->link;
    }
}
void swapLargeToLast()
{
   int temp3;
   temp=head;
   largest=temp;
    while(temp!=NULL)
    {
        if(temp->data > largest->data)
        {
            largest=temp;
        }
        temp=temp->link;
    }
    printf("Largest node==>> %d\n",largest->data);
    temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp3=largest->data;
    largest->data=temp->data;
    temp->data=temp3;
}

void main()
{
    int ch;
    do{
        printf("\n1.insert \n2.display\n3.Swap Largest to last\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 2:display();
                    break;
            case 3:swapLargeToLast();  
                    break;
            
            case 4:  
                    break;
            default:printf("Invalid \n");
                    break;
        }
    }while(ch!=4);
}
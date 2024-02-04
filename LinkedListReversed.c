#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *head ,*current,*temp,*prev,*next,*newnode;
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
void reverse()
{
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        
        next=current->link;
        current->link=prev;   
        prev=current;
        current=next;
    }
    head=prev;
    //to display call display
}
void main()
{
    int ch;
    do{
        printf("\n1.insert \n2.display\n3.reverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                    break;
            case 2:display();
                    break;
            case 3:reverse();  
                    break;
            default:printf("Invalid \n");
                    break;
        }
    }while(ch!=4);
}
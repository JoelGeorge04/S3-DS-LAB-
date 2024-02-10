#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *head,*head1,*head2,*current,*temp,*prev,*next,*newnode;
int item;
struct node* insert(struct node* head)
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
    return head;
}
void display()
{
    if(head1==NULL)
    {
        printf("1st List Empty \n");
    }
    else
    {
        temp=head1;
        printf("1st List ==> \n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
    }
        if(head2==NULL)
        {
           printf("2st List Empty \n");
        }
        else
        {
              temp=head2;
              printf("\nSecond List ==> \n");
              while(temp!=NULL)
             {
                 printf("%d\t",temp->data);
                 temp=temp->link;
             }
        }
    
}
void merge()
{
    if(head1==NULL)
    {
        printf("1st List Empty");
    }
    else
    {
          temp=head1;
          while(temp->link!=NULL)
          {
            temp=temp->link;
          }
          temp->link=head2; //2nd list added to 1st list.
          temp=head1;
          printf("Merged List ==> \n");
          while(temp->link!=NULL)
          {
              printf("%d\t",temp->data);
              temp=temp->link;
          }
          printf("%d\t",temp->data);
    }
}
void main()
{
    int ch;
    do{
        printf("\n1.Insert(1st List)\n2.Insert(2nd List) \n3.Display(Both List)\n4.MergeList\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head1=insert(head1);
                    break;
            case 2:head2=insert(head2);
                    break;
            case 3:display();
                    break;
            case 4:merge();
                   break;
            default:printf("Invalid \n");
                    break;
        }
    }while(ch!=5);
}
/*2.There are two linked lists A and B containing the following data: 
    A:3, 7,10,15,16,9,22,17,32
    B:16, 2,9,13,37,38,10,1,28
    Write a program to create:  
    -A linked list C that contains only those elements that are common in linked list A and B. 
    - A linked list D which contains all elements of A as well as B ensuring that there is no repetition of elements.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *head,*head1,*head2,*head3,*head4,*temp,*temp1,*newnode;
int item,i=0,j=0,a[100],b[100],n,m;
struct node* insert(struct node* head,int item)
{
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
           printf("\n2st List Empty \n");
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
        if(head3==NULL)
        {
           printf("\n3rd List Empty \n");
        }
        else
        {
              temp=head3;
              printf("\nThird List ==> \n");
              while(temp!=NULL)
             {
                 printf("%d\t",temp->data);
                 temp=temp->link;
             }
        }
        head3=NULL;
        if(head4==NULL)
        {
           printf("\n4th List Empty \n");
        }
        else
        {
              temp=head3;
              printf("\nFourth List ==> \n");
              while(temp!=NULL)
             {
                 printf("%d\t",temp->data);
                 temp=temp->link;
             }
        }
}
void nxtList(struct node* head1,struct node* head2)
{
   temp=head1;
   while(temp!=NULL)
   {
       a[i]=temp->data;
       temp=temp->link;
       i++;
       n=i;
   }
   temp=head2;
   while(temp!=NULL)
   {
       b[j]=temp->data;
       temp=temp->link;
       j++;
       m=j;
   }
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           if(a[i]==b[j])
           {
               b[j]=0;
               head3=insert(head3,a[i]);
           }
       }
   }
}
/*void listD(struct node* head1,struct node* head2)
{
    temp=head1;
    while(temp!=NULL)
    {
        temp=temp->link;
    }
    temp->link=head2;// List A and List B merged.
    while(temp->link!=NULL)
    {
        head4=insert(head4,temp->data);
        temp=temp->link;
    }

}*/
void main()
{
    int ch;
    do{
        printf("\n1.Insert(1st List)\n2.Insert(2nd List) \n3.Display\n4.Read common elements for list C\n5.List D\n");
        // All as per question.
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data \n");
                    scanf("%d",&item);
                    head1=insert(head1,item);
                    break;
            case 2:printf("Enter the data \n");
                    scanf("%d",&item);
                    head2=insert(head2,item);
                    break;
            case 3:display();
                    break;
            case 4:nxtList(head1,head2);
                    break;
           /* case 5:listD(head1,head2);
                    break;*/
            default:printf("Invalid \n");
                    break;
        }
    }while(ch!=5);
}
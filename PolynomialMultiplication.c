#include <stdio.h>
#include <math.h>
#define MAX 50

struct poly {
    int expo;
    int coeff;
}p1[20],p2[20],p3[20];
int n1,n2,n3,i,j,k=0;
void main()
{
    printf("Enetr the no. of terms in poly1\n");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enetr the coeff and expo \n");
        scanf("%d%d",&p1[i].coeff,&p1[i].expo);
    }
    printf("Enetr the no. of terms in poly2\n");
    scanf("%d",&n2);
    for(j=0;j<n2;j++)
    {
        printf("Enetr the coeff and expo \n");
        scanf("%d%d",&p2[j].coeff,&p2[j].expo);
    }
    printf("First Polynomial\n");
    for(i=0;i<n1-1;i++)
    {
        printf("%dX^%d+",p1[i].coeff,p1[i].expo);
       
    }
    printf("%dX^%d",p1[n1-1].coeff,p1[n1-1].expo);
    printf("\nSecond Polynomial\n");
    for(i=0;i<n2-1;i++)
    {
        printf("%dX^%d+",p2[i].coeff,p2[i].expo);
       
    }
    printf("%dX^%d",p2[n2-1].coeff,p2[n2-1].expo);
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            p3[k].expo=p1[i].expo + p2[j].expo;
            p3[k].coeff=p1[i].coeff * p2[j].coeff;
            k++;
        }
    }
    n3=k;
    printf("\nResultant polynomial\n");
    for(k=0;k<n3-1;k++)
    {
        printf("%dX^%d+",p3[k].coeff,p3[k].expo);
    }
    printf("%dX^%d",p3[n3-1].coeff,p3[n3-1].expo);
    
}
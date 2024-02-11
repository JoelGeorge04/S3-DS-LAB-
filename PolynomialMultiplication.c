#include <stdio.h>
#include <math.h>
#define MAX 50

struct poly {
    int expo;
    int coeff;
}p1[20],p2[20],p3[20];
int n1,n2,i,j,k;
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
     for(i=0;i<=n2-1;i++)
    {
        printf("%dX^%d+",p1[i].coeff,p1[i].expo);
       
    }
}
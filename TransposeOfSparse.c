#include<stdio.h>
void main()
{ 
    int r,c,i,j,a[10][10],t[3][10],s[3][10],k=1,x=1;
     printf("Enter no of rows:\n");
    scanf("%d",&r);
     printf("Enter no of cols:\n");
    scanf("%d",&c);
    printf("Enter sparse matrix elements:\n");
    for(i=0;i<r;i++)
     {
         for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
         }
    }
    printf("The sparse matrix is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           if(a[i][j]!=0)
            {
                s[0][k]=i;
                s[1][k]=j;
                s[2][k]=a[i][j];
                k++;
            }
         }
    }
    printf("Sparse matrix representation:\n");
     s[0][0]=r;
    s[1][0]=c;
     s[2][0]=k-1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<k;j++)
        {
            printf("%d\t",s[i][j]);
        }
    printf("\n");
    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<k;j++)
        {
            if(s[1][j]==i) 
            {
                 t[0][x]=s[1][j];
                 t[1][x]=s[0][j];
                 t[2][x]=s[2][j];
                x++;
            }
        }
    }
    t[0][0]=s[1][0];
    t[1][0]=s[0][0];
    t[2][0]=s[2][0];
    printf("Transose of sparse matrix :\n"); 
    for(i=0;i<3;i++)
    {
        for(j=0;j<x;j++)
        {
            printf("%d\t",t[i][j]);
        }
    printf("\n");
    }
}
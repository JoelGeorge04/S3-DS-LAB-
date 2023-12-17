#include <stdio.h>
#include<stdlib.h>
struct poly{
	int coeff;
	int expn;
}*ptr1,*ptr2,*ptr3;
void poly_add(struct poly *ptr1,struct poly *ptr2,struct poly *ptr3,int n1,int n2,int n)
{	
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if((ptr1+i)-> expn == (ptr2+j)-> expn)
		{
		    (ptr3+k)-> coeff=(ptr1+i)-> coeff + (ptr2+j)-> coeff;
		    (ptr3+k)-> expn=(ptr1+i)-> expn;
		    i++;
		    j++;
		    k++;
		}
		else if((ptr1+i)-> expn > (ptr2+j)-> expn)
		{
		    (ptr3+k)-> coeff=(ptr1+i)-> coeff;
		    (ptr3+k)-> expn=(ptr1+i)-> expn;
		    i++;
		    k++;
		}
		else
		{
		    (ptr3+k)-> coeff=(ptr2+j)-> coeff;
		    (ptr3+k)-> expn=(ptr2+j)-> expn;
		    j++;
		    k++;
		}	
	}
	
	
		while(i<n1)
		{
		    (ptr3+k)-> coeff=(ptr1+i)-> coeff;
		    (ptr3+k)-> expn=(ptr1+i)-> expn;
		    i++;
		    k++;
		}
		while(j<n2)
		{
		    (ptr3+k)-> coeff=(ptr2+j)-> coeff;
		    (ptr3+k)-> expn=(ptr2+j)-> expn;
		    j++;
		    k++;
		}
		printf("\n Resultant polynimial is : \n");
		n=k;
	for(k=0;k<n-1;k++)
	{
	    printf("%d X ^%d + ",(ptr3+k)-> coeff,(ptr3+k)-> expn);
	}
	printf("%d X ^%d",(ptr3+(n-1))-> coeff,(ptr3+(n-1))-> expn);
}	
void main()
{
	int i,j,k,n1,n2,n;
	printf("Enter the number of terms in 1st and 2nd polynomial \n");
	scanf("%d %d",&n1,&n2);
	n=n1+n2;
	ptr1=(struct poly*)malloc(n1 * sizeof(struct poly));
	
	ptr2=(struct poly*)malloc(n2 * sizeof(struct poly));
	
	ptr3=(struct poly*)malloc(n * sizeof(struct poly));

	for(i=0;i<n1;i++)
	{
		printf("Enter the coeff,expo of 1st poly \n");
		scanf("%d%d",&(ptr1+i)-> coeff,&(ptr1+i)-> expn);
	}
	for(j=0;j<n2;j++)
	{
		printf("Enter the coeff,expo of 2st poly \n");
		scanf("%d%d",&(ptr2+j)-> coeff,&(ptr2+j)-> expn);
	}
	poly_add(ptr1,ptr2,ptr3,n1,n2,n);
}
#include<stdio.h>
int a[10],n,i,j,key;
int temp,min,loc;
int pivot,right,left,high,low,b[20],k,mid;
void insertion()
{
	for(i=1;i<n;i++)
	{
		key=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>key)
			{
				a[j+1]=a[j];
			}
			else
			{
				break;
			}
			a[j]=key;                                                                                                         
		}
	}
	printf("The Sorted Array is :\n ");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
void bubble_sort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The Sorted Array is :\n ");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
void selection_sort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        if(loc!=i)
        {
            temp=a[i];
            a[i]=a[loc];
            a[loc]=temp;
        }
    }
    printf("The Sorted Array is :\n ");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}
int part(int left,int right)
	{
		pivot=left;
		while(left <right)
		{
			while((a[pivot]<=a[right])&& pivot < right)
			{
				right =right-1;
			}
			while(a[pivot]>a[right])
			{
				int temp=a[pivot];
				a[pivot]=a[right];
				a[right]=temp;
				pivot=right;
				left++;
			}
		
		
			while((a[pivot]>=a[left])&& pivot > left)
			{
				left =left+1;
			}
			while(a[pivot]<a[left])
			{
				temp=a[pivot];
				a[pivot]=a[right];
				a[right]=temp;
				pivot=left;
				right--;
			}
		}
		return pivot;
	
}
void display()
{
	printf("The Sorted Array is :\n ");
		for(i=0;i<n;i++)
		{
			printf("%d \t",a[i]);
		}


}
void quick(int a[],int left,int right)
{
		int p=part(left,right);
		if(left<right)
		{
			quick(a,left,p-1);
			quick(a,p+1,right);
		}	     	  
}
void merge(int low,int mid,int high)
{
	
	k=low;
	i=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k=k+1;
			i=i+1;
		}
		else
		{
			b[k]=a[j];
			k=k+1;
			j=j+1;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		k=k+1;
		i=i+1;
	}
	while(j<=high)
	{
		b[k]=a[j];
		k=k+1;
		j=j+1;
	}
	for(i=low;i<=high;i++)
	{
		a[i]=b[i];
	}
	
}

void merge_sort(int low,int high)
{	
	int mid,k;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

void main()
{	
	int ch;
	do
	{
	printf("\nEnter your choice \n1.insertion \n2.selection \n3.bubble \n4.quick \n5.Merge \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the number of elements:\n");
            	scanf("%d",&n);
	            printf("Enter the elements:\n");
	            for(i=0;i<n;i++)
	            {
		            scanf("%d",&a[i]);
	            }
    			insertion();
    			break;
		case 2: printf("Enter the number of elements:\n");
            	scanf("%d",&n);
	            printf("Enter the elements:\n");
	            for(i=0;i<n;i++)
	            {
		            scanf("%d",&a[i]);
	            }
    			selection_sort(a,n);
    			break;
		case 3: printf("Enter the number of elements:\n");
            	scanf("%d",&n);
	            printf("Enter the elements:\n");
	            for(i=0;i<n;i++)
	            {
		            scanf("%d",&a[i]);
	            }
	            bubble_sort(a,n);
    			break;
		case 4: quick(a,0,n-1);
				display();
            	printf("Enter the number of elements:\n");
            	scanf("%d",&n);
	            printf("Enter the elements:\n");
	            for(i=0;i<n;i++)
	            {
		            scanf("%d",&a[i]);
	            }
	            bubble_sort(a,n);
			    break;
		case 5: printf("Enter the number of elements:\n");
            	scanf("%d",&n);
	            printf("Enter the elements:\n");
	            for(i=0;i<n;i++)
	            {
		            scanf("%d",&a[i]);
	            }
		
		        low =0;
		    	high =n-1;
		    	merge_sort(low,high);
		    	display();
			    break;
	}
	}while(ch!=6);	
}
#include<stdio.h>
    
void swap(int x, int y,int A[])
{
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int main()
{
    int i,j,min;
    int A[10] = {3,6,7,2,5,8,9,0,1,4};
    int n = 10;
    
    printf("Array before Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    
    for(i=0;i<(n-1);i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        if( min != i)
            swap(i,min,A);
    }
    
    printf("\nArray after Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
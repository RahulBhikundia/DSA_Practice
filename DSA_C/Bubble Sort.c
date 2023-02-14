#include<stdio.h>

void swap(int x, int y,int A[])
{
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int main()
{
    int A[10] = {3,6,7,2,5,8,9,0,1,4};
    int n = 10;
    
    printf("Array before Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    
    for(int pass =1;pass<n-1;pass++)
    {
        for(int i=0;i<n-pass;i++)
        {
            if(A[i]>A[i+1])
                swap(i,i+1,A);
        }
    }
    
    printf("\nArray after Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
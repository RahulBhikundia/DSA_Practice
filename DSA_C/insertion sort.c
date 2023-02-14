#include<stdio.h>

int main()
{
    int i,j,key;
    int A[10] = {3,6,7,2,5,8,9,0,1,4};
    int n = 10;
    
    printf("Array before Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
    
    for(i=1;i<n;i++)
    {
        key = A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
            j=j-1;
        }
        A[j+1] = key;
    }
    
    printf("\nArray after Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
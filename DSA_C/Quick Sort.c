//Program for Quick Sort
#include<stdio.h>

void swap(int x, int y,int A[])
{
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(int first,int last,int A[])
{
    int pi = first;
    int L = pi,R = last+1;
    while(L<R)
    {
        do
        {
            L++;
        }
        while(A[L]<A[pi]);
        do
        {
            R--;
        }
        while(A[R]>A[pi]);
        if(L < R)
        {
            swap(L,R,A);
        }
    }
    swap(pi,R,A);
    return R;
}

void QuickSort(int first,int last,int A[])
{
    while(first<last)
    {
        int pi = partition(first,last,A);
        QuickSort(first,pi-1,A);
        QuickSort(pi+1,last,A);
        return;
    }
    return;
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
    
    QuickSort(0,n-1,A);
    
    printf("\nArray after Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
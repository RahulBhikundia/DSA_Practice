#include<stdio.h>

void Merge(int A[],int p,int q,int r)
{
    int n = q-p+1;
    int m = r-q;
    int P[n],Q[m];
    for(int i=0;i<n;i++)
    {
        P[i] = A[p+i];
    }
    for(int i=0;i<m;i++)
    {
        Q[i] = A[q+1+i];
    }
    int i=0,j=0,k=p;
    while(i<n && j<m)
    {
        if(P[i] < Q[j])
        {
            A[k] = P[]
        }
    }
}

void MergeSort(int A[],int l,int r)
{
    if(l<r)
    {
        int mid = l + ((r-l)/2)
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,r);
        Merge(A,l,mid,r);
    }
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
   
    MergeSort(A,0,n-1);
   
    printf("\nArray after Sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}
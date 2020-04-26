#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define myinfinite 2147483647

int inversions;

void merge(int A[], int p, int q, int r)
{
    int i, j, n1,n2,k;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1], R[n2+2];
    
    for(i=1; i<=n1; i++)
    L[i]=A[p+i-1];
    
    for(j=1; j<=n2; j++)
    R[j]=A[q+j];
    
    L[n1+1]= myinfinite;
    R[n2+1]=myinfinite;
    i=1;
    j=1;
    
    for (k=p; k<=r; k++)
    {
        if(L[i]<= R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]= R[j];
            printf("%d ", n1 + 1 - i);/////////////////////////////////////
            inversions += n1 - i; 
            j++;
        }
    }
}

void mergesort( int A[], int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A,p,q,r);
    }
}

int main ()
{
    int n, A[100005], index, value;
    while (scanf ("%d", &n) != EOF)
    {
    	inversions = 0;
        for(index=1; index<=n; index++)
        {
            scanf("%d", &value);
            A[index]=value;
        }
        mergesort(A, 1, n);
        
        printf("%d", inversions);
    }
    return 0;
}

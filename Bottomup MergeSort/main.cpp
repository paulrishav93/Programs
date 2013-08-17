#include <iostream>
using namespace std;

void mergearray(int *a, int lo, int mid, int hi)
{
    int i=lo;
    int j=mid+1;
    int k=0;

    int *b=new int[hi-lo+1];

    while(i<=mid && j<=hi)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=mid)
        b[k++]=a[i++];

    while(j<=hi)
        b[k++]=a[j++];

    for(i=hi;i>=lo;i--)
        a[i]=b[--k];

}

void mergesort(int *a, int n)
{
    for(int size=1;size<=n;size=size*2)
        for(int lo=0;lo<=n-size;lo=lo+2*size)
            mergearray(a,lo,lo+size-1,min(lo+size*2-1,n));
}
int main()
{
    int a[]={2,5,4,1,9,8,7,6,5,4,3,76,2,1};
    mergesort(a,13);
    for(int i=0;i<14;i++)
        cout<<a[i]<<" ";
    return 0;
}

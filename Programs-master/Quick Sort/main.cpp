#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int partition(int *a, int lo, int hi)
{
    int A=a[lo];

    int B=a[(lo+hi)/2];

    int C=a[hi];

    if((C<B && B<A)||(A<B && B<C))
    swap(a[lo],a[(lo+hi)/2]);

    else if((B<C && C<A) || (A<C && C<B))
    swap(a[lo],a[hi]);

    int pivot=a[lo];
    int i=lo+1;


    int j=hi;


    while(1)
    {
        while(a[i]<pivot && i<=hi)
            i++;

        while(a[j]>pivot && j>=lo)
            j--;

        if(i>=j) break;
        swap(a[i],a[j]);
    }

    swap(a[lo],a[j]);

    return j;
}

void quicksort(int *a, int lo, int hi)
{
    if(lo<hi)
    {
        int j=partition(a,lo,hi);
        quicksort(a,lo,j-1);
        quicksort(a,j+1,hi);
    }
}
int main()
{
    int n;
    cin>>n;

    int *a=new int[n];

    for(register int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n);

    for(register int i=0;i<n;i++)
        cout<<a[i]<<endl;
    return 0;
}

#include <iostream>
using namespace std;

void quicksort(int *a, int lo, int hi)
{
    int lt=lo, gt=hi;
    int i=lo;
    if(lo>=hi) return;
    int v=a[lo];
    while(i<=gt)
    {
        if(a[i]<v)
        {
            swap(a[lt],a[i]);
            lt++;
            i++;
        }

        else if(a[i]>v)
        {
            swap(a[gt],a[i]);
            gt--;
        }

        else    i++;
    }

    quicksort(a,lo,lt-1);
    quicksort(a,gt+1,hi);

}

int main()
{
    int a[]={11,2,31,2,5,5,7};

    quicksort(a,0,6);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    return 0;
}

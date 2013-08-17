#include <iostream>
#include <fstream>

using namespace std;

void swap (int &a, int &b)
{
     int temp=a;
     a=b;
     b=temp;
}
int c=0;


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
    c+=hi-lo;

    for(register int j=lo+1;j<=hi;++j)
    {
     if(a[j]<pivot)
     {
      swap(a[j],a[i]);
      i++;
     }
    }

   swap(a[lo],a[i-1]);

   return i-1;
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

    ifstream fin;
    ofstream fout;
    fin.open("QuickSort.txt");
    fout.open("Sorted.txt");
    int a[10000];

    for(register int i=0;i<10000;++i)
    fin>>a[i];

    quicksort(a,0,9999);

      cout<<c;


    return 0;
}

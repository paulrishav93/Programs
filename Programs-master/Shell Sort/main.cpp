#include <iostream>

using namespace std;

void shellsort(int *a, int n)
{
    int h=1;

    while(h<n/3)
        h=3*h+1;

    while(h>=1)
    {
       for(int i=h;i<n;i++)
        {
            int j=i;
            int key=a[j];

            while(key<=a[j-h] && j>=h)
            {
                a[j]=a[j-h];
                j=j-h;
            }
            a[j]=key;
        }
        h=(h-1)/3;
    }

    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
}
int main()
{
    int a[10];

    for(int i=0;i<10;i++)
        a[i]=10-i;
    shellsort(a,10);
    return 0;
}

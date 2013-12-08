#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

void permute(char *a, int index, int end_index)
{
    if(index == end_index)
        cout<<a<<endl;

    else
    {
        for(int i=index ; i <= end_index ; ++i)
        {
            swap(a[i],a[index]);
            permute(a,index + 1 , end_index);
            swap(a[i],a[index]);
        }
    }
}

int main()
{
    char a[100];

    cin.getline(a, 100, '\n');

    permute(a,0, strlen(a)-1);
}


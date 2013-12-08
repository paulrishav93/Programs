
/* 

PRINT ALL PERMUTATIONS OF A STRING

The idea is that for every N length string we can calculate the permutation
of that string by first calculating all the strings which start at the first
letter of the original string + all the permutations of the rest of the string
and then the permutations of the string starts with the second letter + all
the permutations of the rest of the string and so on until we reach the strings
which starts with the last letter of the string + all the permutations of the
rest of the string .

*/

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
        }
    }
}

int main()
{
    char a[100];

    cin.getline(a, 100, '\n');

    permute(a,0, strlen(a)-1);
}


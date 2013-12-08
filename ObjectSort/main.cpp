#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;

    for(int i=99;i>=0;++i)
        v.push_back(i);

    //sort(v.begin(),v.end());

    for(int i=0;i<100;++i)
        cout<<v[i]<<" ";

    return 0;
}

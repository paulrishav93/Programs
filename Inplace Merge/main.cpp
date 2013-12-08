#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //vector<int> v;

    vector<int> v;

    v.push_back(4);
    v.push_back(5);v.push_back(6);v.push_back(1);v.push_back(2);v.push_back(3);

    inplace_merge(v.begin(),v.begin()+3,v.end());

    for(int i=0;i<6;++i)
    cout<<v[i]<<" ";
    //inplace_merge()
    return 0;
}

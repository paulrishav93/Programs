#include <iostream>
#include <vector>

using namespace std;


int LIS(vector<int> &a)
{
    vector<int> LISTable(a.size(),1);

    for(int i=0;i<a.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            if(a[j]<a[i] && LISTable[i]<LISTable[j]+1)
            {
                LISTable[i]=LISTable[j]+1;
            }
        }
    }
    int max=0;

    for(int i=0;i<a.size();++i)
    {
        if(max<LISTable[i])
            max=LISTable[i];
    }

    return max;
}

int main()
{
    vector<int> a;  int b;

    for(int i=0;i<5;++i)
    {
        cin>>b;
        a.push_back(b);
    }

    cout<<LIS(a);
    return 0;
}

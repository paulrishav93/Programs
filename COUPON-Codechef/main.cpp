#include <iostream>
#include <vector>
#define usig unsigned long long
#define INF 1000000007
using namespace std;

int main()
{
    int T,N,M,temp;
    vector< vector<usig> > price;
    vector< vector<usig> > discount;
    vector< vector<usig> > dp;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;

        price.resize(N);
        discount.resize(N);

        for(usig i=0;i<N;++i)
        {
            price[i].resize(M);
            discount[i].resize(M);
            dp[i].resize(M);
        }

        for(usig i=0;i<N;++i)
            for(usig j=0;j<M;++j)
                cin>>price[i][j];       //price of item 'i' in shop 'j'


        for(usig i=0;i<N;++i)
            for(usig j=0;j<M;++j)
                cin>>discount[i][j];    //discount of item 'i' in shop 'j'

        usig prev=INF*INF;

        for(int i=0;i<M;++i)
        {
            dp[0][i]=price[0][i];
            prev=min(prev,dp[0][i]);
        }
    }
    return 0;
}

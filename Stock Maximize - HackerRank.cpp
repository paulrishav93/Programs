#include <iostream>

using namespace std;


/**
https://www.hackerrank.com/challenges/stockmax

STOCK MAXIMIZE PROBLEM

We have the stock prices on all the days.
We want to sell the stock at a point of maximum price after purchase.
So, we traverse the array in reverse and mark all the selling points

For array { 5,9,3,1,7} selling points will be { 0,1,0,0,1 }

*/

int main()
{
    int t, n;

    cin >> t ;

    while(t--)
    {
        cin >> n;

        int * a = new int [ n ];
        bool *bs = new bool[n];

        for( int i = 0 ; i < n ; ++ i)
            cin >> a[i];

        int sell = a[n-1]; bs[n-1] = 0;

        for( int i = n-2; i >= 0 ; i --)
        {
            if(a[i] > sell ) { sell = a[i]; bs[i] = 0;}
            else bs[i] = 1;
        }

        unsigned long long buy = 0 , profit = 0, available = 0,count=0;
        for( int i = 0 ; i < n; ++ i)
        {
            if(bs[i] == 1) { buy+=a[i]; available = 1;count++;}
            if(!bs[i] && available ) { profit += count*a[i] - buy; buy = 0; count = 0;}
        }

        cout << profit << endl;
    }

    return 0;
}

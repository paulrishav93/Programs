#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define type pair<int,int>

int main()
{
	vector< pair<int, pair<int,int> > > data;

	data.push_back(pair<int, type > (8, (type(2,3))));
	data.push_back(pair<int, type > (4, (type(2,3))));
	data.push_back(pair<int, type > (1, (type(2,3))));
	data.push_back(pair<int, type > (6, (type(2,3))));
	data.push_back(pair<int, type > (12, (type(2,3))));
	data.push_back(pair<int, type > (89, (type(2,3))));
	data.push_back(pair<int, type > (-9, (type(2,3))));

	sort(data.begin(),data.end());

	for(int i=0;i<6;++i)
		cout<<data[i].first<<" ";

	return 0;
}

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;
	
	cout<<vec.size();
	
	for(int i=0;i<40;++i)
		vec.push_back(i);
	
	cout<<endl<<vec.size();
	
	vector<int>::iterator v=vec.begin();
	
	while(v!=vec.end())
	{
		cout<<*v<<endl;
		v++;
	}
	
	v=vec.begin();
	
	cout<<v[8]<<endl;
	
	v=vec.end()-1;
	
	while(v!=vec.begin())
	{
		cout<<*v<<endl;
		v--;
	}
	return 0;
}

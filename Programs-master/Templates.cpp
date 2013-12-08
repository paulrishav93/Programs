#include<iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<class T> class item
{
	
	public:
	//template<typename T> b;
	T b;
	
	item(T a)
	{
		b=a;
	}
	
	void display()
	{
		cout<<b<<endl;
	}
};

int main()
{
	item<int> a(3);
	a.display();
	
	item<string> b("123");
	b.display();
	
	return 0;
}





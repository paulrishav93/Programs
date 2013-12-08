#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> Q;

    for(int i=0;i<10;++i)
        Q.push(i);


    while(!Q.empty())
    {
        cout<<Q.front()<<" ";
        Q.pop();
    }

    return 0;
}

/*
empty: Test whether container is empty (public member function )
size: Return size (public member function )
front: Access next element (public member function )
back :Access last element (public member function )
push :Insert element (public member function )
emplace :Construct and insert element (public member function )
pop :Remove next element (public member function )
swap :*/

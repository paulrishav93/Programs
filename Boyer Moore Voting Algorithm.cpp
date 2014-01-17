#include <iostream>
using namespace std;

int A[] = {1,2,3,2,4,2,2,2,2,2,6,5}, len = 12;

void boyer_moore_majority()
{
	int key = A[0];
	int count = 0;

	int i = 0;

	while ( i < len )
	{

//        if ( key == -1 ) { key = A[i]; count = 1;}

		if ( A[i] == key ) { count ++ ; }
        	else if (key == -1 ) { count = 1; key = A[i];}
		else
		{
		    if ( !count ) {key = A[i];}
		    else if ( count >= 1 ) {count --; if(!count) key = -1;}
		}

		i++;

		cout << key <<" " << count << endl;
	}

	if ( count >= 1 ) cout << key << endl;
}

int main()
{

	boyer_moore_majority();
	return 0;
}

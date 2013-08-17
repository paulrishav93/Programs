#include <iostream>
using namespace std;

void buildheap(int A[], int length);
void heapify(int A[], int heapsize, int root);

void heapsort(int A[], int length)//	       (takes O(n lg n) time)
{
	int heapsize = length;

	buildheap(A, length);	//Take the unsorted list and make it a heap

	for (int i = length-1; i >=1; i--)
	{
		swap(A[0], A[i]);
		heapsize--;
		heapify(A, heapsize, 0);
	}
}

void buildheap(int A[], int length)	//     (takes O(n) time)
{
	for (int i = ((length)/2); i >= 0 ; i--)
		heapify(A, length, i);
}

void heapify(int A[], int heapsize, int root) //(takes O(h) time,
					// h is the height of root
{
	int left = 2*root+1,
		right = 2*root +2,
		largest;

	if ( (left < heapsize) && (A[left] > A[root]))
		largest = left;
	else
		largest = root;

	if ( (right < heapsize) && (A[right] > A[largest]))
		largest = right;

	if (largest != root)
	{
		swap(A[root], A[largest]);
		heapify(A, heapsize, largest);
	}
}

int main()
{   int a[]={6,5,8,4};
    heapsort(a,4);
    for(int i=0;i<=3;i++)
        cout<<a[i]<<" ";
    return 0;
}

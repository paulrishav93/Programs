#include <stdio.h>

int count = 0;
int inversions(int a[], int len);
void mergesort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main() {
  int a[] = {1,6,3,2,4,5};
  printf("%d\n", inversions(a, 5));
}

int inversions(int a[], int len) {
  mergesort(a, 0, len - 1);
  return count;
}

void mergesort(int a[], int left, int right) {
  if (left < right) {
     int mid = (left + right) / 2;
     mergesort(a, left, mid);
     mergesort(a, mid + 1, right);
     merge(a, left, mid, right);
  }
}

void merge(int a[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int b[right - left + 1];
  while (i <= mid && j <= right) {
     if (a[i] <= a[j]) {
       b[k++] = a[i++];
     } else {
       printf("right element: %d\n", a[j]);
       count += (mid - i + 1);
       printf("new count: %d\n", count);
       b[k++] = a[j++];
     }
  }
  while (i <= mid)
    b[k++] = a[i++];
  while (j <= right)
    b[k++] = a[j++];
  for (i = left, k = 0; i <= right; i++, k++) {
    a[i] = b[k];
  }
}

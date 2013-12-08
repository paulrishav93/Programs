#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y=28;

    const int x=y;

    int a[x];

    a[0]='A';

    printf("%c%d",a[0],y);

    return 0;
}

#include <stdio.h>

int Grcd(int a, int b);

int main()
{
    int n, t;
    printf("enter 2 num ");
    scanf("%d%d", &n, &t);
    printf("the greatest common division of %d and %d is %d\n", n, t, Grcd(n, t));
    return 0;
}

int Grcd(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
#include <stdio.h> 

int Grcd(int a, int b);

int main()
{
    int n, t;
    printf("enter 2 num ");
    scanf("%d%d", &n, &t);
    printf("the greates common divisor of %d and %d is %d\n", n, t, Grcd(n, t));
    return 0;
}

//greatest common divisor

 
int Grcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a;
    while (a != b)
        if (a > b)
            a = a - b;
        else 
            b = b - a; 
    return a;
}
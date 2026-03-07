#include <stdio.h> 

int total(int n);

int main()
{
    int num;
    do
    {
        printf("enter num ");
        scanf("%d", &num);
    } while (num < 0);
    printf("result: %d\n", total(num));
    return 0;
    
}

int total(int n)
{
    int S, i; 
    S = 0;
    for (i = 1; i <= n; i++)
    {
        S = S + i;
    }
    return S;
}
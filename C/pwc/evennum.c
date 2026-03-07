#include <stdio.h>

int isthatyou(int n);

int main()
{
    int num, i;
    printf("enter num ");
    scanf("%d", &num);
    i = isthatyou(num);
    if (i == 1)
        printf("that is the even number\n");
    else 
        printf("that is not the even number\n"); 
    return 0;
}

int isthatyou(int n)
{
    if (n % 2 == 0)
        return 1;
    else 
        return 0;
}
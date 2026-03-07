#include <stdio.h> 
int total(int num);
int main()
{
    int n;
    do
    {
        printf("enter the number ");
        scanf("%i", &n);
    } while (n < 0);
    
    printf("total is %d\n", total(n));
    return 0;
}

int total(int num)
{
    int total, digit;
    total = 0;
    while (num > 0)
    {
       digit = num % 10;
       total = total + digit; 
       num = num / 10; 
    }
    return total;
}
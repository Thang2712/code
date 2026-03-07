#include <stdio.h> 

int length(int num);

int main()
{
    int n;
    do
    {
        printf("enter the num ");
        scanf("%i", &n);
    } while (n < 0);
    printf("the length of number is %d\n", length(n));
    return 0;
}

int length(int num)
{
    int count; 
    count = 0;
    while (num > 0)
    {
        count = count + 1; 
        num = num / 10;
    }
    return count;
}
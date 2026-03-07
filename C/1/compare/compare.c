#include <stdio.h> 

int main(void)
{
    // Input X
    int x;
    printf("What's x?  ");
    scanf("%d", &x);

    // Input y
    int y; 
    printf("What's y?  ");
    scanf("%d", &y);

    // Compare

    if ( x > y )
    {
        printf("x is greater than y\n");
    }
    else if ( x < y )
    {
        printf("x is less than y\n");
    }
    else 
    {
        printf("x is equal to y\n");
    }
}
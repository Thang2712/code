#include <stdio.h> 

void pyramid(int height);
int main(void)
{
    // prompt the user's for the pyramid's height
    int n;
    do 
    {
        printf("Height: ");
        scanf("%d", &n);
    }
    while( n < 1 || n > 10 );

    

    // Call 
    pyramid(n);
}

void pyramid(int height) 
{  
     // make a loop 
    for (int i = 1; i <= height; i++)
    {
        for (int space = 0; space <= height - i; space++ )
        {
            printf(" ");
        }
        for (int hash = 0; hash < i; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}   
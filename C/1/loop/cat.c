#include <stdio.h> 

int main(void)
{
    // Input 
    int x;
    printf("How times do you want to see the word \"moew\"? ");
    scanf("%d", &x);

    //Loop
    while ( x > 0 )
    {
        printf("moew\n");
        x--;
    }
}
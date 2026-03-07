#include <stdio.h> 

int main(void)
{
    char x;
    
        printf("Do you agree with this? [y]: agreed or [n]: not agreed: ");
        scanf("%c", &x);
    if ( x == 'y' || x == 'Y')
    {
        printf("Agreed\n");
    }
    else if ( x == 'n' || x == 'N')
    {
        printf("Not agreed\n");
    }
    else 
    {
        printf("lmao");
    }

}
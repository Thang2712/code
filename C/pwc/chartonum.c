#include <stdio.h> 

int chartonum(char c);

int main()
{
    char character;
    printf("enter character ");
    scanf("%c", &character);
    printf("ASCII: %d\n", chartonum(character));
    return 0;
}

int chartonum(char c)
{
    int k; 
    k = (int) c;
    return k;
}

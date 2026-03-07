#include <stdio.h> 

void(meow(int times));
int main(void)
{
    int x;
    printf("How times do you want to see the word \"moew\" ?");
    scanf("%d", &x); 

    meow(x);
    return 0;
}
void(meow(int times))
{
    for (int i = 0; i < times; i++)
    {
        printf("moew\n");
    }
}
#include <stdio.h>
#include <math.h>

float cycle(float l);

int main()
{
    float l;
    do
    {
        printf("enter your length ");
        scanf("%f", &l);
    } while (l < 0);
    
    printf("the answer is %.2f\n", cycle(l));
    return 0;
}

float cycle(float l)
{
    float g, T; 
    float const pi = 3.14; 
    g = 10;
    T = 2 * pi * pow(l/g,1/2);
    return T;
}
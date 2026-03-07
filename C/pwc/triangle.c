#include <stdio.h> 
#include <math.h>

float Area(float a, float b, float c);

int main()
{
    float a, b, c;
    do
    {
        printf("enter 3 sides of the triangle ");
        scanf("%f%f%f", &a, &b, &c);
    } while (a < 0 || b < 0 || c < 0 || a + b < c || a + c < b || b + c < a);
    
    printf("the area of the triangle is %.2f\n", Area(a, b, c));
    return 0;

}

float Area(float a, float b, float c)
{
    float p, S; 
    p = (a + b + c) / 2;
    S = pow(p * (p - a) * (p - b) * (p - c), 1.0/2 );
    return S; 
}
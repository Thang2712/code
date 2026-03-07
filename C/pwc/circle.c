#include <stdio.h> 

float AreaCircle(float radius);


int main()
{
    float radius;
    do
    {
        printf("enter radius ");
        scanf("%f", &radius); 
    } while (radius < 0);
    
    printf("the area of the circle is %.2f\n", AreaCircle(radius));
    return 0;
}

float AreaCircle(float radius)
{
    const float pi = 3.14; 
    float S;
    S = pi * radius * radius;
    return S;
}
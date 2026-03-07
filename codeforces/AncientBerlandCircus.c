/**
 *      author: teejaze
 **/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI 3.14159265358979323846

typedef struct
{
    double a;
    double b; 
    double c;
} TriangleSides;

typedef struct
{
    double x; 
    double y;
} POINTS;

TriangleSides get_lengths(POINTS p[])
{
    TriangleSides side; 
    side.a = sqrt(pow(p[1].x - p[2].x, 2) + pow(p[1].y - p[2].y, 2));
    side.b = sqrt(pow(p[0].x - p[2].x, 2) + pow(p[0].y - p[2].y, 2)); 
    side.c = sqrt(pow(p[0].x - p[1].x, 2) + pow(p[0].y - p[1].y, 2));
    
    return side;
}

double gcd_float(double a, double b)
{
    if (fabs(b) < 1e-4)
        return a;
    return gcd_float(b, fmod(a, b));
}

double clamp(double v)
{
    if (v < -1.0)
        return -1.0;
    if (v > 1.0)
        return 1.0;
    return v; 
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        if (freopen(argv[1], "r", stdin) == NULL)
        {
            printf("can't open file %s \n", argv[1]);
            return 1; 
        }

    if (argc > 2)
        freopen(argv[2], "w", stdout); 


   POINTS p[3]; 
   int i; 
   double semi, S, R;
   double angle_a, angle_b, angle_c;
   double alpha, area; 

   for (i = 0; i < 3; i++)
       if (scanf("%lf %lf", &p[i].x, &p[i].y) != 2)  
           break;

   TriangleSides sides = get_lengths(p); 

   semi = (sides.a + sides.b + sides.c) / 2.0;
   S = sqrt(semi * (semi - sides.a) * (semi - sides.b) * (semi - sides.c));
   R = (sides.a * sides.b * sides.c) / (4.0 * S); 
    

   angle_a = 2.0 * acos(clamp((sides.b * sides.b + sides.c * sides.c - sides.a * sides.a) / (2.0 * sides.b * sides.c)));
   angle_b = 2.0 * acos(clamp((sides.a * sides.a + sides.c * sides.c - sides.b * sides.b) / (2.0 * sides.a * sides.c))); 
   angle_c = 2.0 * acos(clamp((sides.a * sides.a + sides.b * sides.b - sides.c * sides.c) / (2.0 * sides.a * sides.b)));


   alpha = gcd_float(angle_a, gcd_float(angle_b, angle_c)); 
   area = ((2.0 * PI / alpha) * R * R * sin(alpha)) / 2.0; 

   printf("%.6f", area); 

    return 0;







}

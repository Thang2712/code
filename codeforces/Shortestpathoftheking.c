/*
 *      author: teejaze
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    char s[3], t[3]; 
    char x1, x2, y1, y2;
    int dx, dy, n;
    if (scanf("%2s %2s", s, t) != 2)
        return 0 ;
    
    x1 = s[0]; 
    y1 = s[1]; 
    x2 = t[0]; 
    y2 = t[1]; 

    dx = abs(x1 - x2); 
    dy = abs(y1 - y2); 
    n = (dx > dy) ? dx : dy; 

    printf("%d\n", n); 

    while (x1 != x2 || y1 != y2)
    {
        if (x1 < x2)
        {
            printf("R"); 
            x1++;
        }
        else 
            if (x1 > x2)
            {
                printf("L"); 
                x1--;
            }
        if (y1 < y2)
        {
            printf("U");
            y1++;
        }
        else 
            if (y1 > y2)
            {
                printf("D"); 
                y1--;
            }
        printf("\n");
    }


    return 0;
}

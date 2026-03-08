/*
 *      author: teejaze
 */

#include <stdio.h> 

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

    int w; 
    scanf("%d", &w);

    if (w > 2 && w % 2 == 0)
        printf("Yes");
    else 
        printf("No");
}

/*
 *      author: teejaze
 */

#include <stdio.h> 
#include <stdlib.h> 

void solve()
{
    int d, sumTime; 
    if (scanf("%d %d", &d, &sumTime) != 2)
        return;

    int minT[35], maxT[35];
    int total_min = 0, total_max = 0; 

    for (int i = 0; i < d; i++)
    {
        if (scanf("%d %d", &minT[i], &maxT[i]) != 2)
            break;
        total_min += minT[i]; 
        total_max += maxT[i];
    }

    if (sumTime < total_min || sumTime > total_max)
    {
        printf("NO\n"); 
        return;
    }

    printf("YES\n"); 
    
    int extra = sumTime - total_min; 
    int *schedule = (int *)malloc(d * sizeof(int)); 

    for (int i = 0; i < d; i++)
    {
        schedule[i] = minT[i]; 
        if (extra > 0)
        {
            int can_add = maxT[i] - minT[i]; 
            int add = (extra < can_add) ? extra : can_add; 

            schedule[i] += add; 
            extra -= add; 
        }
    }
    
    for (int i = 0; i < d; i++)
        printf("%d%c", schedule[i], (i == d - 1) ? '\n' : ' ');
    
    free(schedule);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (freopen(argv[1], "r", stdin) == NULL)
        {
            fprintf(stderr, "can't open file %s \n", argv[1]);
            return 1; 
        }
    }

    if (argc > 2)
    {
        if (freopen(argv[2], "w", stdout) == NULL)
        {
            fprintf(stderr, "can't open output file %s \n", argv[2]);
            return 1;
        }
    }
    
    solve(); 
    return 0;
}


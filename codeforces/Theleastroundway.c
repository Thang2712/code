/*
 *      author: teejaze
 */




#include <stdio.h> 
#include <string.h> 

#define MAXN 1001 
#define INF 1e9

int f2[MAXN][MAXN], f5[MAXN][MAXN]; 
int dp[MAXN][MAXN];
char path_dir[MAXN][MAXN];

int count_factors(int n, int p)
{
    int count;
    if (n <= 0)
        return 0; 
    count = 0; 
    while (n % p == 0)
    {
        count++; 
        n /= p; 
    }
    return count; 
}

void run_dp(int n, int costs[MAXN][MAXN])
{
    int i, j;
    int up, left;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == 0 && j == 0)
                dp[i][j] = costs[i][j];
            else 
            {
                up = (i > 0) ? dp[i - 1][j] : INF;
                left = (j > 0) ? dp[i][j - 1] : INF;
                
                if (up < left)
                {
                    dp[i][j] = up + costs[i][j];
                    path_dir[i][j] = 'D';
                }
                else 
                {
                    dp[i][j] = left + costs[i][j]; 
                    path_dir[i][j] = 'R';
                }
            }
        }

void print_path(int r, int c)
{
    if (r == 0 && c == 0)
        return; 
    if (path_dir[r][c] == 'D')
    {
        print_path(r - 1, c);
        putchar('D');
    }
    else
    {
        print_path(r, c - 1); 
        putchar('R');
    }
}

void solve()
{
    int n, zero_r, zero_c; 
    int i, j;
    int val;
    if (scanf("%d", &n) != 1)
        return; 
    zero_r = -1; 
    zero_c = -1; 
    
    for (i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%d", &val); 
            if (val == 0)
            {
                zero_r = i; 
                zero_c = j;
                f2[i][j] = f5[i][j] = 1;
            }
            else 
            {
                f2[i][j] = count_factors(val, 2);
                f5[i][j] = count_factors(val, 5);
            }
        }

    run_dp(n, f2); 
    int res2 = dp[n - 1][n - 1];
    static char path2[MAXN][MAXN];
    memcpy(path2, path_dir, sizeof(path_dir)); 

    run_dp(n, f5); 
    int res5 = dp[n - 1][n - 1]; 
    int min_val = (res2 < res5) ? res2 : res5; 

    if (zero_r != -1 && min_val > 1)
    {
        printf("1\n"); 
        for (i = 0; i < zero_r; i++)
            putchar('D'); 
        for (i = 0; i < n - 1; i++)
            putchar('R'); 
        for (i = zero_r; i < n - 1; i++)
            putchar('D'); 
        putchar('\n');
    }
    else 
    {
        printf("%d\n", min_val); 
        if (res2 < res5)
        {
            memcpy(path_dir, path2, sizeof(path_dir)); 
            print_path(n - 1, n - 1); 
        }
        else 
            print_path(n - 1, n - 1);
        putchar('\n'); 
    }
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


    solve(); 

    return 0;
}

#include <stdio.h>

long long Threatresquare(long long m, long long n, long long a)
{
    long long resn, resm; 
    resn = (n + a - 1) / a;
    resm = (m + a - 1) / a;

    return resn * resm;
}

int main()
{
    long long a, m, n; 
    if (scanf("%lld %lld %lld", &n, &m, &a) == 3)
    {
        long long res = Threatresquare(m, n, a);
        printf("%lld \n", res);
    }

    return 0;
    


}

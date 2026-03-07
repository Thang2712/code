#include <stdio.h> 

int Grcd(int a, int b);
void plus(int t1, int m1, int t2, int m2, int *t, int *m);
void reduce(int *t, int *m);

int main()
{
    int t1, m1, t2, m2, t, m, a;
    printf("enter first fraction ");
    scanf("%d%d", &t1, &m1);
    printf("enter second fraction ");
    scanf("%d%d", &t2, &m2);

    plus(t1, m1, t2, m2, &t, &m);
    reduce(&t, &m);

    if (m == 1)
        printf("result: %d\n", t);
    else 
        printf("result: %d / %d\n", t, m);
    return 0;
}

int Grcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a;
    while (a != b)
        if (a > b)
            a = a - b;
        else 
            b = b - a; 
    return a;
}

void plus(int t1, int m1, int t2, int m2, int *t, int *m)
{
    *t = t1 * m2 + t2 * m1;
    *m = m1 * m2;
}

void reduce(int *t, int *m)
{
    int a;
    a = Grcd(*t, *m);
    *t = *t / a;
    *m = *m / a;
}
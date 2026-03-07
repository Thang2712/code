/*
 *      author: teejaze
 */




#include <stdio.h> 
#include <math.h> 

struct Stadium
{
    double x, y, r;
};

double get_dist(double px, double py, double sx, double sy)
{
    double dx, dy ; 
    dx = px - sx; 
    dy = py - sy; 
    return sqrt(dx * dx + dy * dy);
}

double get_err(double px, double py, struct Stadium s[3])
{
    double ratios[3]; 
    int i;
    double err, diff;
    for (i = 0; i < 3; i++)
        ratios[i] = get_dist(px, py,s[i].x, s[i].y) / s[i].r ;
    err = 0;  
    for (i = 0; i < 3; i++)
    {
        diff = ratios[i] - ratios[(i + 1) % 3]; 
        err += diff * diff; 
    }
    
    return err;
}

void solve(struct Stadium s[3])
{
    double cur_x, cur_y; 
    int i, iter, found_better;
    double step, cur_err;
    double nx, ny, new_err; 

    cur_x = 0; 
    cur_y = 0; 
    
    for (i = 0; i < 3; i++)
    {
        cur_x += s[i].x ; 
        cur_y += s[i].y ; 
    }
    cur_x /= 3.0; 
    cur_y /= 3.0; 

    step = 1.0; 
    cur_err = get_err(cur_x, cur_y, s); 
    double dx[] = {1, -1, 0, 0}; 
    double dy[] = {0, 0, 1, -1}; 

    for (iter = 0; iter < 100000; iter++)
    {
        found_better = 0; 
        for (i = 0; i < 4; i++)
        {
            nx = cur_x + dx[i] * step; 
            ny = cur_y + dy[i] * step; 
            new_err = get_err(nx, ny, s); 

            if (new_err < cur_err)
            {
                cur_err = new_err;
                cur_x = nx; 
                cur_y = ny; 
                found_better = 1;
            }
        }
        
        if (!found_better)
            step /= 1.5; 
        if (step < 1e-7)
            break; 
    }

    if (cur_err < 1e-6)
        printf("%.5f %.5f", cur_x, cur_y);
}


int main(int argc, char *argv[])
{
    int i; 
    struct Stadium s[3];

    if (argc > 1)
        if (freopen(argv[1], "r", stdin) == NULL)
        {
            printf("can't open file %s \n", argv[1]);
            return 1; 
        }

    if (argc > 2)
        freopen(argv[2], "w", stdout); 
    
    
    for (i = 0; i < 3; i++)
        if (scanf("%lf %lf %lf", &s[i].x, &s[i].y, &s[i].r) != 3)
            return 0; 
    
    solve(s); 
    return 0; 
}

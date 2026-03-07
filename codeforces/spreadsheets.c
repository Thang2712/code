#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s)
{
    int len, i; 
    char temp;
    len = strlen(s); 
    for(i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

}

void solve()
{
    char s[100]; 
    scanf("%s", s); 
    

    int r, c, IsRxCy; 
    IsRxCy = 0; 
    if (s[0] == 'R' && isdigit(s[1]))
    {
        char *c_ptr = strchr(s + 2, 'C');
        if (c_ptr)
            IsRxCy = 1;
    }

    if (IsRxCy)
    {
        int p, rem;
        sscanf(s, "R%dC%d", &r, &c);
        char col_str[20] = {0};
        p = 0; 
        while (c > 0)
        {
            rem = (c - 1) % 26; 
            col_str[p++] = rem + 'A'; 
            c = (c - 1) / 26;
        }
        reverse(col_str); 
        printf("%s%d\n", col_str, r);
    }
    else 
    {
        int i, j; 
        long long col_num;
        char col_str[20] = {0}; 
        i = 0; 
        while (isalpha(s[i]))
        {
            col_str[i] = s[i]; 
            i++;
        }
        int row = atoi(&s[i]); 
        
        col_num = 0;
        for (j = 0; j < strlen(col_str); j++)
            col_num = col_num * 26 + (col_str[j] - 'A' + 1); 
        printf("R%dC%lld\n", row, col_num); 
    }
}

int main()
{
    int n; 

    if (scanf("%d", &n) != 1)
        return 0;
    while(n--)
        solve();
    return 0;

}

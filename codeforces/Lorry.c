/*
 *      author: teejaze
 */
 
 
 
#include <stdio.h> 
#include <stdlib.h>
typedef struct
{
    int weight; 
    int id;
} Boat; 

int compareboats(const void *a, const void *b)
{
    Boat *boatA = (Boat *)a;
    Boat *boatB = (Boat *)b;
    
    if (boatB->weight > boatA->weight) return 1;
    if (boatB->weight < boatA->weight) return -1;
    return 0;
}
 
long long* buildprefixsum(Boat *boats, int count)
{
    int i;
    long long *pref = (long long *)calloc(count + 1, sizeof(long long)); 
    
    for (i = 0; i < count; i++)
        pref[i + 1] = pref[i] + boats[i].weight; 
 
    return pref;
}
 
void solve(int v, Boat *kayaks, int k_count, Boat *catamarans, int c_count)
{
    qsort(kayaks, k_count, sizeof(Boat), compareboats); 
    qsort(catamarans, c_count, sizeof(Boat), compareboats); 
 
    long long max_capacity, best_c, best_k; 
    int i, vol_used_c, vol_rem, num_k, first;
 
 
    long long *pref_k = buildprefixsum(kayaks, k_count); 
    long long *pref_c = buildprefixsum(catamarans, c_count); 
 
    max_capacity = 0; 
    best_c = 0; 
    best_k = 0;
 
 
    for (i = 0; i <= c_count; i++)
    {
        vol_used_c = i * 2; 
        if (vol_used_c > v)
            break; 
 
        vol_rem = v - vol_used_c; 
        num_k = (vol_rem < k_count) ? vol_rem : k_count; 
 
        long long cur_cap = pref_c[i] + pref_k[num_k];
 
        if (cur_cap > max_capacity)
        {
            max_capacity = cur_cap; 
            best_c = i; 
            best_k = num_k;
        }
        
    }
    
    printf("%lld\n", max_capacity); 
    
    first = 1; 
    for (i = 0; i < best_c; i++)
    {
        printf("%s%d", first ? "" : " ", catamarans[i].id);
        first = 0;
    }
    for (i = 0; i < best_k; i++)
    {
        printf("%s%d", first ? "" : " ", kayaks[i].id); 
        first = 0;
    }
    printf("\n"); 
 
 
    free(pref_k); 
    free(pref_c); 
 
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
 
    int n, v, i, k_count, c_count; 
 
    if (scanf("%d %d", &n, &v) != 2)
        return 0; 
 
    Boat *kayaks = malloc(n * sizeof(Boat)); 
    Boat *catamarans = malloc(n * sizeof(Boat)); 
 
    k_count = 0; 
    c_count = 0; 
 
    for (i = 0; i < n; i++)
    {
        int type, p; 
        scanf("%d %d", &type, &p); 
        if (type == 1)
        {
            kayaks[k_count].weight = p; 
            kayaks[k_count].id = i + 1; 
            k_count++;
        }
        else 
        {
            catamarans[c_count].weight = p; 
            catamarans[c_count].id = i + 1;
            c_count++;
        }
    }
 
 
    solve(v, kayaks, k_count, catamarans, c_count);
 
    free(kayaks);
    free(catamarans);
} 

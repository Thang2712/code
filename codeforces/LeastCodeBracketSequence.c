#include <stdio.h> 
#include <string.h> 

#define MAXN 1000005

typedef struct
{
    int diff; 
    int pos;
} Node; 

Node heap[MAXN]; 
int heap_size = 0; 

char s[MAXN]; 
int a[MAXN], b[MAXN];

void swap(Node *a, Node *b)
{
    Node t; 
    t = *a ; 
    *a = *b; 
    *b = t;
}

void heap_push(int diff, int pos)
{
    int i;
    heap[++heap_size].diff = diff; 
    heap[heap_size].pos = pos;
    
    i = heap_size; 
    while (i > 1 && heap[i].diff < heap[i / 2].diff)
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2; 

    }

}

Node heap_pop()
{
    Node top;
    int i, left, right, smallest;

    top = heap[1]; 
    heap[1] = heap[heap_size--]; 

    i = 1; 
    
    while(1)
    {
        left = i * 2; 
        right = i * 2 + 1; 
        smallest = i; 

        if (left <= heap_size && heap[left].diff < heap[smallest].diff)
            smallest = left; 
        if (right <= heap_size && heap[right].diff < heap[smallest].diff)
            smallest = right; 
        
        if (smallest == i)
            break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;

}

void read_input(int argc, char *argv[])
{

    if (argc > 1)
    {
        if (freopen(argv[1], "r", stdin) == NULL)
        {
            printf("can't open file %s \n", argv[1]);
        }
    }

    if (argc > 2)
        freopen(argv[2], "w", stdout); 
}

void solve()
{
    int n, i, balance, q_index;
    long long cost;

    if (scanf("%s", s) == EOF) return; 
    n = strlen(s);
    
    q_index = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            scanf("%d %d", &a[q_index], &b[q_index]);
            q_index++;
        }
    }

    cost = 0; 
    balance = 0; 
    q_index = 0; 

    for (i = 0; i < n; i++)
    {
        if (s[i] == '(')
            balance++;
        else if (s[i] == ')')
            balance--; 
        else 
        {
            cost += b[q_index];
            balance--;
            heap_push(a[q_index] - b[q_index], i);
            s[i] = ')';
            q_index++;
        }

        if(balance < 0)
        {
            if (heap_size == 0)
            {
                printf("-1\n");
                return;
            }

            Node x = heap_pop(); 
            cost += x.diff; 
            s[x.pos] = '(';
            balance += 2;
        }
    }

    if (balance != 0)
    {
        printf("-1\n");
        return;
    }

    printf("%lld\n", cost);
    printf("%s\n", s);
}


int main(int argc, char *argv[])
{
    read_input(argc, argv);
    solve();

    return 0;
}

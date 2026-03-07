/*
 *      author: teejaze
 */

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAX_N 1000
#define MAX_NAME 33

typedef struct
{
    char name[MAX_NAME];
    int score;
} Round; 

typedef struct
{
    char name[MAX_NAME]; 
    int total; 
    int current_score; 
} Player;

int get_player_index(Player players[], int *num_players, char *name)
{
    int i; 
    for (i = 0; i < *num_players; i++)
        if (strcmp(players[i].name, name) == 0 )
            return i ;

    strcpy(players[*num_players].name, name);
    players[*num_players].total = 0; 
    players[*num_players].current_score = 0; 
    (*num_players)++ ; 
    return (*num_players) - 1; 
}

int find_max_tol(Player players[], int num_players)
{
    int max_val, i; 
    max_val = -2e9;
    for (i = 0; i < num_players; i++)
        if (players[i].total > max_val)
            max_val = players[i].total;
    
    return max_val;
}

void process_game()
{
    int n;
    int num_players, i;
    int idx, m;
    if (scanf("%d", &n) != 1)
        return; 

    Round history[MAX_N];
    Player players[MAX_N];
    
    num_players = 0; 
    
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", history[i].name, &history[i].score);
        idx = get_player_index(players, &num_players, history[i].name);
        players[idx].total += history[i].score;
    }
    
    m = find_max_tol(players, num_players);

    for (i = 0; i < n; i++)
    {
        idx = get_player_index(players, &num_players, history[i].name);
        players[idx].current_score += history[i].score;
        
        if (players[idx].current_score >= m && players[idx].total == m)
        {
            printf("%s \n", players[idx].name);
            return;
        }
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

    process_game(); 
    return 0;
}

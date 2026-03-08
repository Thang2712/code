/*
 *      author: teejaze
 */


#include <stdio.h> 
#include <string.h> 

int check_win(char board[3][4], char c)
{
    int i; 
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return 1;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return 1;
    }

    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return 1; 
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return 1; 

    return 0;
}

const char* get_verdict(char board[3][4])
{
    int countX, count0, i, j, winX, win0;
    countX = 0; 
    count0 = 0; 
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == 'X')
                countX++;
            else if (board[i][j] == '0')
                count0++;

    winX = check_win(board, 'X');
    win0 = check_win(board, '0');

    if (countX < count0 || countX > count0 + 1) 
        return "illegal";
    if (winX && win0) 
        return "illegal";
    if (winX && countX != count0 + 1) 
        return "illegal";
    if (win0 && countX != count0) 
        return "illegal";

    if (winX) 
        return "the first player won";
    if (win0) 
        return "the second player won";

    if (countX + count0 == 9) 
        return "draw";
    if (countX == count0) 
        return "first";
    
    return "second";
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        if (freopen(argv[1], "r", stdin) == NULL)
        {
            printf("can't open the file %s \n", argv[1]);
            return 0;
        }
    if (argc > 2)
        freopen(argv[2], "w", stdout);

    char board[3][4];
    int i;

    for (i = 0; i < 3; i++) 
        if (scanf("%s", board[i]) != 1)
            break;

    printf("%s", get_verdict(board));

    return 0;
}



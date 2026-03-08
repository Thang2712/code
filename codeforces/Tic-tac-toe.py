"""
    author: teejaze
"""


import sys



def check_win(board, char):
    for i in range(3):
        if all(board[i][j] == char for j in range(3)): 
            return True
        if all(board[j][i] == char for j in range(3)): 
            return True
 
    if all(board[i][i] == char for i in range(3)): 
        return True
    if all(board[i][2 - i] == char for i in range(3)): 
        return True
    
    return False

def solve():

    data = sys.stdin.read().split()

    if not data:
        return

    board = data

    countX = sum(row.count('X') for row in board)
    count0 = sum(row.count('0') for row in board)

    winX = check_win(board, 'X')
    win0 = check_win(board, '0')

    res = ""
    if not (countX == count0 or countX == count0 + 1):
        res = "illegal"
    elif winX and win0:
        res = "illegal"
    elif winX and countX != count0 + 1:
        res = "illegal"
    elif win0 and countX != count0:
        res = "illegal"
    
    elif winX:
        res = "the first player won"
    elif win0:
        res = "the second player won"
    elif countX + count0 == 9:
        res = "draw"
    
    elif countX == count0:
        res = "first"
    else:
        res = "second"

    print(res, end="")

    sys.stdin.close()
    sys.stdout.close()

if __name__ == "__main__":
    solve()

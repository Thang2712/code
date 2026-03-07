"""
    author: teejaze
"""

import sys



def main():
    data = sys.stdin.read().split()

    if len(data) < 2: 
        return 
    
    s = data[0]
    t = data[1]

    x1, y1 = ord(s[0]), int(s[1])
    x2, y2 = ord(t[0]), int(t[1])

    moves = []

    while x1 != x2 or y1 != y2:
        res = ""

        if x1 < x2: 
            res += 'R'
            x1 += 1
        elif x1 > x2: 
            res += 'L'
            x1 -= 1

        if y1 < y2: 
            res += 'U'
            y1 += 1
        elif y1 > y2: 
            res += 'D'
            y1 -= 1
        moves.append(res)

    print(len(moves))
    for m in moves: 
        print(m)


if __name__ == "__main__": 
    main()

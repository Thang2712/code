"""
    author: teejaze
"""


import sys


def main():
    data = sys.stdin.read().split()

    if not data: 
        return 
    w = int(data[0])

    if w > 2 and w % 2 == 0: 
        print("Yes")
    else: 
        print("No")

if __name__ == "__main__": 
    main()

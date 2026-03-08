"""
    author: teejaze
"""


import sys
import heapq



def main(): 
    s = list(sys.stdin.readline().strip())
    
    if not s: 
        return 
    
    n = len(s)
    
    heap =[]
    cost = 0 
    balance = 0 

    q_index = 0
    costs = []

    for line in sys.stdin: 
        line = line.strip()
        if not line: 
            continue 
        a, b = map(int, line.split())
        costs.append((a, b))


    for i in range(n): 
        if s[i] == '(': 
            balance += 1
        elif s[i] == ')': 
            balance -= 1 
        else: 
            a, b = costs[q_index]
            q_index += 1
            
            cost += b
            balance -= 1

            heapq.heappush(heap, (a - b, i))
            s[i] = ')'
        
        if balance < 0: 
            if not heap: 
                print(-1)
                sys.exit()
            
            diff, pos = heapq.heappop(heap)

            cost += diff
            s[pos] = '('
            balance += 2

    if balance != 0: 
        print(-1)
    else: 
        print(cost)
        print("".join(s))

if __name__ == "__main__": 
    main()

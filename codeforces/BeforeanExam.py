import sys 

def main(): 
    data = sys.stdin.read().split()

    if not data: 
        return

    d = int(data[0])
    sumTime = int(data[1])

    min_limits = []
    max_limits = []

    idx = 2 
    for _ in range(d):
        min_limits.append(int(data[idx]))
        max_limits.append(int(data[idx + 1]))
        idx += 2 

    total_min = sum(min_limits)
    total_max = sum(max_limits)

    if total_min <= sumTime <= total_max:
        print("YES")

        schedule = list(min_limits)
        current_sum = total_min

        extra = sumTime - current_sum 

        for i in range(d):
            if extra <= 0:
                break 

            can_add = max_limits[i] - min_limits[i]
            add = min(extra, can_add)
            
            schedule[i] += add 
            extra -= add 

        print(*(schedule))

    else: 
        print("NO")
if __name__ == "__main__": 
    main()


            
        

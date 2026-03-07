"""
    author: teejaze
"""
import sys

def main():
    data = sys.stdin.read().split()
    if not data:
        return

    n = int(data[0])
    v = int(data[1])
    
    kayaks = []
    catamarans = []

    pointer = 2
    for i in range(1, n + 1):
        t = int(data[pointer])     
        p = int(data[pointer + 1]) 
        if t == 1:
            kayaks.append((p, i))      
        else:
            catamarans.append((p, i))
        pointer += 2

    kayaks.sort(key=lambda x: x[0], reverse=True)
    catamarans.sort(key=lambda x: x[0], reverse=True)

    pref_k = [0] * (len(kayaks) + 1)
    for i in range(len(kayaks)):
        pref_k[i + 1] = pref_k[i] + kayaks[i][0]

    pref_c = [0] * (len(catamarans) + 1)
    for i in range(len(catamarans)):
        pref_c[i + 1] = pref_c[i] + catamarans[i][0]

    max_capacity = 0
    best_config = (0, 0) 

    for i in range(len(catamarans) + 1):
        vol_used_c = i * 2
        if vol_used_c > v:
            break

        vol_rem = v - vol_used_c
        num_k = min(len(kayaks), vol_rem) 

        current_cap = pref_c[i] + pref_k[num_k]

        if current_cap > max_capacity:
            max_capacity = current_cap
            best_config = (i, num_k)

    print(max_capacity)
    
    res_ids = []
    for i in range(best_config[0]):
        res_ids.append(catamarans[i][1])
    for i in range(best_config[1]):
        res_ids.append(kayaks[i][1])
        
    print(*(res_ids))

if __name__ == "__main__":
    main()

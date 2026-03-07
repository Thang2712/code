import sys

def get_dist(px, py, sx, sy): 
    return ((px - sx) ** 2 + (py - sy) ** 2) ** 0.5

def get_error(px, py, stadiums): 
    ratios = []
    for s in stadiums: 
        d = get_dist(px, py, s[0], s[1])
        ratios.append(d / s[2])
    err = 0 
    for i in range(3): 
        err += (ratios[i] - ratios[(i + 1) % 3]) ** 2
    return err

def main():
    try: 
        input_data = sys.stdin.read().split()
        if not input_data: 
            return 
        stadiums = []
        for i in range(0, 9, 3): 
            x = float(input_data[i])
            y = float(input_data[i + 1])
            r = float(input_data[i + 2])
            stadiums.append((x, y, r))
    except (EOFError, IndexError): 
        return

    cur_x = sum(s[0] for s in stadiums) / 3.0
    cur_y = sum(s[1] for s in stadiums) / 3.0
    step = 1.0
    cur_error = get_error(cur_x, cur_y, stadiums)

    for _ in range(100000):
        found_better = False
        for dx, dy in [(step, 0), (-step, 0), (0, step), (0, -step)]:
            nx, ny = cur_x + dx, cur_y + dy
            new_error = get_error(nx, ny, stadiums)
            if new_error < cur_error: 
                cur_error = new_error 
                cur_x, cur_y = nx, ny
                found_better = True
        
        if not found_better: 
            step /= 1.5
        
        if step < 1e-7: 
            break 

    if cur_error < 1e-6: 
        print(f"{cur_x:.5f} {cur_y:.5f}")

if __name__ == "__main__": 
    main()

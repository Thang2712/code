import sys
import re 


def solve():
    input_data = sys.stdin.read().split()

    if not input_data:
        return 


    n = int(input_data[0])
    results = []

    rxcy_pattern = re.compile(r'^R(\d+)C(\d+)$')

    for i in range(1, n + 1): 
        s  = input_data[i]
        match = rxcy_pattern.match(s)

        if match: 
            row = match.group(1)
            col = int(match.group(2))
            res_col = ""

            while col > 0: 
                rem = (col - 1) % 26
                res_col += chr(ord('A') + rem)
                col = (col - 1) // 26 


            results.append(res_col[::-1] + row)
        else: 
            parts = re.findall(r'([A-Z]+)|(\d+)', s)

            col_str = parts[0][0]
            row_str = parts[1][1]

            col_num = 0 
            for char in col_str: 
                col_num = col_num * 26 + (ord(char) - ord('A') + 1 )
            results.append(f"R{row_str}C{col_num}")
    sys.stdout.write("\n".join(results) + "\n")\

if __name__ == "__main__": 
    solve()



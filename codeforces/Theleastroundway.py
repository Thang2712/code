import sys

class Solution: 
    def count_factor(self, num, p): 
        if num == 0: 
            return 1
        count = 0 
        while num > 0 and num % p == 0: 
            count += 1 
            num //= p 
        return count

    def get_path(self, dp, costs, n): 
        path = []
        i, j = n - 1, n - 1
        while i > 0 or j > 0: 
            if i > 0 and (j == 0 or dp[i][j] == dp[i-1][j] + costs[i][j]): 
                path.append('D')
                i -= 1 
            else: 
                path.append('R')
                j -= 1 
        return "".join(reversed(path))

    def solve(self, n, matrix): 
        zero_pos = None 
        f2 = [[0]*n for _ in range(n)]
        f5 = [[0]*n for _ in range(n)]

        for r in range(n): 
            for c in range(n): 
                if matrix[r][c] == 0: 
                    zero_pos = (r, c)
                    f2[r][c] = 1
                    f5[r][c] = 1
                else:
                    f2[r][c] = self.count_factor(matrix[r][c], 2)
                    f5[r][c] = self.count_factor(matrix[r][c], 5)

        def run_dp(costs): 
            dp = [[0] * n for _ in range (n)]
            for i in range (n): 
                for j in range(n): 
                    if i == 0 and j == 0: 
                        dp[i][j] = costs[i][j]
                    elif i == 0: 
                        dp[i][j] = dp[i][j-1] + costs[i][j]
                    elif j == 0: 
                        dp[i][j] = dp[i-1][j] + costs[i][j]
                    else: 
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + costs[i][j]
            return dp

        dp2 = run_dp(f2)
        dp5 = run_dp(f5)

        res2 = dp2[n-1][n-1]
        res5 = dp5[n-1][n-1]
        best_res = min(res2, res5)

        
        if zero_pos and best_res > 1: 
            r, c = zero_pos
            path = 'D' * r + 'R' * (n - 1) + 'D' * (n - 1 - r)
            return 1, path 

        if res2 < res5: 
            return res2, self.get_path(dp2, f2, n)
        else: 
            return res5, self.get_path(dp5, f5, n)

def main():
    
    input_data = sys.stdin.read().split()
    if not input_data: 
        return 

    n = int(input_data[0])
    matrix = []
    for i in range(n): 
        start = 1 + i * n
        row = [int(x) for x in input_data[start : start + n]]
        matrix.append(row)

    sol = Solution()
    ans_val, ans_path = sol.solve(n, matrix)

    sys.stdout.write(f"{ans_val}\n{ans_path}\n")

if __name__ == "__main__": 
    main()

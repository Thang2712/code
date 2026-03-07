class Solution: 
    def ThreatreSquare(self, n: int, m: int, a: int) -> int: 
        resn = (n + a - 1) // a
        resm = (m + a - 1) // a 
        return resn * resm

def main(): 
    n, m, a = map(int, input().split())
    sol = Solution()
    results = sol.ThreatreSquare(n, m, a)
    print(results)
if __name__ == "__main__": 
    main()


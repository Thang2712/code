import sys 
import math
# x1 -> arr[0]; x2 -> arr[2]; x3 -> arr[4]
class Solution:
    def Thelenght(self, arr): 
        a = math.sqrt((arr[2] - arr[4])**2 + (arr[3] - arr[5])**2)
        b = math.sqrt((arr[0] - arr[4])**2 + (arr[1] - arr[5])**2)
        c = math.sqrt((arr[0] - arr[2])**2 + (arr[1] - arr[3])**2)

        return a, b, c
    def menstruation(self, a, b, c): 
        p = (a + b + c) / 2 
        S = math.sqrt(p*(p - a)*(p - b)*(p - c))
        R = (a * b * c)/(4 * S) 
        return R
    def gcd_float(self, a, b):
        if b < 1e-4: 
            return a
        return self.gcd_float(b, a - math.floor(a/b) * b)
    def Angles(self, a, b, c):
        cos_A = (b**2 + c**2 - a**2) / (2 * b * c)
        cos_B = (a**2 + c**2 - b**2) / (2 * a * c) 
        cos_C = (a**2 + b**2 - c**2) / (2 * a * b)

        A = math.acos(max(-1.0, min(1.0, cos_A)))
        B = math.acos(max(-1.0, min(1.0, cos_B)))
        C = math.acos(max(-1.0, min(1.0, cos_C)))

        a1 = 2 * A 
        b1 = 2 * B
        c1 = 2 * C 

        return self.gcd_float(a1, self.gcd_float(b1, c1))








def main():
    input_data = sys.stdin.read().split()

    if not input_data: 
        return 
    points = [float(x) for x in input_data]

    if len(points) != 6:
        return

    sol = Solution()
    a, b, c = sol.Thelenght(points)
    R = sol.menstruation(a, b, c)
    alpha = sol.Angles(a, b, c)


    n = (2 * math.pi) / alpha
    area = (n / 2) * (R ** 2) * math.sin(alpha)

    print(f"{area:.6f}")
    

if __name__  == "__main__": 
    main()

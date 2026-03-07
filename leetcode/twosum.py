class Solution: 
    def twosum(self, nums: list[int], target: int) -> list[int]: 
        chain = {}
        for i, j in enumerate(nums): 
            result = target - j
            if result in chain: 
                return [chain[result], i]
            chain[j] = i 
def main(): 
    try: 
        sol = Solution()
        us_ip = input("enter a list of integers seperated by spaces ")
        us_arr = [int(x) for x in us_ip.split()]

        target = int(input("enter your target "))

        if len(us_arr) == 0:
            print("this is an empty array") 
        else: 
            check = sol.twosum(us_arr, target)
            print(check)
    except ValueError: 
        print("please enter valid integers that seperated by spaces")
if __name__ == "__main__": 
    main()


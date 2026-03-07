class Solution: 
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)): 
                if nums[j] == target - nums[i]:
                    return [i, j]
        return []


def main(): 
    try: 
        sol = Solution()
        us_ip = input("enter a list of integers that separated spaces ")
        us_arr = [int(x) for x in us_ip.split()]
        target = int(input("enter your target"))

        if len(us_arr) == 0: 
            print("this is an empty array ")
        else: 
            check = sol.twoSum(us_arr, target)
            print(check)
    except ValueError: 
        print("please enter only valid integers saparated spaces ")


if __name__ == "__main__": 
    main()

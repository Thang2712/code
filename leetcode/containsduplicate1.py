class Solution: 
    def containsduplicate(self, nums: list[int]) -> bool: 
        return len(nums) != len(set(nums))

def main():
    sol = Solution()
    try:
        us_ip = input("enter a list of integers separated by spaces ")
        us_arr = [int(x) for x in us_ip.split()]

        if not us_arr: 
            print("this is empty array")
        else: 
            check = sol.containsduplicate(us_arr) 
            if check: 
                print("true")
            else:
                print("false")
    except ValueError: 
        print("please enter valid integers")
if __name__ == "__main__": 
    main()

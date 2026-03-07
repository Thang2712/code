import heapq

from collections import Counter 

class Solution: 
    def topFrequent(self, nums: list[int], k: int) -> list[int]: 
        if k == len(nums): 
            return nums 
        count = Counter(nums)

        return heapq.nlargest(k, count.keys(), key = count.get)
       

def main(): 
    try: 
        us_ip = input("enter a list of integers that separated by spaces ")
        us_arr = [int(x) for x in us_ip.split()]
        
        k = int(input("what is your most frequent elements "))

        sol = Solution()

        result = sol.topFrequent(us_arr, k)

        print(result)
    except ValueError:
        print("please print only valid integers ")
if __name__ == "__main__": 
    main()



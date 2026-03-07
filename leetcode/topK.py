import heapq 


class Solution: 
    def topKFrequent(self, nums: list[int], k : int) -> list[int]: 
        if k == len(nums): 
            return nums
        heap = []
        hs = {}

        for i in nums: 
            hs[i] = hs.get(i, 0) + 1
        for i in hs.keys(): 
            heapq.heappush(heap, (-hs[i], i))

        res = []

        for i in range(k): 
            count, number = heapq.heappop(heap)
            res.append(number)
        return res



def main(): 
    try: 
        us_ip = input("enter a list of integers that separated by spaces ")
        us_arr = [int(x) for x in us_ip.split()]
        
        k = int(input("what is your most frequent elements "))

        sol = Solution()

        result = sol.topKFrequent(us_arr, k)
        print(result)
    except ValueError:
        print("please print only valid integers ")
if __name__ == "__main__": 
    main()


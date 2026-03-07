from collections import defaultdict


class Solution: 
    def groupAnagrams(self, strs: list[str] ) -> list[list[str]]: 
        ans = defaultdict(list)

        for s in strs: 
            key = "".join(sorted(s))
            ans[key].append(s)

        return list(ans.values())

def main(): 
    try: 
        us_ip = input("enter your words ")
        input_list = us_ip.split()

        sol = Solution()
        result = sol.groupAnagrams(input_list)

        print("input: ", input_list)
        print("output: ", result)

    except Exception:
        pass
if __name__ == "__main__":
    main()


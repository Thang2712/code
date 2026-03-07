from collections import Counter

class Solution:
    def Anagram(self, t: str, s: str) -> bool: 
        if len(t) != len(s): 
            return False
        return Counter(t) == Counter(s)

    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        res = []
        visited = [False] * len(strs)

        for i in range(len(strs)):
            if visited[i]:
                continue
            
            current_group = [strs[i]]
            visited[i] = True
            
            for j in range(i + 1, len(strs)):
                if not visited[j] and self.Anagram(strs[i], strs[j]):
                    current_group.append(strs[j])
                    visited[j] = True
            
            res.append(current_group)
        
        return res 
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


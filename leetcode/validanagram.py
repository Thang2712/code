class Solution: 
    def isAnagram(self, s: str, t: str) -> bool: 
        if len(s) != len(t): 
            return False    
        counter= {}
        
        for char in s:
            counter[char] = counter.get(char, 0) + 1 

        for char in t: 
            if char not in counter or counter[char] == 0: 
                return False
            counter[char] -= 1 

        return True

def main():
    sol = Solution()
    
    s = input("enter the first string ")
    t = input("enter the second string ")

    result = sol.isAnagram(s, t)

    if result: 
        print("this is a anagram")
    else: 
        print("this is not a anagram")

if __name__ == "__main__": 
    main()

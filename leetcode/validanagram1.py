from collections import Counter

class Solution: 
    def isAnagram(self, s: str, t: str): 
        if len(s) != len(t): 
            return False 
        
        return Counter(s) == Counter(t)

def main(): 
    try: 
        sol = Solution()
        
        t = input("enter the first string ")
        s = input("enter the second string")

        result = sol.isAnagram(s, t)

        if result: 
            print("this is a anagram")
        else: 
            print("this is not a anagram")
    except ValueError as e: 
        print(f"An error occured: {e} ")
if __name__ == "__main__": 
    main()



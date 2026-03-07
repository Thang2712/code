class Solution: 
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]: 
        if len(strs) == 0: 
            return []

        sortedStrings = [''.join(sorted(s)) for s in strs]
        indices = [i for i in range(len(strs))]
        indices.sort(key = lambda x : sortedStrings[x])

        result = []
        currentAnagramList = []
        currentAnagram = sortedStrings[indices[0]]

        for i in indices: 
            string = strs[i]
            sortedStrings =  sortedStrings[i]

            if sortedStrings == currentAnagram: 
                currentAnagramList.append(string)
                continue
            result.append(currentAnagramList)
            currentAnagramList = [string]
            currentAnagram = sortedStrings

        result.append(currentAnagramList)

        
        return result
        

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


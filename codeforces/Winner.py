'''
    author : teejaze
'''

import sys
class Solution: 
    def __init__(self): 
        self.history = []
        self.final_score = {}

    def get_winner(self, data): 
        n = int(data[0])
        ptr = 1

        for _ in range (n): 
            name = data[ptr]
            score = int(data[ptr + 1]) 
            self.history.append((name, score))
            self.final_score[name] = self.final_score.get(name, 0) + score
            ptr += 2 

        max_score = max(self.final_score.values())


        current_scores = {}
        for name, score in self.history: 
            current_scores[name] = current_scores.get(name, 0) + score 

            if current_scores[name] >= max_score and self.final_score[name] == max_score: 
                return name




def main():
    input_data = sys.stdin.read().split()

    if not input_data: 
        return 
   
    sol = Solution()
    winner = sol.get_winner(input_data)

    if winner: 
       print(winner)

if __name__ == "__main__": 
    main()

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        letters = set(brokenLetters)   
        count = 0

        for word in words:
            can_type = True
            for letter in letters:
                if letter in word:
                    can_type = False
                    break
            if can_type:
                count += 1

        return count

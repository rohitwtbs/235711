class Vowel:
    def __init__(self,str):
        self.str = str

    def count(self):
        count = 0
        for characters in self.str:
            if characters in ['a','e','i','o','u']:
                count = count + 1
        return count
        :q

word = Vowel('rohit only')
print(word.count())
print('whether the difference tool made any sense')

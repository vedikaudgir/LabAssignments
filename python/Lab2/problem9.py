#9. Write a Python program that accepts a word from the user and reverse it. (Without word[::-1])
#Author - Vedika Udgir

word = input("Enter a word: ")
reversedWord = ""

for c in word:
    reversedWord = c + reversedWord

print(reversedWord)

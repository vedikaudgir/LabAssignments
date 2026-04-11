#2. Write a Python program to find the list of words that are longer than n from a given list of words.
# Author - Vedika Udgir

inputString = input("Enter a string: ")
words = inputString.split(' ')

nWords = [i for i in words if len(i) > 3]
print(nWords)
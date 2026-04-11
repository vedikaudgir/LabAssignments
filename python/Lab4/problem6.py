#6. Write a Python program to sort a list of words by their frequency (highest first)
#Author - Vedika Udgir

string = "Hello my name is Python"

words = string.split(" ")

words.sort(key = len)

print(words)
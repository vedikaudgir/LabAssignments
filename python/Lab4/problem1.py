#1. Write a Python program to find all the values in a list are greater than a specified number. (Use list comprehension)
# Author - Vedika Udgir

list = [2,34,56,78,90,45,1,9,62,40,0]

newList = [i for i in list if i >= 40]

print(newList)
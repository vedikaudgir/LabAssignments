#3. Write a Python program to print the numbers of a specified list after removing even numbers from it. 
#Author - Vedika Udgir

list = [2, 5, 8, 445, 89, 29, 10, 200, 5, 3, 9, 0, 1, 99, 7]

evenList = [i for i in list if i % 2 != 0]
print(evenList)
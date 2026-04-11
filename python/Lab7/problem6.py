#Define a function which can generate a list where the values are square of numbers between 1 and 20 (both included). Then the function needs to print the first 5 elements in the list.
#Author - Vedika Udgir

def myList():
    myList = [num**2 for num in range(1, 21)]
    return myList[:5]

print(myList())
#5. Define a function which can print a dictionary where the keys are numbers between 1 and 20 (both included) and the values are square of keys.
#Author - Vedika Udgir

def printDictionary():
    myDict = {num : num**2 for num in range(1, 21)}
    return myDict

print(printDictionary())
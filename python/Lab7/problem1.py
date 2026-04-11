#1. Define a function that can receive two integer numbers form user and compute their sum and then print it on console.
#Author - Vedika Udgir

def sum(num1, num2):
    if not isinstance(num1, int):
        return TypeError("Enter an Integer Number!")
    if not isinstance(num2, int):
        return TypeError("Enter an Integer Number!")
    
    return num1+num2

print(sum(2.4,8.9))
print(sum(2,8.9))
print(sum(2.4,8))
print(sum(2,8))

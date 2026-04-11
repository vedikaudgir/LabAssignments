#5. Write a Python program that accepts a string and calculate the number of digits and letters. (Hint: c.isdigit() and c.isalpha())
#Author - Vedika Udgir

stringInput = input("Enter a string: ")

letters = 0
digits = 0
others = 0

for c in stringInput:
    if c.isalpha():
        letters += 1
    elif c.isdigit():
        digits += 1
    else:
        others += 1

print("Letters:", letters)
print("Digits:", digits)
print("Other characters:", others)

#9. Swap first and last characters
#Author - Vedika Udgir

stringInput = input("Enter a string: ")

if len(stringInput) > 1:
    newString = stringInput[-1] + stringInput[1:-1] + stringInput[0]
else:
    newString = stringInput

print(newString)

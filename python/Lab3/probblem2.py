#Check if a given string is a palindrome or not.
#Author - Vedika Udgir

inputString = input("Enter a string: ")
reversedString = inputString[::-1]

if inputString == reversedString:
    print(f'"{inputString}" is a palindrome.')
else:
    print(f'"{inputString}" is not a palindrome.')
#Implement your own version of Python’s str.replace(old, new) without using built-in replace.
#Author - Vedika Udgir

inputString = input("Enter the original string: ")
oldSubstring = input("Enter the substring to be replaced: ") 

if oldSubstring not in inputString:
        print("Substring not found in the original string.")
        exit()

newSubstring = input("Enter the new substring: ") 

for char in range(len(oldSubstring)):
    if inputString[char:char+len(oldSubstring)] == oldSubstring:
        inputString = inputString[:char] + newSubstring + inputString[char+len(oldSubstring):]
        break

print("Modified string:", inputString)
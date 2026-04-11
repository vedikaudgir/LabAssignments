#7. Write a Python program to get a single string from two given strings, separated by a space and swap the first two characters of each string.\
#Author - Vedika Udgir

stringInput1 = input("Enter a string: ")
stringInput2 = input("Enter a string: ")

newString1 = stringInput2[:1] + stringInput1[1:]
newString2 = stringInput1[:1] + stringInput2[1:]

print(f"{newString1} {newString2}")
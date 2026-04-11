#3. Create a program that asks the user to enter their name and their age. Print out a message addressed to them that tells them the year that they will turn 100 years old.
# Author - Vedika Udgir

userName = input("Enter your name: ")
userAge = input("Enter your age: ")
print(f"Hi {userName}, you will turn 100 year old in the year {100 - int(userAge) + 2025 }")
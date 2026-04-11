#Write a Python program to count the number of elements in a list within a specified range
#Author - Vedika Udgir

numbers = [10, 25, 30, 45, 60, 75, 90]

lower = int(input("Enter the lower bound: "))
upper = int(input("Enter the upper bound: "))

count = 0

for num in numbers:
    if lower <= num <= upper:
        count += 1

print("Number of elements within the range:", count)
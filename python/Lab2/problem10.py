#10. Write a Python program to calculate the sum and average of n integer numbers (input from the user). Input 0 to finish.
#Author - Vedika Udgir

total = 0
count = 0

while True:
    n = int(input("Enter a number (0 to stop): "))
    if n == 0:
        break
    total += n
    count += 1

if count > 0:
    print("Sum:", total)
    print("Average:", total / count)
else:
    print("No numbers entered")

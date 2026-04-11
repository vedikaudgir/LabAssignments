#7. Write a Python program to print the following patterns. Expected Output:
# * * *
#  * *
#   *  
#  * *
# * * *
#Author - Vedika Udgir

for i in range(1, 3):
    for j in range(0, i):
        print(" ", end="")
    for k in range(3 - i + 1, 0):
        print("*", end=" ")

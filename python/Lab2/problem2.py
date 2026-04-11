#2. Write a Python program to convert temperatures to and from Celsius, Fahrenheit. (Hint: Enter- 45F or 98C) Formula: C = (5/9) * (F - 32)
#Author - Vedika Udgir

temp = input("Enter temperature (e.g. 45F or 98C): ")

if temp[-1].upper() == "C":
    f = (9/5) * float(temp[:-1]) + 32
    print(f"{temp} is {f}F")

elif temp[-1].upper() == "F":
    c = (5/9) * (float(temp[:-1]) - 32)
    print(f"{temp} is {c}C")
else:
    print("Invalid temperature format. Please use 'C' for Celsius or 'F' for Fahrenheit.")

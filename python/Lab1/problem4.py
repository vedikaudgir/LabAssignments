# 4. Write a Python program which accepts the radius of a circle from the user and compute the area. (Hint: import math and use math.pi)
# Author - Vedika Udgir

import math

radius = input("Enter the radius of the circle: ")
area = math.pi * (float(radius)**2)

print(f"The area of given circle is: {area}")
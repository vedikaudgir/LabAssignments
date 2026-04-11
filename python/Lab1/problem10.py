#10. Memory size
#Author - Vedika Udgir

import sys

stringInput = input("Enter a string: ")
print("Memory size of string:", sys.getsizeof(stringInput))

intInput = int(input("Enter an integer: "))
print("Memory size of integer:", sys.getsizeof(intInput))

listInput = eval(input("Enter a list: "))
print("Memory size of list:", sys.getsizeof(listInput))

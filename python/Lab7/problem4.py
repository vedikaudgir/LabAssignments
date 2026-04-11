#Define a function that can accept two strings as input and concatenate them and then print it in console.
#Author - Vedika Udgir

import string

def concatenate(string1, string2):
    if not isinstance(string1, str):
        return TypeError("Invalid Input")
    if not isinstance(string2, str):
        return TypeError("Invalid Input")
    return string1 + string2

print(concatenate("hello", "1"))
print(concatenate("hello", "world"))

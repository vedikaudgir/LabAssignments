#Write a Python program to remove duplicates from a list. 
#Author - Vedika Udgir

list = [2, 5, 6 , 8 , 3, 0, 9, 3, 7, 1, 8, 3, 1, 2, 4, 8, 5, 6, 7, 7, 9, 0]

result = []

for item in list:
    if item not in result:   
        result.append(item)

print(result)
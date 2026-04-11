#4. Write a Python program to generate all permutations of a list in Python. 
#Author - Vedika Udgir

import itertools

list = ['g', 'o', 'j', 'o']

permutations = [i for i in itertools.permutations(list)]
print(permutations)
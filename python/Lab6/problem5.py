#You are working on a data processing task. You need to check whether one set of values is a subset of another large set efficiently.
#Author - Vedika Udgir

set1 = {1, 2, 3, 4, 5}
set2 = {1, 2, 3}
set3 = {2, 7}

is_subset = set2.issubset(set1)
print(is_subset)

is_subset = set3.issubset(set1)
print(is_subset)
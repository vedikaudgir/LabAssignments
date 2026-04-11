# Write a function to compute the power set of a given set of integers. The power set is the set of all subsets, including the empty set and the set itself.
# Example usage: s = {1, 2, 3} 
# Output: [{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}]

import itertools

s = {1, 2, 3}

powerSet = list(i for r in range(len(s)+1) for i in itertools.combinations(s, r))

print(powerSet)
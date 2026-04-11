# Given a list of integers representing a sequence (but with some numbers missing), find all the missing numbers from the sequence.
#Author - Vedika Udgir

numbers = [3, 6, 9, 15, 18, 27]

a = min(numbers)
d = numbers[1] - numbers[0]
n = len(numbers)

fullset = set(an for an in range(a, max(numbers) + 1, d))

missing = fullset - set(numbers)

print("Missing numbers in the sequence:", sorted(missing))

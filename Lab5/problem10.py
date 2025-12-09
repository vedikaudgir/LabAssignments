import sys

for n in [10, 100, 1000]:
    d = {i: i for i in range(n)}
    print(f"{n} keys:", sys.getsizeof(d))

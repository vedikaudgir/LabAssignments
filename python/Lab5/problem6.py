class BadHash:
    def __init__(self, x):
        self.x = x
    def __hash__(self):
        return 1
    def __eq__(self, other):
        return self.x == other.x

d = {}
for i in range(10):
    d[BadHash(i)] = i

print("Inserted with collisions:", d)

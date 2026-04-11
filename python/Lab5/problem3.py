d = {}

d["a"] = 1
d["b"] = 2
d["c"] = 3
print("Original:", d)

del d["b"]
d["b"] = 2
print("After deletion & reinsertion:", d)

d = {}

try:
    d[["list"]] = "error"
except TypeError as e:
    print("List as key →", e)

try:
    d[{"dict":1}] = "error"
except TypeError as e:
    print("Dict as key →", e)

d["string"] = "ok"
d[(1,2,3)] = "tuple ok"
print(d)

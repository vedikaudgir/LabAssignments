import sys

d = {"name": "Vedika", "age": 19, "active": True}

print("Number of items:", len(d))

print("\nKey Hashes and Memory Addresses:")
for k, v in d.items():
    print(f"Key: {k}, Hash: {hash(k)}, id(key): {id(k)}, id(value): {id(v)}")

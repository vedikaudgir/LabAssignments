d = {"x": 10, "y": 20}

keys_view = d.keys()
values_view = d.values()
items_view = d.items()

print(keys_view, values_view, items_view)

d["z"] = 30

print("After change:", keys_view, values_view, items_view)

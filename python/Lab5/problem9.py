import json

d = {"a": 1, "b": [1,2,3], "c": {"x": 10}}

json_str = json.dumps(d)
back = json.loads(json_str)

print(json_str)
print(back)
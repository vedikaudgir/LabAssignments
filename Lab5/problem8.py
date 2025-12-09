s = "banana"
freq1 = {}

for ch in s:
    freq1.setdefault(ch, 0)
    freq1[ch] += 1

print(freq1)

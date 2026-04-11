word = input("enter a word")
myDict = {chr(i) : i - 65 for i in range(65,91)}
temp = word.upper()

result = ""

for ch in temp:
    if ch.isalpha():
        result += str(myDict[ch])
        result += "."

print(result)
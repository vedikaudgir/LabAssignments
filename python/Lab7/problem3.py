#We can create another substitution cipher by permutating the alphabet and map the letters to the corresponding permutated alphabet. Write a function which takes a text and a dictionary to decrypt or encrypt the given text with a permutated alphabet.
#Author - Vedika Udgir

def makeMap(s):
    s = s % 26
    d = {}
    for ch in range(ord('a'), ord('z') + 1):
        d[chr(ch)] = chr((ch - 97 + s) % 26 + 97)
    for ch in range(ord('A'), ord('Z') + 1):
        d[chr(ch)] = chr((ch - 65 + s) % 26 + 65)
    return d

def substitutionCipher(t, d):
    r = []
    for ch in t:
        r.append(d[ch] if ch in d else ch)
    return ''.join(r)

t = input()
s = int(input())

d = makeMap(s)
print(substitutionCipher(t, d))
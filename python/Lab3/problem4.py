#4.Implement Run-Length Encoding (RLE) for strings: "aaabbcddd" → "a3b2c1d3". Implement both compression and decompression methods.
#Author - Vedika Udgir

inputString = input("Enter a string to compress: ")

count = 1
compressedString = ""

for i in range(1, len(inputString)):
    if inputString[i] == inputString[i - 1]:
        count += 1
    else:
        compressedString += inputString[i - 1] + str(count)
        count = 1

compressedString += inputString[-1] + str(count)

print("Compressed string:", compressedString)
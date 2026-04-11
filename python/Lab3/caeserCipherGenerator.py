#Write a Python program to print the following patterns. Encrypt and decrypt a message using the Caesar Cipher with a given shift.
#Author - Vedika Udgir

message = input("Enter your message: ")
shift = int(input("Enter the shift value (1-25): "))
encryptedMessage = ""

for char in message:
    if char.isalpha():
        code = ord('A') if char.isupper() else ord('a')
        encryptedChar = chr((ord(char) - code + shift) % 26 + code)
        encryptedMessage += encryptedChar
    else:
        encryptedMessage += char

print("Encrypted message:", encryptedMessage)
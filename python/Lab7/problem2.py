#2. Write a function which takes a text and encrypts it with a Caesar cipher. This is one of the simplest and most commonly known encryption techniques. Each letter in the text is replaced by a letter some fixed number of positions further in the alphabet. What about decrypting the coded text?
#The Caesar cipher is a substitution cipher.
#Author - Vedika Udgir


def CeaserCipher(message, shift):
    if not isinstance(shift, int):
        return ValueError("Enter correct shift!")
    encryptedMessage = ""
    for char in message:
        if char.isalpha():
            code = ord('A') if char.isupper() else ord('a')
            encryptedChar = chr((ord(char) - code + shift) % 26 + code)
            encryptedMessage += encryptedChar
        else:
            encryptedMessage += char
    return encryptedMessage

    
code = CeaserCipher("hello",2)
print(code)

decrypt = CeaserCipher(code, -2)
print(decrypt)
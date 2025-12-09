#8. Write a Python program to detect the number of local variables declared in a function.
#Author - Vedika Udgir

def detectLocal(fun):
    return fun.__code__.co_nlocals

def faltuFunction():
    var1 = 10
    var2 = "Gojo Satoru"
    var3 = {"I", "am", "Gojo"}

print(detectLocal(faltuFunction))
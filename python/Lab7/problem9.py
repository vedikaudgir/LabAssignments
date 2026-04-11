#9. Write a Python funcion that changes the value of a variable define inside a function from outside of the function.
#Author - Vedika Udgir

def outer():
    x = 5
    def inner():
        y = 10
        return x+10
    inner(x)
#    return x + y

print(outer)
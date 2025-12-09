class X:
    def greet(self):
        print("Hello from X")
        super().greet()

class Y:
    def greet(self):
        print("Hello from Y")

class Z(X, Y):
    def greet(self):
        print("Hello from Z")
        super().greet()

z_object = Z()
z_object.greet()
print(Z.__mro__)

class A:
    def action(self):
        print("Action from A")

class B(A):
    def action(self):
        print("Action from B")

class C(A):
    def action(self):
        print("Action from C")

class D(B, C):
    pass

d_object = D()
d_object.action()

print("MRO:", D.__mro__)

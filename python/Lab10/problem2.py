class A:
    def action(self):
        print("Action from A")
        super().action()

class B(A):
    def action(self):
        print("Action from B")
        super().action()

class C(A):
    def action(self):
        print("Action from C")
        super().action()

class E(A):
    def action(self):
        print("Action from E")
        super().action()

class D(B, C, E):
    def action(self):
        print("Action from D")
        super().action()

d_object = D()
d_object.action()

print("MRO:", D.__mro__)

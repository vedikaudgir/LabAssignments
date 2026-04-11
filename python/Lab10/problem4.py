class Base1:
    def process(self):
        print("Processing in Base1")

class Base2:
    def process(self):
        print("Processing in Base2")

class Base3:
    def process(self):
        print("Processing in Base3")

class Derived(Base1, Base2, Base3):
    def process(self, order=None):
        method_map = {
            "Base1": Base1.process,
            "Base2": Base2.process,
            "Base3": Base3.process
        }

        if order is None:
            print("Default MRO call:")
            super().process()
        else:
            print("Dynamic runtime call:")
            for class_name in order:
                method_map[class_name](self)


derived_object = Derived()

derived_object.process()
derived_object.process(order=["Base3", "Base1", "Base2"])

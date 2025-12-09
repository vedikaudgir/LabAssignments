class Base1:
    data = "Data from Base1"
    def info(self):
        print("Info from Base1")
        super().info()

class Base2:
    data = "Data from Base2"
    def info(self):
        print("Info from Base2")
        super().info()

class Base3:
    data = "Data from Base3"
    def info(self):
        print("Info from Base3")

class Combined(Base1, Base2, Base3):
    def info(self):
        print("Info from Combined")
        super().info()


combined_object = Combined()
combined_object.info()
print("Data chosen:", combined_object.data)
print("MRO:", Combined.__mro__)
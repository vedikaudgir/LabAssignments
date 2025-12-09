class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        print(f"Area of the circle is = {3.14*(self.radius**2)}")
        
myCircle = Circle(4)
print(myCircle.area())

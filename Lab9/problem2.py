class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def area(self):
        print(f"Area of the Rectangle is = {self.breadth*self.length}")
        
myRectangle = Rectangle(4,2)
print(myRectangle.area())

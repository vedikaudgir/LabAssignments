class Person:
    def __init__(self, name):
        self.name = name
        print("Person initialized")

class Employee(Person):
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary
        print("Employee initialized")

class Manager(Person):
    def __init__(self, name, department):
        super().__init__(name)
        self.department = department
        print("Manager initialized")

class Director(Employee, Manager):
    def __init__(self, name, salary, department):
        super().__init__(name, salary)
        super(Manager, self).__init__(name, department)
        print("Director initialized")


director_object = Director("Vedika", 90000, "Tech")
print("MRO:", Director.__mro__)

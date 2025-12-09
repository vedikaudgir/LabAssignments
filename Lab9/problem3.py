class MultiplesOf7:
    def __init__(self, n):
        self.n = n
    def printMultiplesOf7(self):
        for i in range(self.n):
            if (i % 7 != 0):
                yield i

limit = 100
myObj = MultiplesOf7(limit)

for number in myObj.printMultiplesOf7():
    print(number, end = " ")
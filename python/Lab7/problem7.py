# 7. The Fibonacci Sequence is computed based on the following formula:
# f(n)=0 if n=0
# f(n)=1 if n=1
# f(n)=f(n-1)+f(n-2) if n>1
# Write a function to compute the value of f(n) with a given n input by console.
# Author - Vedika Udgir

def fibonacci(n):
    if n < 0:
        return ValueError("Invalid Input")
    elif n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        a, b = 0, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b

for i in range (10):
    result = fibonacci(i)
    print(result, end = " ")
    
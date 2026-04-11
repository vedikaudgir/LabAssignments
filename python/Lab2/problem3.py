#3. Write a Python program to get the Fibonacci series between 0 to 50. (Hint: initially a=0, b=1 and a=a+b, b=a+b) 0, 1, 1, 2, 3, 5, 8, 13, 21
#Author - Vedika Udgir

a, b = 0, 1
while a <= 50:
    print(a, end=" ")
    a, b = b, a + b

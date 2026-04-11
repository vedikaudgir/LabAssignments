d = {
    n: (n*n if n % 2 == 0 else n*n*n)
    for n in range(1, 21)
    if n % 4 != 0
}

print(d)

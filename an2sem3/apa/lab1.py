import math

def fib1(n):
    if n < 2:
        return n
    else:
        return fib1(n - 1) + fib1(n - 2)

def fib2(n):
    i, j = 1, 0
    for k in range(1, n + 1):
        j = i + j
        i = j - i
    return j

def fib3(n):
    i, j, k, h = 1, 0, 0, 1
    while n > 0:
        if n % 2 == 1:
            t = j * h
            j = i * h + j * k + t
            i = i * k + t
        t = h * h
        h = 2 * k * h + t
        k = k * k + t
        n //= 2
    return j

def fib4(n):
    sqrt5 = math.sqrt(5)
    phi = (1 + sqrt5) / 2
    psi = (1 - sqrt5) / 2
    return round((phi**n - psi**n) / sqrt5)


n = 35
print(f"fib1({n}) = {fib1(n)}")
print(f"fib2({n}) = {fib2(n)}") 
print(f"fib3({n}) = {fib3(n)}")
print(f"fib4({n}) = {fib4(n)}")
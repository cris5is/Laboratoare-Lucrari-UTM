def sum_of_n(n):
    if n==0 or n==1:
        return n
    return n+sum_of_n(n-1)

print(sum_of_n(5))
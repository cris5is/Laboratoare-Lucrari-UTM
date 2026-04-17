def factorial(a):
    if a==0 or a==1:
        return 1
    elif a<0:
        return None
    return a*factorial(a-1)

def sub_factorial(a):
    #!n=(n−1)(!(n−1)+!(n−2))
    if a==0:
        return 1
    elif a==1:
        return 0
    elif a<0:
        return None
    return (a-1)*(sub_factorial(a-1)+sub_factorial(a-2))

def aranjari(a,b):
    # a!/(a-b)!
    if b>a or a<0 or b<0:
        return None
    return factorial(a)//factorial(a-b)

def combinari(a,b):
    if b>a or a<0 or b<0:
        return None
    return factorial(a)//(factorial(a-b)*factorial(b))

def catalan_of(a):
    #(2a)!/((a+1)!*(a)!)
    return factorial(2*a)//(factorial(a+1)*factorial(a))

def probabilitate_binomiala(n, k, p):
#P(X=k)=combinari(n,k)*(p**k)*(1-p)**(n-k)
    if k > n or n < 0 or k < 0:
        return None
    if p < 0 or p > 1:
        return None
    return combinari(n, k)  * p ** k * (1 - p) ** (n - k)

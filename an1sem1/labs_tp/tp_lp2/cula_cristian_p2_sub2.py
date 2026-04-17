import math
a=float(input())
b=float(input())
c=float(input())
if a!=0:
    d=b**2-4*a*c
    if d==0:
        print("x=",end='')
        print(-b/(2*a))
    elif d>0:
        print("x1=", end='')
        print((-b + math.sqrt(d)) / (2 * a))
        print("x2=", end='')
        print((-b - math.sqrt(d)) / (2 * a))
    else:
        print("No solutions")
else:
    if b!=0:
        print("x=",end='')
        print(-c/b);
    else:
        print("No solutions");
import math,datetime, random

def factorial(x):
    if x==1 or x==0:
        return 1
    return factorial(x-1)*x

def maxim(a,b,c):
    maxim=max(a,b,c)
    return maxim

def zar(n):
    for i in range(n):
        a=random.randint(1,6)
        print(f"A cazut cifra {a}")

def timp():
    acum=datetime.datetime.now()
    azi=datetime.date.today()
    print("Timpul de acum",acum)
    print("Data de azi",azi)

while True:
    print("")
    print("1.Calcul factorial")
    print("2.Determinarea maximului a trei numere")
    print("3.Simulare aruncare zar")
    print("4.Afișarea datei curente")
    print("5.Ieșire din program")
    print("")
    state=int(input("Alegeti optiunea:"))
    match state:
        case 1:
            n=int(input("Introduceti un numar pozitiv: "))
            print(factorial(n))
        case 2:
            a=int(input("Primul numar:"))
            b=int(input("Al doilea numar:"))
            c=int(input("Al treilea numar:"))
            print(maxim(a,b,c))
        case 3:
            n=int(input("de cate ori: "))
            zar(n)
        case 4:
            timp()
        case 5:
            break
        case _:
            print("Alegeti optiunea dintre acele propuse: ")
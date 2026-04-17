import math
menu_state=0
while menu_state!=3:
    menu_state=int(input("Alegeti optiunea:\n 1.Gradul I\n 2.Gradul II\n 3.Iesire\n"))
    match menu_state:
        case 1:
         a = float(input("a="))
         b = float(input("b="))
         if a == 0:
             print("x e R")
         else:
             print(-b / a)
        case 2:
            a = float(input("a="))
            while a == 0:
                a = float(input("Introduceti o valoare diferita de 0: "))
            b = float(input("b="))
            c = float(input("c="))
            d = b ** 2 - 4 * a * c
            if d == 0:
                print("x=", end='')
                print(-b / (2 * a))
            elif d > 0:
                print("x1=", end='')
                print((-b + math.sqrt(d)) / (2 * a))
                print("x2=", end='')
                print((-b - math.sqrt(d)) / (2 * a))
            else:
                print("No solution")

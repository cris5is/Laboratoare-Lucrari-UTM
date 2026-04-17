n=int(input("Numarul de numere="))
suma=0
media=0
for i in range(n):
    a=int(input("Introduceti numarul:"))
    suma+=a
media=suma/n
print("Media=",media)
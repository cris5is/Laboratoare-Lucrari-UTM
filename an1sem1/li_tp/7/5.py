import math

a = float(input("introduceti lungimea primei catete: "))
b = float(input("introduceti lungimea celei de a doua catete: "))

c = math.sqrt(a**2 + b**2)
aria = 1/2 * a * b

print(f"catete: {a} si {b}\nipotenuza: {c:.2f}\naria: {aria:.3f}\n")

h = int(round(a))
w = int(round(b))

h = max(1, h)
w = max(1, w)

for i in range(h):
    latime = int(round((i + 1) * w / h))
    latime = max(1, latime) 
    print("*" * latime)

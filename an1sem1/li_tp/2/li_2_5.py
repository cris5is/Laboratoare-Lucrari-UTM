import random
a=int(input("Ghiceste numaru [1,10] - "))
b=random.randint(1,10)
while a!=b:
    a=int(input("Incearca din nou - "))
print("Ati ghicit numarul")
import csv
import random
produse = ["Mouse", "Tastatura", "Monitor", "Casti", "Telefon", "Laptop"]
lista_produse = []

for i in range(5):
    nume = random.choice(produse)
    pret = round(random.uniform(50, 1500), 2) 
    lista_produse.append({"nume": nume,"pret": pret})

with open("produse.csv", "w", newline="") as f:
    scrie = csv.DictWriter(f, fieldnames=["nume", "pret"])
    scrie.writeheader()
    scrie.writerows(lista_produse)
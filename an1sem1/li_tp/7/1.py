import pandas as p
import matplotlib.pyplot as plt
date = p.read_csv('4/produse.csv')
nume = date['nume']
pret = date['pret']
plt.bar(nume, pret) 
plt.title('Pretul produselor')
plt.xlabel('Produse')
plt.ylabel('Pret')
plt.show()
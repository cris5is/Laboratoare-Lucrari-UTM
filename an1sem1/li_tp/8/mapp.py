list_numere = [1, 2, 3, 4, 5]
double=lambda x: x * 2
list_dublu= list(map(double, list_numere))
print(f"lista originala: {list_numere}")
print(f"lista dublata: {list_dublu}")
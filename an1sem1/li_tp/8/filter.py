list_numere = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
par_check=lambda x: x % 2 == 0
list_pare = list(filter(par_check, list_numere))
print(f"lista originala: {list_numere}")
print(f"lista filtrata: {list_pare}")
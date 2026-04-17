from functools import reduce
suming=lambda x, y: x + y
list_numere = [1, 2, 3, 4, 5]
sum = reduce(suming, list_numere)
print(f"lista originala: {list_numere}")
print(f"suma totala: {sum}")
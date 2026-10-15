import random
import sys
import pandas as pd

sys.setrecursionlimit(20000)
sys.set_int_max_str_digits(0)


class Counter:
    def __init__(self):
        self.aritmetice = 0
        self.comparatii = 0
        self.logice = 0
        self.iteratii_apeluri = 0

    @property
    def Nop(self):
        return self.aritmetice + self.comparatii + self.logice

    def reset(self):
        self.aritmetice = 0
        self.comparatii = 0
        self.logice = 0
        self.iteratii_apeluri = 0

    def __repr__(self):
        return (f"Nop={self.Nop} (aritm={self.aritmetice}, "
                f"comp={self.comparatii}, logice={self.logice}), "
                f"iteratii/apeluri={self.iteratii_apeluri}")


def merge_sort(arr, c: Counter):
    c.iteratii_apeluri += 1
    c.comparatii += 1
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    c.aritmetice += 2
    left = merge_sort(arr[:mid], c)
    right = merge_sort(arr[mid:], c)
    return merge(left, right, c)


def merge(left, right, c: Counter):
    result = []
    i = j = 0
    c.aritmetice += 2
    while i < len(left) and j < len(right):
        c.iteratii_apeluri += 1
        c.comparatii += 3
        c.logice += 1
        c.comparatii += 1
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
            c.aritmetice += 1
        else:
            result.append(right[j])
            j += 1
            c.aritmetice += 1

    while i < len(left):
        c.iteratii_apeluri += 1
        c.comparatii += 2
        c.logice += 1
        result.append(left[i])
        i += 1
        c.aritmetice += 1

    while j < len(right):
        c.iteratii_apeluri += 1
        c.comparatii += 2
        c.logice += 1
        result.append(right[j])
        j += 1
        c.aritmetice += 1
    return result


def quick_sort(arr, low, high, c: Counter):
    c.iteratii_apeluri += 1
    c.comparatii += 1
    if low < high:
        pi = partition(arr, low, high, c)
        quick_sort(arr, low, pi - 1, c)
        c.aritmetice += 1
        quick_sort(arr, pi + 1, high, c)
        c.aritmetice += 1


def partition(arr, low, high, c: Counter):
    p = arr[low]
    c.aritmetice += 1
    k = low
    l = high + 1
    c.aritmetice += 2

    while True:
        while True:
            k += 1
            c.aritmetice += 1
            c.comparatii += 2
            c.logice += 1
            if k > high or arr[k] > p:
                break

        while True:
            l -= 1
            c.aritmetice += 1
            c.comparatii += 1
            if arr[l] <= p:
                break

        c.comparatii += 1
        if k < l:
            arr[k], arr[l] = arr[l], arr[k]
        else:
            break
    arr[low], arr[l] = arr[l], arr[low]
    c.aritmetice += 2
    return l


def binary_search_di(arr, low, high, target, c: Counter):
    c.iteratii_apeluri += 1
    c.comparatii += 1
    if low > high:
        return -1

    mid = (low + high) // 2
    c.aritmetice += 3

    c.comparatii += 1
    if arr[mid] == target:
        return mid

    c.comparatii += 1
    if arr[mid] > target:
        c.aritmetice += 1
        return binary_search_di(arr, low, mid - 1, target, c)
    else:
        c.aritmetice += 1
        return binary_search_di(arr, mid + 1, high, target, c)


def construieste_worst_merge(arr):
    if len(arr) <= 1:
        return arr
    stanga = construieste_worst_merge(arr[0::2])
    dreapta = construieste_worst_merge(arr[1::2])
    return stanga + dreapta


def construieste_best_quick(vals):
    n = len(vals)
    if n <= 1:
        return vals[:]
    m = n // 2
    g_stanga = construieste_best_quick(vals[:m])
    g_dreapta = construieste_best_quick(vals[m + 1:])
    stanga = g_stanga[1:] + g_stanga[:1]
    return [vals[m]] + stanga + g_dreapta


def genereaza_intrare(algoritm, caz, n):
    if algoritm == "MergeSort":
        if caz == "favorabil":
            return list(range(n))
        elif caz == "mediu":
            arr = list(range(n))
            random.shuffle(arr)
            return arr
        elif caz == "defavorabil":
            return construieste_worst_merge(list(range(n)))

    elif algoritm == "QuickSort":
        if caz == "favorabil":
            return construieste_best_quick(list(range(n)))
        elif caz == "mediu":
            arr = list(range(n))
            random.shuffle(arr)
            return arr
        elif caz == "defavorabil":
            return list(range(n))

    elif algoritm == "BinarySearch":
        arr = sorted(list(range(n)))
        if caz == "favorabil":
            return arr, arr[(n - 1) // 2]
        elif caz == "mediu":
            return arr, random.choice(arr)
        elif caz == "defavorabil":
            return arr, -999


def masoara_algoritm(algoritm, caz, n):
    c = Counter()
    if algoritm == "MergeSort":
        arr = genereaza_intrare("MergeSort", caz, n)
        merge_sort(arr, c)
    elif algoritm == "QuickSort":
        arr = genereaza_intrare("QuickSort", caz, n)
        quick_sort(arr, 0, len(arr) - 1, c)
    elif algoritm == "BinarySearch":
        arr, target = genereaza_intrare("BinarySearch", caz, n)
        binary_search_di(arr, 0, len(arr) - 1, target, c)
    return c


REPETARI = 20 


def masoara_nop(algoritm, caz, n):
    if caz != "mediu":
        return masoara_algoritm(algoritm, caz, n).Nop

    if algoritm == "BinarySearch":
        arr = list(range(n))
        total = 0
        for target in arr:
            c = Counter()
            binary_search_di(arr, 0, n - 1, target, c)
            total += c.Nop
        return round(total / n)


    total = sum(masoara_algoritm(algoritm, caz, n).Nop for _ in range(REPETARI))
    return round(total / REPETARI)

n_values = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
cazuri = ["favorabil", "mediu", "defavorabil"]
algoritmi = ["MergeSort", "QuickSort", "BinarySearch"]

rezultate = {alg: {caz: [] for caz in cazuri} for alg in algoritmi}
for caz in cazuri:
    for n in n_values:
        for alg in algoritmi:
            rezultate[alg][caz].append(masoara_nop(alg, caz, n))

for caz in cazuri:
    df = pd.DataFrame({"n": n_values})
    for alg in algoritmi:
        df[alg] = rezultate[alg][caz]
    print(f"\nCazul {caz}")
    print(df.to_string(index=False))

for alg in algoritmi:
    df = pd.DataFrame({"n": n_values})
    for caz in cazuri:
        df[caz] = rezultate[alg][caz]
    print(f"\nAlgoritmul {alg}")
    print(df.to_string(index=False))
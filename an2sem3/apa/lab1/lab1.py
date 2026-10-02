import math
import sys
import pandas as pd

sys.setrecursionlimit(10000)
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
    
    def __repr__(self):
        return (f"Nop={self.Nop} (aritm={self.aritmetice}, "
                f"comp={self.comparatii}, logice={self.logice}), "
                f"iteratii/apeluri={self.iteratii_apeluri}")

def fib1(n, c: Counter):
    c.iteratii_apeluri += 1
    c.comparatii += 1
    if n < 2:
        return n
    c.aritmetice += 1
    a = fib1(n - 1, c)
    c.aritmetice += 1
    b = fib1(n - 2, c)
    c.aritmetice += 1
    return a + b

def fib2(n, c: Counter):
    i, j = 1, 0
    for _ in range(1, n + 1):
        c.iteratii_apeluri += 1
        j= i + j
        c.aritmetice += 1
        i = j - i
        c.aritmetice += 1
    return j

def fib3(n, c: Counter):
    i, j, k, h = 1, 0, 0, 1
    while n > 0:
        c.iteratii_apeluri += 1
        c.comparatii += 1
        c.aritmetice += 1
        c.comparatii += 1
        if n % 2 == 1:
            t = j * h
            c.aritmetice += 1
            j = i * h + j * k + t
            c.aritmetice += 4
            i = i * k + t
            c.aritmetice += 2
        t = h * h
        c.aritmetice += 1
        h = 2 * k * h + t
        c.aritmetice += 3
        k = k * k + t
        c.aritmetice += 2
        n = n // 2
        c.aritmetice += 1
    return j

def fib4(n, c: Counter):
    sqrt5 = math.sqrt(5)
    c.aritmetice += 1
    phi = (1 + sqrt5) / 2
    c.aritmetice += 2
    psi = (1 - sqrt5) / 2
    c.aritmetice += 2
    phi_n = phi ** n
    c.aritmetice += 1
    psi_n = psi ** n
    c.aritmetice += 1
    diff = phi_n - psi_n
    c.aritmetice += 1
    result = diff / sqrt5
    c.aritmetice += 1
    c.iteratii_apeluri += 1
    return round(result)

def masoara(func, n):
    c = Counter()
    rezultat = func(n, c)
    return rezultat, c

def format_val(valoare):
    s = str(valoare)
    if len(s) <= 24:
        return s, s
    trunchiat = f"{s[:10]}...{s[-6:]} ({len(s)} cifre)"
    return s, trunchiat

def analizeaza_algoritm(func, nume, n_values, eticheta_iteratii):
    randuri = []
    for n in n_values:
        rezultat, c = masoara(func, n)
        f_n_exact, f_n_afisat = format_val(rezultat)
        randuri.append({
            "n": n,
            "F(n)": f_n_afisat,
            eticheta_iteratii: c.iteratii_apeluri,
            "Nop (aritmetice)": c.aritmetice,
            "Nop (comparatii)": c.comparatii,
            "Nop (logice)": c.logice,
            "Nop (total)": c.Nop,
        })
    df = pd.DataFrame(randuri)
    print(f"\n=== Analiza empirica separata: {nume} ===")
    print(df.to_string(index=False))
    return df

OUT = "C:/Users/Cula Cristian/Documents/Laboratoare-Lucrari-UTM/an2sem3/apa/lab1"

n_fib1 = list(range(2, 34, 2))
df_fib1 = analizeaza_algoritm(fib1, "FIB1 (recursiv)", n_fib1, "apeluri")
df_fib1.to_csv(f"{OUT}/fib1_tabel.csv", index=False)

n_mari = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

df_fib2 = analizeaza_algoritm(fib2, "FIB2 (iterativ)", n_mari, "iteratii")
df_fib2.to_csv(f"{OUT}/fib2_tabel.csv", index=False)
df_fib3 = analizeaza_algoritm(fib3, "FIB3 (dublare rapida)", n_mari, "iteratii")
df_fib3.to_csv(f"{OUT}/fib3_tabel.csv", index=False)

df_fib4 = analizeaza_algoritm(fib4, "FIB4 (Binet)", n_mari, "pasi")
df_fib4.to_csv(f"{OUT}/fib4_tabel.csv", index=False)

n_comun = list(range(2, 27, 2))
comp = []
for n in n_comun:
    _, c1 = masoara(fib1, n)
    _, c2 = masoara(fib2, n)
    _, c3 = masoara(fib3, n)
    _, c4 = masoara(fib4, n)
    comp.append({
        "n": n,
        "FIB1 Nop": c1.Nop,
        "FIB2 Nop": c2.Nop,
        "FIB3 Nop": c3.Nop,
        "FIB4 Nop": c4.Nop,
    })
df_comp = pd.DataFrame(comp)
df_comp.to_csv(f"{OUT}/comparatie_toti_algoritmii.csv", index=False)
print("\n=== Tabel comparativ (interval comun, limitat de FIB1) ===")
print(df_comp.to_string(index=False))

def tabel_nop(functii_si_nume, n_values):
    randuri = []
    for n in n_values:
        rand = {"n": n}
        for func, nume in functii_si_nume:
            _, c = masoara(func, n)
            rand[nume] = c.Nop
        randuri.append(rand)
    return pd.DataFrame(randuri)

n_A = list(range(1, 35))
df_A = tabel_nop([(fib1, "FIB1 (recursiv)"), (fib2, "FIB2 (iterativ)")], n_A)
df_A.to_csv(f"{OUT}/comparatie_fib1_vs_fib2.csv", index=False)
print("\n=== A) FIB1 (recursiv) vs FIB2 (iterativ) ===")
print(df_A.to_string(index=False))

n_B = list(range(1, 1001))
df_B = tabel_nop([(fib2, "FIB2 (iterativ)"), (fib3, "FIB3 (dublare rapida)"),
                    (fib4, "FIB4 (Binet)")], n_B)
df_B.to_csv(f"{OUT}/comparatie_fib2_fib3_fib4.csv", index=False)
print("\n=== B) FIB2 (iterativ) vs FIB3 (dublare rapida) vs FIB4 (Binet) ===")
print(df_B.iloc[::50].to_string(index=False))
df_B_zoom = df_B[df_B["n"] <= 60]

n_C = list(range(1, 1001))
df_C = tabel_nop([(fib3, "FIB3 (dublare rapida)"), (fib4, "FIB4 (Binet)")], n_C)
df_C.to_csv(f"{OUT}/comparatie_fib3_vs_fib4.csv", index=False)
print("\n=== C) FIB3 (dublare rapida) vs FIB4 (Binet) ===")
print(df_C.iloc[::50].to_string(index=False))


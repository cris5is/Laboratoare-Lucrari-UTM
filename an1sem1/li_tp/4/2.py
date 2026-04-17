import csv

def citeste_csv(nume_fisier):
    info = []
    with open(nume_fisier,"r") as f:
        citit = csv.DictReader(f)
        for linie in citit:
            if "" in linie.values():
                print(f"Missing value in {nume_fisier} file, line {linie}")
            else:
                info.append(linie)
    return info

catalog_elevi=citeste_csv("elevi.csv")

media_generala = []
for elev in catalog_elevi:
    nume = elev['nume']
    media_mate = float(elev['matematica'])
    media_rom = float(elev['romana'])
    media_eng = float(elev['engleza'])
    media_ist = float(elev['istoria'])
    media=(media_eng+media_ist+media_mate+media_rom)/4
    media_generala.append({"nume":nume, "media":media})

with open("mediile.csv", "w", newline="") as f:
    scrie=csv.DictWriter(f,fieldnames=["nume","media"])
    scrie.writeheader()
    scrie.writerows(media_generala)


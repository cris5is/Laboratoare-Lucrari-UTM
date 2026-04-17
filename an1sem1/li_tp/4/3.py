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

mediile=citeste_csv("mediile.csv")
admis=[]
for elev in mediile:
    nume = elev['nume']
    media = float(elev['media'])
    admitere=''
    if media<5 and media>=0:
        admitere='Neadmis'
    elif media>=5 and media<=10:
        admitere='Admis'
    else:
        admitere='Frauda?'
    admis.append({"nume":nume,"admis":admitere})

    
with open("admitere.csv", "w", newline="") as f:
    scrie=csv.DictWriter(f,fieldnames=["nume","admis"])
    scrie.writeheader()
    scrie.writerows(admis)
    
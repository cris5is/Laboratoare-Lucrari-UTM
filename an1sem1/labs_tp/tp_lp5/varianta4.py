import csv
import json
deleted_lines=0 
class NoValue(Exception):
    pass

def citeste_csv(nume_fisier,convert):
    info = []
    global deleted_lines
    try:
        open(nume_fisier,"r", encoding='utf-8')
    except FileNotFoundError:
        print(f"File {nume_fisier} not found")
        exit
    else:
        with open(nume_fisier,"r", encoding='utf-8') as f:
            citit = csv.DictReader(f)
            for linie in citit:
                try:
                    list_item=linie.values()
                    for i in list_item:
                        if i=="":
                            raise NoValue
                    for value,t in zip(list_item,convert):
                        '''
                        daca este list1=[a,b,c] si list2=[d,e,f]
                        list12=zip(list1,list2):
                            print(list12)
                        >>>[(a,d),(b,e),(c,f)]
                        stackoverflow 👍
                        '''
                        try:
                            t(value)
                        except ValueError:
                            deleted+=1
                except:
                    deleted_lines+=1
                else:
                    info.append(linie)
                finally:
                    print()
    return info

vanzari= citeste_csv("vanzari.csv",[str,int,float])
stoc= citeste_csv("stoc.csv",[str,int,int])

totaluri = {}
for item in vanzari:
    produs = item['produs']
    cantitate = float(item['cantitate'])
    pret = float(item['pret'])
    total = cantitate * pret
    if produs in totaluri:
        totaluri[produs] += total
    else:
        totaluri[produs] = total

top_vanzari = sorted(totaluri.items(), key=lambda x:x[1], reverse=True)

with open("top_vanzari.csv","w", newline='\n') as f:
    scrie=csv.writer(f)
    scrie.writerow(["produs","total"])
    scrie.writerows(top_vanzari)

top_vanzari_json=[]
for p,t in top_vanzari:
    item={"produs":p,"total":t}
    top_vanzari_json.append(item)

with open("top_vanzari.json", "w") as f:
    json.dump(top_vanzari_json, f, indent=4)

alerte = []
for item in stoc:
    produs=item['produs']
    stoc_minim=float(item['stoc_minim'])
    stoc_curent=float(item['stoc_curent'])
    if stoc_curent<stoc_minim:
        alerte.append(produs)
set(alerte)
with open("alerte_stoc.json", "w") as f:
    json.dump(alerte, f, indent=4)

for p,t in top_vanzari[:5]:
    print(f"{p}:{t} lei")

print(f"\nnumarul de alerte: {len(alerte)}\nLinii omise: {deleted_lines}")
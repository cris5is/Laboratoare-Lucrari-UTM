import csv

elevi = []

def adauga_elev():
    nume = input("nume elev= ")
    media_mate = float(input("media la mate = "))
    media_rom = float(input("media la romana = "))
    media_eng = float(input("media la eng = "))
    media_ist = float(input("media la istorie = "))
    elevi.append({"nume": nume, "matematica": media_mate,
                  "romana": media_rom,
                  "engleza": media_eng,
                  "istoria": media_ist})

def savein_csv():
    with open("elevi.csv", "w", newline="") as f:
        scrie =csv.DictWriter(f,fieldnames=["nume","matematica","romana","engleza","istoria"])
        scrie.writeheader()
        scrie.writerows(elevi)

option=0
while option!=3:
    option=int(input("alegeti optiunea: \n 1. adauga elev\n 2. salveaza in csv file\n"))
    match option:
        case 1:
            adauga_elev()
        case 2:
            savein_csv()
            option=3
        case 3:
            pass
        case _:
            option=int(input("alegeti o optiune valabila\n"))

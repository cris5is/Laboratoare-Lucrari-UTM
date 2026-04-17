class Produs:
    def __init__(self,denumire, pret, stoc):
        self.denumire=denumire
        self.pret=pret
        self.stoc=stoc

    def __str__(self):
        return f"{self.denumire} - ${self.pret}. Stoc curent: {self.stoc}"

    def actualizeaza_stoc(self,cantitate):
        print(f" * Stoc actualizat de la {self.stoc} la ",end='')
        self.stoc+=cantitate
        if self.stoc<0:
            self.stoc=0
        print(f"{self.stoc} pentru {self.denumire}")

class Client:
    comenzi_total=0
    def __init__(self,nume):
        self.nume=nume
        self.cos_cumparaturi=[]

    def __str__(self):
        return f"{self.nume}"
    
    def adauga_in_cos(self,produs,numar=1):
        if produs.stoc>=numar:
            self.cos_cumparaturi.append((produs,numar))
            print(f" * Adaugat in cosul {self.nume} - {produs.denumire} x{numar}")
            produs.actualizeaza_stoc(-numar)
        else:
            print(f" * Insuficient stoc pentru {produs.denumire}")

    def calculeaza_total(self):
        total=0
        for produs, numar in self.cos_cumparaturi:
            total+=produs.pret*numar
        return total
    
    def finalizeaza_comanda(self):
        total=self.calculeaza_total()
        print(f" * Finalizata comanda lui {self.nume}\nIn total = {total}")
        Client.comenzi_total+=1
        return total

    @classmethod
    def total_comenzi(cls):
        print(f" * Comenzi in total => {cls.comenzi_total}")

class ClientPremium(Client):
    def __init__(self,nume,reducere):
        super().__init__(nume)
        self.reducere=reducere #reducerea in procente => 90%

    def __str__(self):
        return f"{self.nume} (Premium) ({self.reducere}%)"
    
    def calculeaza_total(self):
        total=super().calculeaza_total()
        Client.comenzi_total+=1
        return total*(100-self.reducere)/100

    def finalizeaza_comanda(self):
        total=self.calculeaza_total()
        print(f" * Finalizata comanda lui {self.nume} cu reducere de {self.reducere}%\nIn total: {total*100/(100-self.reducere)} => {total}")
        Client.comenzi_total+=1
        return total

list_produse=[]
list_clienti=[]
print("1. Adaugarea produs\n",
      "2. Creare client\n",
      "3. Efectuare comanda\n",
      "4. Numarul total de comenzi\n",
      "5. Iesire\n")
option=0
while option!=5:
    option=int(input("Alegeti optiunea: "))
    match option:
        case 1:
            nume_produs=input("Numele produsului: ")
            pret_produs=float(input("Pretul produsului: "))
            stoc_produs=int(input("Stocul curent: "))
            list_produse.append(Produs(nume_produs,pret_produs,stoc_produs))
        case 2:
            print("1. Standard\n"
                  "2. Premium\n")
            sec_option=int(input("Alegeti optiunea: "))
            match sec_option:
                case 2:
                    nume_client=input("Numele clientului premium: ")
                    reducere_client=int(input("Reducerea aplicata: "))
                    list_clienti.append(ClientPremium(nume_client,reducere_client))
                case _:
                    nume_client=input("Numele clientului: ")
                    list_clienti.append(Client(nume_client))
        case 3:
            for client in list_clienti:
                print(client)
            client_ales=input("Selectati clientul: ")
            client_curent=next((cl for cl in list_clienti if cl.nume==client_ales),None)
            if client_curent==None:
                print(f"{client_curent} nu a fost gasit")
            else:
                print("1. Adaugare produs in cos\n"
                      "2. Finalizare comanda")
                sec_option=int(input("Alegeti optiunea: "))
                match sec_option:
                    case 1:
                        for produs in list_produse:
                            print(produs)
                        produs_ales=input("Selectati produsul: ")
                        produs_curent=next((pr for pr in list_produse if pr.denumire==produs_ales),None)
                        cantitate_produs=int(input("Introduceti cantitatea: "))
                        if produs_curent==None:
                            print(f"{produs_curent} nu a fost gasit")
                        else:
                            client_curent.adauga_in_cos(produs_curent,cantitate_produs)
                    case _:
                        client_curent.finalizeaza_comanda()
        case 4:
            print(f"Numarul total de comenzi: {Client.comenzi_total}\n")

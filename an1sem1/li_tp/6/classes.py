class Lampa:
    def __init__(self, culoare):
        self.culoare=culoare
        self.aprins=False
    
    def aprinde(self):
        if not self.aprins:
            self.aprins=True
            print(f"Lampa s-a aprins. Culoarea {self.culoare}")
        else:
             print("Lampa deja e aprinsa")

    def stange(self):
        if self.aprins:
            self.aprins=False
            print(f"Lampa s-a stins")
        else:
             print("Lampa deja e stansa")

class Tamagochi:
    def __init__(self,hp,hunger,happiness):
        self.max_hp=hp
        self.current_hp=hp
        self.hunger=hunger
        self.happiness=happiness

    def give_good_food(self):
        self.hunger+=5
        self.happiness+=1
        if self.max_hp-self.current_hp>=2:
            self.current_hp+=2
        else: 
            self.current_hp=self.max_hp
        print(f"HP:{self.current_hp}/{self.max_hp} - Hunger:{self.hunger} - Happiness:{self.happiness}")

    def give_bad_food(self):
        self.hunger+=1
        if self.happiness>=2:
            self.happiness-=2
        print(f"Hunger:{self.hunger} - Happiness:{self.happiness}")

    def damage(self,amount):
        if self.current_hp>amount-1:
            self.current_hp-=amount
        else:
            self.current_hp=0
        print(f"Took {amount} damage => HP:{self.current_hp}/{self.max_hp}")

    def stats(self):
        print(f"HP:{self.current_hp}/{self.max_hp} - Hunger:{self.hunger} - Happiness:{self.happiness}")
    
class Cub:
    def __init__(self, lungime):
        self.lungime = lungime
      
    def aria_suprafetei(self):
        return 6*self.lungime**2

    def volum(self):
        return self.lungime**3
    
    def info(self):
        print(f"Aria suprafetei={self.aria_suprafetei()} Volum={self.volum()}")

my_lampa=Lampa("Albastru")
my_lampa.aprinde()
my_lampa.stange()
my_lampa.stange()
print()
my_tamagochi=Tamagochi(50,25,5)
my_tamagochi.give_bad_food()
my_tamagochi.give_good_food()
my_tamagochi.damage(4)
my_tamagochi.damage(7)
my_tamagochi.stats()
print()
my_cube=Cub(5)
my_cube.info()

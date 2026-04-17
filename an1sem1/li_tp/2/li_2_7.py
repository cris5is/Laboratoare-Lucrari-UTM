option=0
numele=''
while option!=3:
    print("1.Introducerea nume\n"
          "2.Salutare\n"
          "3.Iesire\n")
    option=int(input())
    match option:
        case 1:
            numele=input()
        case 2:
            print(f"Salut, {numele}")
        case 3:
            pass
        case _:
            print("Alegeti optiunile din meniu")


    
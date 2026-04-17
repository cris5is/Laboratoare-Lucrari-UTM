a = list(map(int, input().strip().split()))
for i in a:
    if i>0:
        print(f"{i} - Pozitiv ",end='')
    elif i==0:
        print(f"{i} - Zero ",end='')
    else:
        print(f"{i} - Negativ ",end='')
        
    if i%2==0:
        print("- Par")
    else:
        print("- Impar")
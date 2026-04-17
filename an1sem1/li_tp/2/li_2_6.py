a=int(input("Dimensiunea matricei: "))
for i in range(a):
    for j in range(a):
        print("* ",end='')
    print(end='\n')

cuvant=input("Introduceti un cuvant: ")
vocale="aeuioyAEYUIO"
count=0

for litera in cuvant:
    if litera in vocale:
        count+=1
print(f"sunt {count} vocale")
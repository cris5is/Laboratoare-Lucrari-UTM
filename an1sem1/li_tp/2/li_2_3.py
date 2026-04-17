note=[2,2,2,2,7,10]
media=0
maxim=0
for i in note:
    if i>maxim:
        maxim=i
    media+=i
media/=len(note)
if media>=5:
    print("Admis ",end='')
else:
    print("Neadmis ",end='')
print(f"{media:.2f}")
print(f"Nota maxima: {maxim}")

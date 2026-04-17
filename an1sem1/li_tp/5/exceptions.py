import logging

class OverLimit(Exception):
    pass

logging.basicConfig(
    filename="log.txt",
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s"
)
try:
    a=int(input("introduceti un numar de la -10^6 la 10^6\n=> "))
    b=int(input("introduceti un numar de la -10^6 la 10^6 fara 0\n=> "))

    if abs(a) > pow(10,6) and abs(b) > pow(10,6):
        raise OverLimit
    
    c=a/b
    
except ValueError:
    mesaj = "trebuie sa introduceti doar numere"
    print(mesaj)
    logging.error(mesaj)

except OverLimit:
    mesaj = "trebuie sa introduceti numere din limitele respective"
    print(mesaj)
    logging.warning(mesaj)

except ZeroDivisionError:
    mesaj = "b nu trebuie sa fie 0"
    print(mesaj)
    logging.error(mesaj)
else:
    mesaj = f"totu e bine, a/b={c}"
    print(mesaj)
    logging.info(mesaj)
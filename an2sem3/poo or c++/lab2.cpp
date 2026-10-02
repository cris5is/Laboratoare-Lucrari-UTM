#include <iostream>
#include <string>
using namespace std;

class BiletCinema
{
    string codRezervare;
    double pretBilet;
    bool locValidat;

public:
    string filmul;
    BiletCinema()
    {
        filmul = "Nu stiu";
        codRezervare = "Nu stiu";
        pretBilet = 1.0;
        locValidat = 0;
        cout << "Constructor implicit apelat pentru obiectul " << filmul << endl;
    }
    BiletCinema(string filmul, string codRezervare, double pretBilet, bool locValidat)
    {
        this->filmul = filmul;
        this->codRezervare = "Nu stiu";
        this->pretBilet = 1.0;
        this->locValidat = 0;
        set_codRezervare(codRezervare);
        set_pretBilet(pretBilet);
        set_locValidat(locValidat);
        cout << "Constructor cu parametri apelat pentru obiectul " << this->filmul << endl;
    }
    BiletCinema(const BiletCinema &src)
    {
        this->filmul = src.filmul;
        this->codRezervare = src.codRezervare;
        this->pretBilet = src.pretBilet;
        this->locValidat = src.locValidat;
        cout << "Constructor de copiere apelat pentru obiectul " << this->filmul << endl;
    }
    ~BiletCinema()
    {
        cout << "Destructor apelat pentru obiectul " << this->filmul << endl;
    }
    string get_codRezervare()
    {
        return this->codRezervare;
    }
    void set_codRezervare(string codRezervare)
    {
        if (codRezervare.empty())
        {
            cout << "Eroare: Codul rezervarii nu poate fi gol" << endl;
            return;
        }
        this->codRezervare = codRezervare;
    }
    double get_pretBilet()
    {
        return this->pretBilet;
    }
    void set_pretBilet(double pretBilet)
    {
        if (pretBilet <= 0)
        {
            cout << "Eroare la obiectul " << this->filmul << ": Pretul biletului trebuie sa fie mai mare decat zero" << endl;
            return;
        }
        this->pretBilet = pretBilet;
    }
    bool get_locValidat()
    {
        return this->locValidat;
    }
    void set_locValidat(bool locValidat)
    {
        this->locValidat = locValidat;
    }
    bool valideaza()
    {
        if (this->codRezervare == "ANULAT")
        {
            cout << "Eroare: Locul este anulat pentru filmul " << this->filmul << endl;
            return 0;
        }
        if (this->get_locValidat() != 1)
        {
            this->set_locValidat(1);
            cout << "Loc validat pentru filmul " << this->filmul << endl;
            return 1;
        }
        cout << "Eroare: Locul este validat deja pentru filmul " << this->filmul << endl;
        return 0;
    }
    void aplicaReducere(int Reducere)
    {
        double pretBiletOld = this->get_pretBilet();
        if (Reducere >= 100 || Reducere <= 0)
            cout << "Eroare la obiectul " << this->filmul << ": Reducerea trebuie sa fie intre 0 si 100" << endl;
        else
        {
            this->set_pretBilet(this->get_pretBilet() * (100 - Reducere) / 100.0);
            cout << "Pretul biletului pentru filmul " << this->filmul << " s-a aplicat reducerea de " << Reducere << endl
                 << pretBiletOld << " => " << this->get_pretBilet() << endl;
        }
    }
    void anuleaza()
    {
        if (this->codRezervare != "ANULAT")
        {
            this->codRezervare = "ANULAT";
            this->locValidat = false;
            cout << "Biletul pentru filmul " << this->filmul << " a fost anulat." << endl;
        }
        else
            cout << "Eroare la obiectul " << this->filmul << ": Biletul nu poate fi anulat de 2 ori" << endl;
    }
    string afiseazaDetalii()
    {
        return "Filmul: " + this->filmul + " Cod Rezervare: " + this->codRezervare +
               " Pret Bilet: " + to_string(this->pretBilet) + " Loc Validat: " + (this->locValidat ? "Da" : "Nu");
    }
};
int main()
{
    BiletCinema *b1 = new BiletCinema();
    cout << b1->afiseazaDetalii() << endl;
    b1->filmul = "Filmul 1";
    b1->set_codRezervare("");
    b1->set_codRezervare("rezerv1");
    b1->set_pretBilet(-20);
    b1->set_pretBilet(0);
    b1->set_pretBilet(45.0);
    cout << b1->afiseazaDetalii() << endl
         << endl;
    delete b1;
    BiletCinema *b2 = new BiletCinema("Filmul 2", "rezerv2", 80.0, false);
    cout << b2->afiseazaDetalii() << endl;
    b2->valideaza();
    b2->valideaza();
    b2->aplicaReducere(150);
    b2->aplicaReducere(25);
    cout << b2->afiseazaDetalii() << endl
         << endl;
    BiletCinema *b3 = new BiletCinema(*b2);
    delete b2;
    cout << b3->afiseazaDetalii() << endl;
    b3->filmul = "Filmul 3";
    b3->aplicaReducere(50);
    cout << b3->afiseazaDetalii() << endl;
    b3->anuleaza();
    b3->anuleaza();
    b3->valideaza();
    cout << b3->afiseazaDetalii() << endl;
    delete b3;
    return 0;
}
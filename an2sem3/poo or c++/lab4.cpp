#include <iostream>
#include <string>
using namespace std;
class Document
{
    int nrPagini;

protected:
    string titlu;

public:
    int obtineNrPagini()
    {
        return this->nrPagini;
    }
    void set_nrPagini(int nrPagini)
    {
        if (nrPagini <= 1 || nrPagini >= 1000)
        {
            cout << "Eroare: nrPagini trebuie sa fie intre 1 si 1000" << endl;
        }
        else
            this->nrPagini = nrPagini;
    }
    void afiseaza()
    {
        cout << "Titlu: " << this->titlu << " NrPagini: " << this->obtineNrPagini() << endl;
    }
    Document(string titlu, int nrPagini)
    {
        this->titlu = "template";
        this->nrPagini = 2;
        if ((titlu.empty()))
        {
            cout << "Eroare: titlu nu trebuie sa fie gol" << endl;
        }
        else
            this->titlu = titlu;
        set_nrPagini(nrPagini);
        cout << "Constructor (Document) apelat pentru " << this->titlu << endl;
    }
    ~Document()
    {
        cout << "Destructor (Document) apelat pentru " << this->titlu << endl;
    }
};
class DocumentOficial : public Document
{
protected:
    string nrInregistrare;

public:
    void afiseaza()
    {
        cout << "Titlu: " << this->titlu << " NrPagini: "
             << this->obtineNrPagini() << " NrInregistrare: " << this->nrInregistrare << endl;
    }
    bool esteUrgent()
    {
        if (this->nrInregistrare[0] == 'U')
        {
            return true;
        }
        return false;
    }
    DocumentOficial(string titlu, int nrPagini, string nrInregistrare) : Document(titlu, nrPagini)
    {
        this->nrInregistrare = "Null";
        if ((nrInregistrare.empty()))
        {
            cout << "Eroare: nrInregistrare nu trebuie sa fie gol" << endl;
        }
        else
            this->nrInregistrare = nrInregistrare;
        cout << "Constructor (DocumentOficial) apelat pentru " << this->titlu << endl;
    }
    ~DocumentOficial()
    {
        cout << "Destructor (DocumentOficial) apelat pentru " << this->titlu << endl;
    }
};
class Contract : public DocumentOficial
{
protected:
    double valoareLei;

public:
    void afiseaza()
    {
        cout << "Titlu: " << this->titlu << " NrPagini: "
             << this->obtineNrPagini() << " NrInregistrare: " << this->nrInregistrare
             << " ValoareaLei: " << this->valoareLei << endl;
    }
    Contract(string titlu, int nrPagini, string nrInregistrare, double valoareLei) : DocumentOficial(titlu, nrPagini, nrInregistrare)
    {
        this->valoareLei = 1.0;
        if (valoareLei <= 0)
        {
            cout << "Eroare: valoareLei > 0" << endl;
        }
        else
            this->valoareLei = valoareLei;
        cout << "Constructor (Contract) apelat pentru " << this->titlu << endl;
    }
    ~Contract()
    {
        cout << "Destructor (Contract) apelat pentru " << this->titlu << endl;
    }
};
class SemnaturaDigitala
{
protected:
    string algoritm;

public:
    void afiseaza()
    {
        cout << "Algoritm: " << this->algoritm << endl;
    }
    void semneaza(string semnatar)
    {
        if (semnatar.empty())
        {
            cout << "Eroare: \"semnatar\" nu poate fi gol" << endl;
            return;
        }
        cout << "Semnat de " << semnatar << " cu " << this->algoritm << endl;
    }
    SemnaturaDigitala(string algoritm)
    {
        this->algoritm = "RSA";
        if (algoritm != "RSA" && algoritm != "ECDSA")
        {
            cout << "Eroare: Algoritmul trebuie sa fie RSA sau ECDSA" << endl;
        }
        else
            this->algoritm = algoritm;
        cout << "Constructor (SemnaturaDigitala) apelat pentru " << this->algoritm << endl;
    }
    ~SemnaturaDigitala()
    {
        cout << "Destructor (SemnaturaDigitala) apelat pentru " << this->algoritm << endl;
    }
};
class ContractElectronic : public Contract, public SemnaturaDigitala
{
    int zileValabilitate;

public:
    void afiseaza()
    {
        cout << "Titlu: " << this->titlu << " Nr. Pagini: "
             << this->obtineNrPagini() << " Nr. Inregistrare: " << this->nrInregistrare
             << " Valoarea Lei: " << this->valoareLei << endl
             << "Algoritm: " << this->algoritm << " Zile Valabilitate: " << this->zileValabilitate << endl;
    }
    int timpCitire()
    {
        return 2 * obtineNrPagini();
    }
    void rezumat()
    {
        cout << this->nrInregistrare << " | " << this->valoareLei << " lei | "
             << this->algoritm << " | " << this->zileValabilitate << " zile" << endl;
    }
    ContractElectronic(string titlu, int nrPagini, string nrInregistrare, double valoareLei, string algoritm, int zileValabilitate) : Contract(titlu, nrPagini, nrInregistrare, valoareLei), SemnaturaDigitala(algoritm)
    {
        this->zileValabilitate = 2;
        if (zileValabilitate <= 1 || zileValabilitate >= 3650)
        {
            cout << "Eroare: zileValabilitate trebuie sa fie intre 1 si 3650" << endl;
        }
        else
            this->zileValabilitate = zileValabilitate;
        cout << "Constructor (ContractElectronic) apelat pentru " << this->titlu << endl;
    }
    ~ContractElectronic()
    {
        cout << "Destructor (ContractElectronic) apelat pentru " << this->titlu << endl;
    }
};
int main()
{
    Contract *c1 = new Contract("Ceva", 12, "U_suca", 356.0);
    delete c1;
    Contract c_test("", 1001, "", -2.0);

    ContractElectronic c_test_restu("nimic", 746, "Uiaibu", 5.0, "RSA", 28);
    return 0;
}
// Creează un obiect al derivatei de nivel 2 și arată din mesaje ordinea constructorilor de-a
// lungul lanțului (bază → nivel 1 → nivel 2) și a destructorilor (în ordine inversă);
// • Creează un obiect al clasei finale și arată din mesaje ordinea constructorilor (clasa de bază
// → nivel 1 → nivel 2 → a doua clasă de bază → clasa finală) și a destructorilor (în ordine
// inversă);
// • Apelează afiseaza() pe fiecare obiect;
// • Apelează, pe obiectul clasei finale, metodele proprii moștenite din ambele baze, apoi
// metodele proprii ale clasei finale;
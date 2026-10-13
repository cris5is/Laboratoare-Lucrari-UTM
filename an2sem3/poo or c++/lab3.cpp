#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double BONUS = 10.0;
const double TAXA = 5.0;
class Sold
{
    double valoare;

public:
    Sold(double valoare = 0.0)
    {
        this->valoare = valoare;
    }

    friend ostream &operator<<(ostream &out, const Sold &s)
    {
        out << "Sold: " << s.valoare;
        return out;
    }
};
class BankAccount
{
    string numarCont;
    double sold;

    static bool valideaza(string nr, double s)
    {
        if (nr.empty())
        {
            cout << "Numarul contului nu poate fi gol" << endl;
            return 0;
        }
        if (s < 0)
        {
            cout << "Soldul nu poate fi negativ" << endl;
            return 0;
        }
        return 1;
    }

public:
    BankAccount()
    {
        numarCont = "Nu stiu";
        sold = 0.0;
    }

    BankAccount(string numarCont, double sold)
    {
        this->numarCont = "Nu stiu";
        this->sold = 0.0;
        if (valideaza(numarCont, sold))
        {
            this->numarCont = numarCont;
            this->sold = sold;
        }
    }

    BankAccount &operator++()
    {
        sold += BONUS;
        return *this;
    }

    BankAccount &operator--()
    {
        sold = (sold >= TAXA) ? sold - TAXA : 0.0;
        return *this;
    }

    BankAccount operator+(double suma) const
    {
        if (suma < 0)
        {
            cout << "Suma trebuie sa fie pozitiva" << endl;
            return BankAccount(numarCont, sold);
        }
        return BankAccount(numarCont, sold + suma);
    }

    string operator[](int index) const
    {
        switch (index)
        {
        case 0:
            return numarCont;
        case 1:
            return to_string(sold);
        default:
        {
            cout << "Indexul este in afara limitei" << endl;
            return "";
        }
        }
    }

    bool operator==(BankAccount alt) const
    {
        return (sold == alt.sold);
    }

    explicit operator double() const { return sold; }
    explicit operator Sold() const { return Sold(sold); }

    friend istream &operator>>(istream &in, BankAccount &b);
    friend ostream &operator<<(ostream &out, const BankAccount &b);
};
istream &operator>>(istream &in, BankAccount &b)
{
    string nr;
    double s;
    if (!(in >> nr >> s))
        cout << "Eroare la citire" << endl;
    BankAccount::valideaza(nr, s);
    b.numarCont = nr;
    b.sold = s;
    return in;
}

ostream &operator<<(ostream &out, const BankAccount &b)
{
    out << "Numar cont: " << b.numarCont << " Sold: " << b.sold;
    return out;
}

int main()
{
    BankAccount a("", 100.0);
    BankAccount b("02020002", 100.0);
    cout << a << endl
         << b << endl;
    BankAccount c;
    cin >> c;
    cout << c << endl;

    cout << "Inainte: " << a << endl;
    ++a;
    cout << "Dupa:    " << a << endl
         << endl;

    cout << "Inainte: " << a << endl;
    --a;
    cout << "Dupa:    " << a << endl
         << endl;

    BankAccount mic("4684653", 3.0);
    cout << "Sold mic, inainte: " << mic << endl;
    --mic;
    cout << "Sold mic, dupa: " << mic << endl;

    BankAccount d = b + 50.0;
    cout << "b+50.0=" << d << "  (b ramane: " << b << ")" << endl;

    cout << "b[0] = " << b[0] << endl;
    cout << "b[1] = " << b[1] << endl;

    cout << "a == b ? " << (a == b ? "da" : "nu") << "  (" << (double)a << " si " << (double)b << ")" << endl;
    BankAccount e("5387656985", 100.0);
    cout << "b == e ? " << (b == e ? "da" : "nu") << endl;

    double s = (double)b;
    cout << "operator double(): " << fixed << setprecision(2) << s << endl;
    Sold so = Sold(b);
    cout << "operator Sold(): " << fixed << setprecision(2) << so << endl;

    return 0;
}
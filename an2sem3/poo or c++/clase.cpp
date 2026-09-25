#include <iostream>
using namespace std;
class Produs
{
public:
    static int Stoc;
    static void afiseaza_stoc()
    {
        cout << Stoc << endl;
    }
    string Nume;
    float Pret;
    enum Calitate
    {
        Rea,
        Medie,
        Buna,
        Excelenta
    };
    Calitate q;

    void afisare_date()
    {
        cout << "Nume: " << Nume << endl
             << "Pret: " << Pret << endl
             << "Calitate: " << q << endl;
    }
    Produs()
    {
        cout << "Produs creat\n";
        Stoc++;
    }
    ~Produs()
    {
        cout << "gata, nu-i ;(\n";
        Stoc--;
    }

private:
    string id;
};
int main()
{
    Produs::Stoc = 0;
    Produs *list = new Produs[10];
    Produs::afiseaza_stoc();
    delete[] list;
    Produs::afiseaza_stoc();
    return 0;
}
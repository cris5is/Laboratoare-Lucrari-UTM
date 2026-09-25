#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Hotel
{
    string Nume;
    int Stele;

    void citire()
    {
        cout << "Nume:";
        getline(cin, Nume);
        cout << "Stele:";
        cin >> Stele;
        cin.ignore();
    }
    void setNume(string name)
    {
        Nume = name;
    }
    void setStele(int numar)
    {
        Stele = numar;
    }
    void Import(string numefisier)
    {
        ifstream Readed(numefisier);
        getline(Readed, Nume);
        Readed >> Stele;
        Readed.close();
    }
    void Afisare()
    {
        cout << "Nume: " << Nume << " Nr. Stele = " << Stele << endl;
    }
};
void SortareDupaStele(Hotel *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i].Stele > arr[j].Stele)
            {
                Hotel temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
void Afisare(Hotel *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << arr[i].Nume << "  Nr. Stele = " << arr[i].Stele << endl;
    }
    cout << endl;
}
Hotel *Adauga(Hotel nou, Hotel *arr, int &n)
{
    Hotel *new_arr = new Hotel[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        new_arr[i] = arr[i - 1];
    }
    new_arr[0] = nou;
    n += 1;
    return new_arr;
}
void Export(Hotel *arr, string numefisier, int n)
{
    ofstream Exported(numefisier);
    for (int i = 0; i < n; i++)
    {
        Exported << arr[i].Nume << endl
                 << arr[i].Stele << endl;
    }
    Exported.close();
}

int main()
{
    int n;
    cout << "n=";
    cin >> n;
    cin.ignore();
    Hotel *hoteluri = new Hotel[n];
    for (int i = 0; i < n; i++)
        hoteluri[i].citire();
    SortareDupaStele(hoteluri, n);
    Afisare(hoteluri, n);
    Hotel h;
    h.setNume("Radisson Blu");
    h.setStele(5);
    hoteluri = Adauga(h, hoteluri, n);
    Afisare(hoteluri, n);
    Export(hoteluri, "hoteluri.txt", n);
    Hotel nou;
    nou.Import("hoteluri.txt");
    nou.Afisare();
    return 0;
}
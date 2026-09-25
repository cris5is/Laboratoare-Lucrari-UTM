#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class BiletCinema
{
public:
    string filmul;

private:
    string codRezervare;
    double pretBilet;
    bool locValidat;
};
int main()
{
    double a = 5.3491;
    a *= 100;
    cout << fixed << setprecision(2) << floor(a) / 100.0 << endl;
    return 0;
}
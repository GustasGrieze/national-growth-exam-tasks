#include <iostream>
#include <fstream>
using namespace std;

int sunkiausia()
{

    ifstream fd("duomenys.txt");
    int n, reiksme, suma = 0, kiekis=0;
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> reiksme;
        suma = suma + reiksme;
        kiekis++;
    }

    int vidurkis = suma / kiekis;

    fd.close();

    return vidurkis;

}

int kiek_kupriniu()
{

    int sunkiausias = sunkiausia();
    int kiekis=0, n, reiksme;

    ifstream fd("duomenys.txt");

    fd >> n;
    for(int i=0; i<n; i++)
    {

        fd >> reiksme;
        if(sunkiausias>reiksme) kiekis++;

    }

    fd.close();

    return kiekis;
}

int main()
{


    ofstream fr("rezultatai.txt");

    int n, sunkiausias, kiekis;

    kiekis = kiek_kupriniu();
    sunkiausias = sunkiausia();

    cout << sunkiausias << kiekis;

    fr << sunkiausias <<" "<< kiekis;


    fr.close();

    return 0;
}

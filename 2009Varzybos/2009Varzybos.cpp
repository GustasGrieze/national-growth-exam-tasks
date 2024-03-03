#include <iostream>
#include <fstream>
using namespace std;

struct Dalyviai
{

    string pav;
    int m;
    int s;

};

void Rikiavimas(Dalyviai A[], int kiekis);
void Spausdinimas(Dalyviai G[], int nr);

int main()
{
    Dalyviai D[9], G[26]; //D - pradinis sarasas, G - galutinis sarasas;
    int n, kiek, nr = 0;
    char eil[21];
    //------Nuskaitymas
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> kiek;
        fd.ignore();
        for(int j=0; j<kiek; j++)
        {
            fd.get(eil, 20);
            D[j].pav = eil;
            fd >> D[j].m >> D[j].s;
            fd.ignore();

        }
        Rikiavimas(D, kiek);
        // Perrasom i kita masyva
        for(int j=0; j<kiek/2; j++)
        {
            G[nr] = D[j];
            nr++;
        }
        // -------
    }
    fd.close();
    //---------
    Rikiavimas(G, nr);
    Spausdinimas(G, nr);
    return 0;
}

void Spausdinimas(Dalyviai G[], int nr)
{

    ofstream fr("rezultatai.txt");
    for(int i=0; i<nr; i++)
    {
        fr << G[i].pav << G[i].m<<" "<<G[i].s << endl;
    }

    fr.close();

}

void Rikiavimas(Dalyviai A[], int kiekis)
{
    int l1, l2;
    for(int i=0; i<kiekis-1; i++)
    {
        for(int j=i+1; j<kiekis; j++)
        {
            l1 = A[i].m * 60 + A[i].s;
            l2 = A[j].m * 60 + A[j].s;
            if(l1>l2) swap(A[i], A[j]);
        }
    }
}

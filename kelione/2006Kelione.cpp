#include <bits/stdc++.h>
using namespace std;
struct Transportas
{
    string pav;
    int minu;
    double km;
};
void Nuskaitymas(Transportas A[], int & n, int & greitis, int & val, int & minu);
int Laikas(double atstumas, int gr);
void Skaiciavimas(Transportas A[], int n, int greitis);
void Spausdinimas(Transportas A[], int n, int val, int minu);

int main()
{
    int n, greitis, val, minu;
    Transportas A[100];
    Nuskaitymas(A, n, greitis, val, minu);
    Skaiciavimas(A, n, greitis, val, minu);
    Spausdinimas(A, n, val, minu);
    return 0;
}

void Spausdinimas(Transportas A[], int n, int val, int minu)
{
    ofstream fr("rezultatai.txt");
    for(int i=0; i<n; i++)
    {
        val = val + (minu + A[i].minu)/60;
        minu = (minu + A[i].minu)%60;
        fr << A[i].pav << val <<" val."<<minu<<" min. "<<endl;
    }
    fr.close();
}

void Skaiciavimas(Transportas A[], int n, int greitis, int val, int minu)
{
    for(int i=0; i<n; i++)
    {
        A[i].minu = Laikas(A[i].km, greitis);
    }
}

int Laikas(double atstumas, int gr)
{
    return roud(ats / gr*60);
}

void Nuskaitymas(Transportas A[], int & n, int & greitis, int & val, int & minu)
{
    char eil[16];
    ifstream fd("duomenys.txt");
    fd >> n >> greitis >> val >> minu;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 15);
        A[i].pav = eil;
        fd >> A[i].km;
        fd.ignore();
    }
    fd.close();
}

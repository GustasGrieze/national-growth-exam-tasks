#include <bits/stdc++.h>

using namespace std;

struct Duomenys
{
    string vardas;
    int kiek; // kiek zuvu, koef
    string zuv[6];
    int mase[6];
    int t=0; // taskai, mase
};

void Rikiavimas(Duomenys A[], int kiek);
int Svoriai(Duomenys Zuvys[], int k, string zuvis);

int main()
{
    int n, k;
    Duomenys Zvejai[31], Zuvys[31];
    char eil[21];
    //---NUSKAITYMAS----------------
    ifstream fd("duomenys.txt");
    fd >> n;
    fd.ignore();
    for(int i = 0 ; i < n ; i++)
    {
        fd.get(eil, 20);
        Zvejai[i].vardas = eil;
        fd >> Zvejai[i].kiek;
        fd.ignore();
        for(int j = 0 ; j < Zvejai[i].kiek ; j++)
        {
            fd.get(eil, 20);
            Zvejai[i].zuv[j] = eil;
            fd >> Zvejai[i].mase[j];
            if(Zvejai[i].mase[j] >= 200)
            {
                Zvejai[i].t += 30;
            }
            else
            {
                Zvejai[i].t += 10;
            }
            fd.ignore();
        }
    }
    fd >> k;
    fd.ignore();
    for(int i=0; i<k; i++)
    {
        fd.get(eil, 20);
        Zuvys[i].vardas = eil;
        fd >> Zuvys[i].kiek;
        fd.ignore();
    }
    fd.close();
    //------------------------------

    int nr;
    //--- Zvejo taskai / Zuvies svoris ----
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<Zvejai[i].kiek; j++)
        {
            nr = Svoriai(Zuvys, k, Zvejai[i].zuv[j]);
            Zvejai[i].t += Zuvys[nr].kiek;
            Zuvys[nr].t += Zvejai[i].mase[j];
        }
    }

    Rikiavimas(Zvejai, n);
    Rikiavimas(Zuvys, k);
    //--------- Spausdinimas ----
    ofstream fr("rezultatai.txt");
    fr << "Dalyviai" << endl;
    for(int i=0; i<n; i++)
    {
        fr << Zvejai[i].vardas <<" "<<Zvejai[i].t <<endl;
    }
    fr << "Laimikis" << endl;
    for(int i=0; i<k; i++)
    {
        fr << Zuvys[i].vardas <<" "<<Zuvys[i].t << endl;
    }
    fr.close();
    //-----------
    return  0;
}

void Rikiavimas(Duomenys A[], int kiek)
{
    for(int i=0; i<kiek-1; i++)
    {
        for(int j=i+1; j<kiek; j++)
        {
            if(A[i].t < A[j].t)
            {
                swap(A[i], A[j]);
            }
            if(A[i].t == A[j].t && A[i].vardas > A[j].vardas)
            {
                swap(A[i], A[j]);
            }
        }
    }
}

int Svoriai(Duomenys Zuvys[], int k, string zuvis)
{
    for(int i=0; i<k; i++)
    {
        if(zuvis == Zuvys[i].vardas)
        {
            return i;
        }
    }
}


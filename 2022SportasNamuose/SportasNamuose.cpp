#include <iostream>
#include <fstream>
using namespace std;
struct Sportas
{

    string pav;
    int diena = 0;
    int rytas = 0;
    int vakaras = 0;
    int dienosID;
    int kiek = 0;
    int viso = 0;
    int kiekis = 0;

};

void Sarasas(Sportas A[], int na, Sportas B[], int & nb);
int Yra(Sportas B[], int nb, string prat);

int main()
{
    Sportas A[170], B[6];

    int n, k, na = 0, kiek, nb = 0; // na = pratimu masyve
    char eil[19];
    string zodis; // saugos rytas, diena, vakaras
    //--------Nuskaitymas--
    ifstream fd("U2.txt");
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> k;
        for(int j=0; j<k; j++)
        {
            fd. get(eil, 17);
            A[na].pav = eil;
            fd >> zodis;
            fd >> A[na].kiek;
            if(zodis == "Rytas")
            {
                A[na].rytas++;
            }
            if(zodis == "Diena")
            {
                A[na].diena++;
            }
            if(zodis == "Vakaras")
            {
                A[na].vakaras++;
            }
            A[na].dienosID = i + 1;
            na++;
        }
        fd.ignore();
    }

    fd.close();
    Sarasas(A, na, B, nb);
    //---Rikiavimas---
    for(int i=0; i<nb-1; i++)
    {
        for(int j=i+1; j< nb;j++)
        {
            if(B[i].pav > B[j].pav)
            {
                swap(B[i],B[j]);
            }
        }
    }
    //-----

    //--- Spausdinimas--

    ofstream fr("rezultatai.txt");

    for(int i=0; i < nb; i++)
    {
        fr << B[i].pav <<" "<<B[i].kiekis<<" "<<B[i].viso<<endl;

    if(B[i].rytas != 0)
    {
        fr << "Rytas     " << B[i].rytas << endl;
    }
     if(B[i].diena != 0)
    {
        fr << "Diena     " << B[i].diena << endl;
    }

     if(B[i].vakaras != 0)
    {
        fr << "Vakaras     " << B[i].vakaras << endl;
    }
    }



    fd.close();
    //------
    return 0;
}

void Sarasas(Sportas A[], int na, Sportas B[], int & nb)
{
    int kur;
    for(int i=0; i<na; i++)
    {
        kur = Yra(B, nb, A[i].pav);
        if(kur >= 0)
        {
            B[kur].viso += A[i].kiek;
            B[kur].rytas += A[i].rytas;
            B[kur].diena += A[i].diena;
            B[kur].vakaras += A[i].vakaras;
            if(B[kur].dienosID != A[i].dienosID)
            {
                B[kur].kiekis++;
            }
            B[kur].dienosID = A[i].dienosID;
        }
        else
        {
            B[nb].pav = A[i].pav;
            B[nb].viso = A[i].kiek;
            B[nb].rytas = A[i].rytas;
            B[nb].diena = A[i].diena;
            B[nb].vakaras = A[i].vakaras;
            B[nb].kiekis = 1;
            B[nb].dienosID = A[i].dienosID;
            nb++;
        }
    }
}

int Yra(Sportas B[], int nb, string prat)
{
    for(int i=0; i<nb; i++)
    {
        if(B[i].pav == prat)
        {
            return i;
        }

    }
    return -1;
}

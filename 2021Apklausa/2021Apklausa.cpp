#include <iostream>
#include <fstream>
using namespace std;

struct Mokiniai
{
    string vardas;
    string dalykas;
    double vidurkis;
};

struct Dalykai
{
    string dal;
    int pop = 0;
};

void Nuskaitymas(Mokiniai A[], int & m);
void Atranka(Mokiniai A[], int m, Dalykai D[], int & p);
int Yra(Dalykai D[], int p, string dalykas);
void Rikiavimas(Dalykai D[], int p);

int main(){

    Mokiniai A[50];
    int m;
    Dalykai D[50];
    int p = 0;
    Nuskaitymas(A, m);
    Atranka(A, m, D, p);
    Rikiavimas(D, p);
    //---Spausdinimas
    ofstream fr("rezultatai.txt");
    if(p==0) fr <<"Neatitinka vidurkis";
    for(int i=0; i<p; i++)
    {
        fr << D[i].dal <<" "<<D[i].pop<<endl;
        for(int j=0; j<m; j++)
        {
            if(A[j].dalykas == D[i].dal && A[j].vidurkis >= 9)
            {
                fr << A[j].vardas << endl;
            }
        }
    }
    fr.close();
    return 0;
}

void Rikiavimas(Dalykai D[], int p)
{
    for(int i=0; i<p-1; i++)
    {
        for(int j=i+1; j<p; j++)
        {
            if(D[i].pop < D[j].pop) swap(D[i], D[j]);
            if(D[i].pop == D[j].pop && D[i].dal > D[j].dal) swap(D[i], D[j]);
        }
    }
}

int Yra(Dalykai D[], int p, string dalykas)
{
    for(int i=0; i<p; i++)
    {
        if(D[i].dal == dalykas)
        {
            return i;
        }
    }
    return -1;
}

void Atranka(Mokiniai A[], int m, Dalykai D[], int & p)
{
    int kur;
    for(int i=0; i<m; i++)
    {
        kur = Yra(D, p, A[i].dalykas);
        if(kur >= 0 && A[i].vidurkis >= 9)
        {
           D[kur].pop++;
        }
        else if(A[i].vidurkis >= 9)
        {
            D[p].dal = A[i].dalykas;
            D[p].pop++;
            p++;
        }
    }
}

void Nuskaitymas(Mokiniai A[], int & m)
{
    int k;
    double p, sum = 0;
    ifstream fd("U2.txt");
    fd >> m;
    for(int i=0; i<m; i++)
    {
        fd >> A[i].vardas;
        fd >> A[i].dalykas;
        fd >> k;
        for(int j=0; j<k; j++)
        {
            fd >> p;
            sum += p;
        }
        A[i].vidurkis = sum / (double)k;
        sum = 0;
    }
    fd.close();
}

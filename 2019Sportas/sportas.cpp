#include <bits/stdc++.h>

using namespace std;

struct Dalyviai
{
    string vardas;
    int nr;
    int start;
    int stop = 0; //bool finisas = false;
    int laikas;
    int bauda;
};

void Rikiavimas(int n, Dalyviai A[]);
void Spausdinimas(int n, Dalyviai A[], int kas);

int main()
{
    Dalyviai A[31];
    int n, val, minu, sek, nr, m;
    int t1, t2, t3, t4, bauda, finisas;
    char eil[21];
    //----Nuskaitymas-----
    ifstream fd("u2.txt");
    fd >> n;
    fd.ignore();
    for(int i = 0 ; i < n ;i++)
    {
        fd.get(eil, 20);
        A[i].vardas = eil;
        fd >> A[i].nr ;
        fd >> val >> minu >> sek;
        A[i].start = val * 3600 + minu * 60 + sek;
        fd.ignore();
    }
    fd >> m;
    for(int i = 0 ; i < m ;i++)
    {
        fd >> nr >> val  >> minu >> sek ;
        finisas = val * 3600 + minu *60 + sek;
        if (nr / 100 == 1)
        {
            fd >> t1 >> t2;
            bauda = (10 - t1 - t2)*60;
        }
        else
        {
            fd >> t1 >> t2 >> t3 >> t4;
            bauda = (20 - t1 - t2 - t3 - t4)*60;
        }
        for(int j = 0 ; j < n ; j++)
        {
            if (nr == A[j].nr)
            {
                A[j].stop = finisas;
                A[j].laikas = A[j].stop - A[j].start + bauda;
                break;
            }
        }
    }
    fd.close();
    //---------------------
    Rikiavimas(n, A);
    ofstream fr("rezultatai.txt");
    fr.close();
    Spausdinimas(n, A, 1);
    Spausdinimas(n, A, 2);
    return 0;
}

void Spausdinimas(int n, Dalyviai A[], int kas)
{
    ofstream fr("rezultatai.txt", ios::app);
    if (kas==1) fr <<"Merginos"<<endl;
      else fr <<"Vaikinai"<<endl;
    for(int i = 0 ; i < n ; i++)
       if (kas == A[i].nr / 100 && A[i].stop != 0)
        fr << A[i].vardas <<" "<<A[i].laikas / 3600 <<" "<<A[i].laikas %3600 / 60 <<" "<<A[i].laikas %3600%60<<endl;

    fr.close();
}

void Rikiavimas(int n, Dalyviai A[])
{
    for(int i = 0 ; i < n-1 ; i++)
        for(int j = i+1 ; j < n ;j++)
    {
        if (A[i].laikas > A[j].laikas) swap(A[i], A[j]);
        if (A[i].laikas== A[j].laikas && A[i].vardas > A[j].vardas) swap(A[i], A[j]);
    }
}

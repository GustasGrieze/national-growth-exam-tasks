#include <bits/stdc++.h>

using namespace std;

struct Pratimai
{
    string pav;
    int sk;
};


int Yra(Pratimai B[], int m, string pratimas);
void Rikiavimas(Pratimai B[], int m);



int main()
{
    Pratimai A[100], B[100];
    int n, m  = 0, i;
    //---Nuskaitymas------
    char eil[20];
    ifstream fd("duomenys.txt");
    fd >> n;
    fd.ignore();
    for (i = 0; i < n; i++)
    {
        fd.get(eil, 20);
        A[i].pav = eil;
        fd >> A[i].sk;
        fd.ignore();
    }
    fd.close();
    //-------Atranka-----------
    int k;
    for (i = 0; i < n; i++)
    {
        k = Yra(B, m, A[i].pav);
        if (k >= 0) B[k].sk += A[i].sk;
        else
        {
            B[m] = A[i];
            m++;
        }
    }
    //--------------
    Rikiavimas(B, m);
    //----- Spausdinimas-----
    ofstream fr("rezultatai.txt");
    for(i = 0; i < m; i++)
        fr << B[i].pav<<B[i].sk<<endl;
    fr.close();
    return 0;
}


int Yra(Pratimai B[], int m, string pratimas)
{
    for(int i = 0; i < m; i++)
        if (B[i].pav == pratimas ) return i;
    return -1;
}

void Rikiavimas(Pratimai B[], int m)
{
    int i, j;
    for(i = 0; i < m-1; i++)
        for(j = i + 1; j  < m; j++)
            if (B[i].sk < B[j].sk) swap(B[i], B[j]);
}

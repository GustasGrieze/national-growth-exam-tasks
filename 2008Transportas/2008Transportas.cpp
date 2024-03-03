#include <iostream>
#include <fstream>
using namespace std;

struct Transportas
{
    string pav;
    int k;
    int M[1000];
};

void Nuskaitymas(Transportas A[], int & n);
int Ilgiausias(Transportas A[], int n);
void Spausdinimas(Transportas A[], int n);

int main()
{
    Transportas A[101];
    int n;
    Nuskaitymas(A, n);
    Spausdinimas(A, n);
    return 0;
}

int Ilgiausias(Transportas A[], int n)
{

    int MA[1000] = {0}, maxM = 0, indeksas;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<A[i].k; j++)
        {
            int ind = A[i].M[j];
            MA[ind]++; //MA[A[i].M[j]]++;
        }
    }

    for(int i=0; i<1000; i++)
    {
        if(MA[i] > maxM)
        {
            maxM = MA[i];
            indeksas = i;
        }
    }
    return indeksas;
}

void Spausdinimas(Transportas A[], int n)
{
    int indeksas;
    indeksas = Ilgiausias(A, n);
    cout << indeksas;
    ofstream fr("rezultatai.txt");
    fr << indeksas << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<A[i].k; j++)
        {
            if(A[i].M[j]==indeksas)
            {
                fr << A[i].pav << endl;
            }
        }
    }
    fr.close();
}

void Nuskaitymas(Transportas A[], int & n)
{
    ifstream fd("duomenys.txt");
    char eil[21];
    fd >> n;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 20);
        A[i].pav = eil;
        fd >> A[i].k;
        for(int j=0; j<A[i].k; j++)
        {
            fd >> A[i].M[j];
        }
        fd.ignore();
    }
    fd.close();
}

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Dalyviai
{
    string vardas;
    int taskai = 0;
    int uzdaviniai = 0;
    int laikas = 0;
    int sugLaikai[13];
};

void Skaiciavimas(int u, int laikai[], int taskaii[], Dalyviai A[]);\

int main()
{
    Dalyviai A[6];
    int u, laikai[6], taskaii[6];
    char eil[12];

    //-------Nuskaitymas
    ifstream fd("U1.txt");

    fd >> u;
    for(int i=0; i<u; i++)
    {
        fd >> laikai[i];
    }
    for(int i=0; i<u; i++)
    {
        fd >> taskaii[i];
    }
    for(int i=0; i<5; i++)
    {
        fd.ignore();
        fd.get(eil, 11);
        A[i].vardas = eil;
        for(int j=0; j<u; j++)
        {
            fd >> A[i].sugLaikai[j];
        }
        cout << A[i].vardas << endl;
    }

    fd.close();
    //--------
    Skaiciavimas(u, laikai, taskaii, A);

    //---- Didziausias tasku kiekis
    int maxim = 0;

    for(int i=0; i<5; i++)
    {
        if(A[i].taskai > maxim)
        {
            maxim = A[i].taskai;
        }
    }
    //----------

    //---------Rikiavimas
    for(int i=0; i<5; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(A[i].uzdaviniai < A[j].uzdaviniai)
            {
                swap(A[i], A[j]);
            }
        }
    }
    //---------------

    //----Spausdinimas
    ofstream fr("rezultatai.txt");
    fr << maxim << endl;
    for(int i=0; i<5; i++)
    {
        if(A[i].taskai == maxim)
        {
            fr << A[i].vardas << A[i].uzdaviniai <<" "<< A[i].laikas <<endl;
        }
    }

    fr.close();
    //--------------
    return 0;
}
void Skaiciavimas(int u, int laikai[], int taskaii[], Dalyviai A[])
{

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<u; j++)
        {
            if(A[i].sugLaikai[j]>0)
            {
                A[i].uzdaviniai++;
                A[i].laikas += A[i].sugLaikai[j];
            }
        }
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<u; j++)
        {
            if(A[i].sugLaikai[j] > 0)
            {
                if(A[i].sugLaikai[j] > laikai[j])
                {
                    A[i].taskai += taskaii[j]/2;
                }
                else
                {
                    A[i].taskai += taskaii[j];
                }
            }
        }
    }

}

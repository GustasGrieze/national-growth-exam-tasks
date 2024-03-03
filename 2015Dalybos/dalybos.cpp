#include <iostream>
#include <fstream>

using namespace std;

void Veiksmai(int V[], int T[]);



int main()
{
    int V[20] ={0}, T[10]={0};
    //---Nuskaitymas---
    int i;
    ifstream fd("duomenys.txt");
    for(i=0; i < 10; i++)
    {
        fd >> V[i];
        T[i]=10 - V[i];
    }
    fd.close();
    //----------
    Veiksmai(V, T);
   ofstream fr("rezultatai.txt");
    for(int i=0; i < 20; i++)
    {
       fr<<V[i]<<"  ";
    }
    fr.close();
    return 0;
}

void Veiksmai(int V[], int T[])
{
    int i, j, nr=1;
    for(i=0; i < 10 ; i++)
    {
        j = nr;
        while(T[i] > 0)
        {
            V[j]++;
            T[i]--;
            j++;
        }
        nr++;
    }
}

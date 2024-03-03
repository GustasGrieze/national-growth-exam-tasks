#include <fstream>
#include <iostream>
using namespace std;

void skaitymas(int Start[], int Zaide[], int Sedejo[])
{

    ifstream fd("U1.txt");

    int n, skaicius, laikai, laikas;
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> skaicius;
        fd >> laikai;
        for(int j=0; j<laikai; j++)
        {
            fd >> laikas;
            if(j == 0 && laikas > 0)
            {
                Start[skaicius] = laikas;
            }
            if(laikas > 0)
            {
                Zaide[skaicius] += laikas;
            }
            else
            {
                Sedejo[skaicius] += abs(laikas);
            }
        }
    }

    fd.close();

}

int daugiausiai(int Zaide[]){

int didziausias = 0, indeksas;
for(int i=0; i<100; i++){
    if(Zaide[i] > didziausias){
        didziausias = Zaide[i];
        indeksas = i;
    }
}

return indeksas;

}

int main()
{

    ofstream fr("U1REZ.txt");

    int Start[100] = {0}, Zaide[100] = {0}, Sedejo[100] = {0};


    skaitymas(Start, Zaide, Sedejo);

    for(int i=0; i<100; i++)
    {
        if(Start[i] > 0)
        {
            fr << i <<" ";
        }
    }

    int indeksas = daugiausiai(Zaide);
    fr << endl << indeksas <<" "<< Zaide[indeksas] << endl;
    int indeksas_2 = daugiausiai(Sedejo);
    fr << indeksas_2 <<" " << Sedejo[indeksas_2];
    fr.close();

    return 0;
}

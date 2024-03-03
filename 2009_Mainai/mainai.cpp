#include <iostream>
#include <fstream>
using namespace std;

int PiniguSuma(int Nominalai[], int Monetos[], int kiekis)
{

    int suma = 0;

    for(int i=0; i<kiekis; i++)
    {
        suma += Nominalai[i] * Monetos[i];
    }

    return suma;

}

void Keitimas(int sum, int N[], int n){
int k, viso=0;
ofstream fr("rezultatai.txt", ios::app);
for(int i=0; i<n; i++){

    k = sum / N[i];
    sum = sum % N[i];
    viso += k;
    fr << N[i] <<" "<< k << endl;

}

fr << viso<< endl;

fr.close();

}


int main()
{

    ifstream fd("duomenys.txt");

    int EN[51], EM[51], GN[51], GM[51]; //EN - Eglijos nominalai
    int ng, ne;
    int suma_eg, suma_gi;

//-------------Skaitymas
    fd >> ng;
    for(int i=0; i<ng; i++)
    {
        fd >> GN[i];
    }
    for(int i=0; i<ng; i++)
    {
        fd >> GM[i];
    }


    fd >> ne;
    for(int i=0; i<ne; i++)
    {
        fd >> EN[i];
    }
    for(int i=0; i<ne; i++)
    {
        fd >> EM[i];
    }
//-------------------


    suma_eg = PiniguSuma(EN, EM, ne);
    suma_gi = PiniguSuma(GN, GM, ng);

    ofstream fr("rezultatai.txt");
    fr.close();

    Keitimas(suma_gi, EN, ne);
    Keitimas(suma_eg, GN, ng);


    fd.close();

    return 0;

}

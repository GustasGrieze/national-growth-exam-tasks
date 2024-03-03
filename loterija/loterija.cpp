#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{

    int n;
    int isl, laime; //isl = islaidos, laim - laimejimai
    int isleido = 0, laimejo = 0;
    int maxL = 0, nr, kiek =0;
    ifstream fd("loterija.txt");
    ofstream fr("rezultatai.txt");

    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> isl >> laime;
        isleido += isl; //isleido = isleido + isl;
        laimejo += laime;
        if(laime > maxL){
            maxL = laime;
            nr = i+1;
        if(laime == 0) kiek++;

        }
    }
    fr << isleido << " " << laimejo << endl;
    fr <<"Didziausias laimejimas "<< maxL << endl;
    if(laimejo == isleido) fr <<"Lygiosios";
        else if (laimejo > isleido) fr << "Pelnas: " << laimejo-isleido;
            else fr<<"Nuostolis: " << isleido-laimejo;

    fr << "Didziausias laimejimas buvo: " << nr << endl;
    fr << "Nieko nelaimejo: " << kiek << "Kartu" << endl;
    fd.close();
    fr.close();

    return 0;

}

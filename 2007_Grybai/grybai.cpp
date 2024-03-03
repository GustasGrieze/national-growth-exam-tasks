#include <iostream>
#include <fstream>
using namespace std;



int dienos_numeris(int B[], int R[], int L[]){

int kiekis=0;
int didziausia_reiksme = 0, didziausias_indeksas;

for(int i=0; i<31; i++){
    kiekis = B[i] + R[i] + L[i];
    if(kiekis>didziausia_reiksme){
        didziausia_reiksme = kiekis;
        didziausias_indeksas = i;
    }
}

return didziausias_indeksas;

}

void spausdinimas(int B[], int R[], int L[], int didziausias_indeksas){

ofstream fr("rezultatai.txt");

for(int i=0; i<31; i++){
    if(B[i] > 0 || R[i] > 0 || L[i] > 0){
        fr << i << " " << B[i] << " " << R[i] << " " << L[i] << endl;
    }

}

fr << didziausias_indeksas << " " << B[didziausias_indeksas] + R[didziausias_indeksas] + L[didziausias_indeksas];
fr.close();

}

int main(){

int n, d, B[31] = {0}, R[31] = {0}, L[31] = {0};
int bar, rau, lep;

ifstream fd("duomenys.txt");

fd >> n;
for(int i=0; i<n; i++){
    fd >> d;
    fd >> bar >> rau >> lep;
    B[d] += bar;
    R[d] += rau;
    L[d] += lep;
}

int didziausias_indeksas = dienos_numeris(B, R, L);

spausdinimas(B, R, L, didziausias_indeksas);

fd.close();

return 0;
}



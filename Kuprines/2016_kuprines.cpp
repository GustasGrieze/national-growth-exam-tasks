#include <iostream>
#include <fstream>
using namespace std;

int sunkiausia(){

ifstream fd("duomenys.txt");
int n, sunkiausias = 0, reiksme;
fd >> n;
for(int i=0; i<n; i++){
fd >> reiksme;
if(reiksme > sunkiausias) sunkiausias = reiksme;
}

fd.close();

return sunkiausias;

}

int kiek_kupriniu(){

int sunkiausias = sunkiausia();
int kiekis=0, n, reiksme;

ifstream fd("duomenys.txt");

fd >> n;
for(int i=0; i<n; i++){

fd >> reiksme;
if((sunkiausias-reiksme*2)>=0) kiekis++;

}

fd.close();

return kiekis;
}

int main(){


ofstream fr("rezultatai.txt");

int n, sunkiausias, kiekis;

kiekis = kiek_kupriniu();
sunkiausias = sunkiausia();

fr << sunkiausias <<" "<< kiekis;


fr.close();

return 0;
}

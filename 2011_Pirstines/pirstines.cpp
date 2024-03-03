#include <iostream>
#include <fstream>
using namespace std;

void skaitymas(int MK[], int MD[], int VK[], int VD[]);
int Poros(int K[], int D[]);
int Likutis(int p, int K[], int D[]);

int main(){

int MK[100] = {0}, MD[100] = {0}; //Moteriska kaire, moteriska desine
int VK[100] = {0}, VD[100] = {0};
int pM, pV;

skaitymas(MK, MD, VK, VD);

pV = Poros(VK, VD);
pM = Poros(MK, MD);

ofstream fr("rezultatai.txt");
fr << pM <<endl<< pV<< endl;
fr << Likutis(MK, MD);
fr << Likutis(VK, VD);
fr.close();

for(int i=0; i < 100; i++){
    if(MK[i] != 0) cout << i <<" "<<MK[i] << endl;
}

return 0;
}

void skaitymas(int MK[], int MD[], int VK[], int VD[]){

    int n;
    int lytis, dydis, ranka;
    ifstream fd("duomenys.txt");

    fd >> n;
    for(int i=0; i<n; i++){
        fd >> lytis >> ranka >> dydis;
        if(lytis == 4 && ranka == 1) MK[dydis]++;
        if(lytis == 4 && ranka == 2) MD[dydis]++;
        if(lytis == 3 && ranka == 2) VD[dydis]++;
        if(lytis == 3 && ranka == 1) VK[dydis]++;
    }
    fd.close();

}

int Poros(int K[], int D[]){

int p = 0;
for(int i=0; i < 100; i++){
    if(K[i] < D[i]) p += K[i];
        else p += D[i];
    return p;
}

}


int Likutis(int K[], int D[]){

    int liko =0;
    for(int i=0; i< 100; i++){
        liko += abs(K[i]-D[i]);

    }
    return liko;
}


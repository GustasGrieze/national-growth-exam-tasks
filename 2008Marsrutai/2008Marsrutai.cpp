#include <iostream>
#include <fstream>
using namespace std;

void Nuskaitymas(int IL[], int ISL[]);
void Spausdinimas(int IL[]);

int main()
{
    int IL[101] = {0}, ISL[101] = {0};

    Nuskaitymas(IL, ISL);

    return 0;
}

void Spausdinimas(int IL[])
{
    ofstream fr("rezultatai.txt");
    for(int i=0; i<101; i++){
        if(IL[i] != 0){
            fr<<i;
        }
    }
    fr.close();
}

void Nuskaitymas(int IL[], int ISL[]){
int n, m, zm;
ifstream fd("duomenys.txt");
fd >> n;
for(int i=0; i<n; i++){
    fd >> m >> zm;
    if(zm > 0){
        IL[m] += zm;
    } else {
        ISL[m] += zm;
    }
}

fd.close();
}

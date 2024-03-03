#include <iostream>
#include <fstream>
using namespace std;

struct Dievai
{
    string vardas;
    int taskai = 0;
    int lyginiai = 0;
};

void Skaitymas(Dievai Dievas[], int & n, int & k);
int Valdovas(Dievai Dievas[], int n, int k);

int main()
{

    Dievai Dievas[50];
    int n, k, indeksas;
    Skaitymas(Dievas, n, k);
    indeksas = Valdovas(Dievas, n, k);

    ofstream fr("rezultatai.txt");

    fr << Dievas[indeksas].vardas << " " << Dievas[indeksas].taskai;

    fr.close();

    return 0;
}

int Valdovas(Dievai Dievas[], int n, int k){
    int didziausias = 0, indeksas = 0, kiekis = 0, indeksai[50] = {0};
    for(int i=0; i<n; i++){
            if(Dievas[i].taskai > didziausias){
                didziausias = Dievas[i].taskai;
                indeksas = i;
            }
    }
    for(int i=0; i<n; i++){
        if(Dievas[indeksas].taskai==Dievas[i].taskai){
            indeksai[i] = i;
            indeksai[indeksas] = 0;
        }
    }
    didziausias = 0;
        for(int i=0; i<n; i++){
            if(indeksai[i]>= 1){

                if(Dievas[indeksai[i]].lyginiai > didziausias){
                    didziausias = Dievas[i].lyginiai;
                    indeksas = i;
            }
        }
    }
    return indeksas;
}

void Skaitymas(Dievai Dievas[], int & n, int & k)
{
    ifstream fd("duomenys.txt");
    char eil[11];
    int taskas;
    fd >> n >> k;
    for(int i=0; i<n; i++)
    {

        fd.ignore();
        fd.get(eil, 10);
        Dievas[i].vardas = eil;
        for(int j=0; j<k; j++)
        {
            fd >> taskas;
            if(taskas%2==0){
                Dievas[i].taskai += taskas;
                Dievas[i].lyginiai++;
            } else {
                Dievas[i].taskai -= taskas;
            }
        }
    }
    fd.close();
}

#include <iostream>
#include <fstream>
using namespace std;

struct Sokejai
{
    string vardai;
    int viso;
};

void Nuskaitymas(Sokejai S[], int & n);
void Rikiavimas(Sokejai S[], int n);
int Balai(int B[], int k);

int main()
{
    Sokejai S[101];
    int n;
    Nuskaitymas(S, n);
    Rikiavimas(S, n);
    ofstream fr("rezultatai.txt");
    for(int i=0; i<n; i++)
    {
        fr << S[i].vardai <<" "<<S[i].viso << endl;
    }
    fr.close();
    return 0;
}

void Rikiavimas(Sokejai S[], int n)
{
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(S[i].viso < S[j].viso){
                swap(S[i], S[j]);
            }
        }
    }
}

int Balai(int B[], int k)
{
    int sum = 0, maxB = B[0], minB = B[0];
    for(int i=0; i<k; i++)
    {
        sum += B[i];
        if(B[i] < minB) minB = B[i];
        if(B[i] > maxB) maxB = B[i];
    }
    return sum - minB - maxB;
}

void Nuskaitymas(Sokejai S[], int & n)
{

    int k;
    int A[11], T[11];
    char eil[21];
    ifstream fd("duomenys.txt");
    fd >> n >> k;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 20);
        S[i].vardai = eil;
        fd.ignore();
        for(int j=0; j<k; j++)
        {
         fd >> A[j];
        }
        for(int j=0; j<k; j++)
        {
         fd >> T[j];
        }
        S[i].viso = Balai(A, k) + Balai(T, k);
        cout << S[i].viso << endl;
        fd.ignore();
    }
    fd.close();
}

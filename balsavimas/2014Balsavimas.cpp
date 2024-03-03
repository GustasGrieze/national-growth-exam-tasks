#include <iostream>
#include <fstream>
using namespace std;

int geriausias(int T[], int dir[])
{
    if(T[0] > T[1] && T[0] > T[2]){
        return 1;
    } else if(T[1] > T[0] && T[1] > T[2]){
        return 2;
    } else if(T[2] > T[0] && T[2] > T[1]) {
        return 3;
    }

}

void taskai(int k, int log1[], int log2[], int log3[], int T[])
{
for(int i=0; i<k; i++){
    if(log1[i] > log2[i] && log1[i] > log3[i]){
        T[0] += 4;
    } else if(log2[i] > log1[i] && log2[i] > log3[i]) {
        T[1] += 4;
    } else if(log3[i] > log1[i] && log3[i] > log2[i]){
        T[2] += 4;
    }

    if(log1[i] == log2[i] && log1[i] > log3[i] && log2[i] > log3[i]){
        T[0] += 2;
        T[1] += 2;
    } else if(log1[i] == log3[i] && log1[i] > log2[i] && log3[i] > log2[i]){
        T[0] += 2;
        T[2] += 2;
    } else if(log2[i] == log3[i] && log2[i] > log1[i] && log3[i] > log1[i]){
        T[1] += 2;
        T[2] += 2;
    }
}

}

int main(){

int k, log1[10], log2[10], log3[10], dir[3], T[3] = {0};
int b1 = 0, b2 = 0, b3 = 0;

ifstream fd("duomenys.txt");

fd >> k;
for(int i=0; i<k; i++){
    fd >> log1[i] >> log2[i] >> log3[i];
    b1 += log1[i];
    b2 += log2[i];
    b3 += log3[i];
}
    fd >> dir[0] >> dir[1] >> dir[2];

    taskai(k, log1, log2, log3, T);
    cout << T[0] << T[1] << T[2];

    if(T[0] == T[1] && T[0] == T[2]){
        T[0] += dir[0];
        T[1] += dir[1];
        T[2] += dir[2];
    }

    int laimejo = geriausias(T, dir);

    ofstream fr("rezultatai.txt");

    fr << b1 <<" "<< b2 <<" "<< b3 <<" "<<endl;
    fr << T[0] <<" "<< T[1] <<" "<< T[2]<< endl;
    fr << laimejo;

    fr.close();
fd.close();

return 0;
}

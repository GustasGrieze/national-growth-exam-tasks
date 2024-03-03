#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    int n, m;
    double r, bendra_suma=0, suma=0;
    ifstream fd("duomenys.txt");
    ofstream fr("rezultatai.txt");

    fd >> n;
    for(int i=0; i<n; i++){
        fd >> m;
        suma = 0;
        for(int j=0; j<m; j++){
            fd >> r;
            suma = suma + 1/r;
        }
        bendra_suma = bendra_suma + 1/suma;
    }

cout << bendra_suma;

    fd.close();
    fr.close();
    return 0;
}

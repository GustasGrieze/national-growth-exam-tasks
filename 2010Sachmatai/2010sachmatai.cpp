#include <iostream>
#include <fstream>
using namespace std;

int kiekiss(int figuros[])
{

    int kiekis = 0;

    while(figuros[0] >= 8 && figuros[1] >= 2 && figuros[2] >= 2 && figuros[3] >= 2 && figuros[4] >= 1 && figuros[5] >= 1)
    {

        figuros[0] = figuros[0] - 8;
        figuros[1] = figuros[1] - 2;
        figuros[2] = figuros[2] - 2;
        figuros[3] = figuros[3] - 2;
        figuros[4] = figuros[4] - 1;
        figuros[5] = figuros[5] - 1;

        kiekis++;

    }

    return kiekis;

}

int main()
{

    ifstream fd("U1.txt");
    ofstream fr("U1REZ.txt");

    int figuros[6] = {0}, n, skaicius;

    fd >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            fd >> skaicius;
            figuros[j] += skaicius;
        }
    }

    int kiekis = kiekiss(figuros);
    fr << kiekis;

    fd.close();
    fr.close();

    return 0;

}

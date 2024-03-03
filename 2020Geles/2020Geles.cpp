#include <iostream>
#include <fstream>
using namespace std;

void Nuskaitymas(int G[]);
int Numeris(int men, int d);
int MaxDiena(int G[]);
void Intervalas(int ind, int & men, int & d);

int main()
{
    int G[93] = {0}, maxd, start, stop;
    int pM, pD, paM, paD;
    Nuskaitymas(G);
    maxd = MaxDiena(G);
    for(int i=1; i<=92; i++)
    {
        if(G[i] == maxd)
        {
            start = i;
            break;
        }
    }
    for(int i=start; i<= 92; i++)
    {
        if(G[i] != maxd)
        {
            stop = i;
            break;
        }
    }
    Intervalas(start, pM, pD);
    Intervalas(stop, paM, paD);

    ofstream fr("rezultatai.txt");

    fr << maxd << endl;
    fr << pM <<" "<<pD<<endl;
    fr << paM <<" "<<paD<<endl;
    fr.close();
    return 0;
}

void Intervalas(int ind, int & men, int & d)
{
        if(ind <= 30)
        {
            men = 6;
            d = ind;
        }
        else if(ind <= 61)
        {
            men = 7;
            d = ind - 30;
        }
        else
        {
            men = 8;
            d = ind - 61;
        }
}

int MaxDiena(int G[])
{
    int md = 0;
    for(int i=1; i <= 92; i++)
    {
        if(G[i] > md)
        {
            md = G[i];
        }
    }
    return md;
}

int Numeris(int men, int d)
{
    if(men == 6)
    {
        return d;
    }
    if(men == 7)
    {
        return 30 + d;
    }
    if(men == 8)
    {
        return 61 + d;
    }
}

void Nuskaitymas(int G[])
{
    int n, nr, pM, pD, paM, paD, start, stop;
    ifstream fd("duomenys.txt");
    fd >> n;
    for(int i=0; i<n; i++)
    {
        fd >> nr >> pM >> pD >> paM >> paD;
        start = Numeris(pM, pD);
        stop = Numeris(paM, paD);
        for(int j=start; j<stop; j++)
        {
            G[j]++;
        }

    }

    fd.close();
}

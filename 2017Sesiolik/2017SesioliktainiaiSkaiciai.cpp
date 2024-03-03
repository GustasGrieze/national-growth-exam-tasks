#include <fstream>
#include <iostream>
using namespace std;

string Kodas(int k);
char IntToString(int sk);

int main()
{
    int a, b, r, g, bl;
    string sesiol;
    ifstream fd("duomenys.txt");
    ofstream fr("rezultatai.txt");
    fd >> a >> b;
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            fd >> r >> g >> bl;
            sesiol = Kodas(r) + Kodas(g) + Kodas(bl);
            if(j != b)
            {
                fr << sesiol <<";";
            }
            else
            {
                fr << sesiol;
            }
        }
        fr<< endl;
    }

    fr.close();
    fd.close();
    return 0;
}

string Kodas(int k)
{
    string pirm, antr;
    int pirmas, antras;
    pirmas = k / 16;
    antras = k % 16;
    pirm = IntToString(pirmas);
    antr = IntToString(antras);
    return pirm + antr;
}
char IntToString(int sk)
{
    if(sk == 0)
    {
        return '0';
    }
    if(sk == 1)
    {
        return '1';
    }
    if(sk == 2)
    {
        return '2';
    }
    if(sk == 3)
    {
        return '3';
    }
    if(sk == 4)
    {
        return '4';
    }
    if(sk == 5)
    {
        return '5';
    }
    if(sk == 6)
    {
        return '6';
    }
    if(sk == 7)
    {
        return '7';
    }
    if(sk == 8)
    {
        return '8';
    }
    if(sk == 9)
    {
        return '9';
    }
    if(sk == 10)
    {
        return 'A';
    }
    if(sk == 11)
    {
        return 'B';
    }
    if(sk == 12)
    {
        return 'C';
    }
    if(sk == 13)
    {
        return 'D';
    }
    if(sk == 14)
    {
        return 'E';
    }
    if(sk == 15)
    {
        return 'F';
    }
}

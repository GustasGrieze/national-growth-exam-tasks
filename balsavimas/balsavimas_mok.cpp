#include <bits/stdc++.h>

using namespace std;

void Taskai(int B[], int T[]);
int Laimetojas(int T[], int d1, int d2, int d3);

int main()
{
    int k;
    int B[3], T[3]= {0};
    int b1 = 0, b2 = 0, b3 = 0;
    int d1, d2, d3;
    //--------NUSKAITYMAS---------
    ifstream fd("duomenys.txt");
    fd >>k;
    for(int i = 0 ; i < k ; i++)
    {
        fd >> B[0] >> B[1] >> B[2];
        b1 += B[0];
        b2 += B[1];
        b3 += B[2];
        Taskai(B, T);
    }
    fd >> d1 >> d2 >>d3;
    fd.close();
    //----------SPAUSDINIMAs------------------
    ofstream fr("rezultatai.txt");
    fr << b1<<" "<<b2<<" "<<b3<<endl;
    fr <<T[0] <<" "<<T[1]<<" "<<T[2]<<endl;
    fr << Laimetojas(T, d1, d2, d3) + 1;
    fr.close();
    return 0;
}

int Laimetojas(int T[], int d1, int d2, int d3)
{
    int maxT = T[0], nr=0, i, kiek = 0;
    for(i = 0 ; i < 3 ; i++)
        if (T[i] > maxT)
        {
            maxT = T[i];
            nr  = i;
        }
    for(i = 0 ; i <3 ; i++ )
        if (maxT == T[i]) kiek++;
    if (kiek == 1) return nr;
    else
    {
        T[0] += d1;
        T[1] += d2;
        T[2] += d3;
        maxT = T[0];
        for(i = 0 ; i < 3 ; i++)
        if (T[i] > maxT)
        {
            maxT = T[i];
            nr  = i;
        }
        return nr;
    }
}

void Taskai(int B[], int T[])
{
    int maxT = B[0], nr=0, i, kiek = 0;
    for(i = 0 ; i < 3 ; i++)
        if (B[i] > maxT)
        {
            maxT = B[i];
            nr  = i;
        }
    for(i = 0 ; i <3 ; i++ )
        if (maxT == B[i]) kiek++;
    if (kiek == 1) T[nr]+=4;
    if (kiek == 2)
    {
        if (B[0]==maxT) T[0]+=2;
        if (B[1]==maxT) T[1]+=2;
        if(B[2]==maxT) T[2]+=2;
    }
}

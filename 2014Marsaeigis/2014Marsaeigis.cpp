#include <iostream>
#include <fstream>
using namespace std;

struct Koordinates
{
    int kiek;
    int k[31];
    int kom = 0;
    bool tikslas = false;
};

int main()
{
    int x0, y0, x1, y1;
    Koordinates A[11];
    //----Nuskaitymas---
    ifstream fd("duomenys.txt");
    fd >> x0 >> y0 >> x1 >> y1 >> n;
    for(int i=0; i<n; i++)
    {
        fd >> A[i].kiek;
        for(int j=0; j<A[i].kiek; j++)
        {
            fd >> A[i].k[j];
        }
    }
    fd.close();

    //---- Veiksmai ---
    for(int i=0; i<n; i++)
    {
        x = x0;
        y= y0;
        int j=0;
        while(j < A[i].kiek && !A[i].tikslas)
        {
            if(x == x1 && y == y1)
            {
                A[i].tikslas = true;
            }
            else
            {
                if(A[i].k[j] == 1)
                {
                    y = y + 1;
                }
                if(A[i].k[j] == 2)
                {
                    x = x + 1;
                }
                if(A[i].k[j] == 3)
                {
                    y = y - 1;
                }
                if(A[i].k[j] == 4)
                {
                    x = x - 1;
                }
                j++;
                A[i].kom++;+
            }
            if(x == x1 && y == y1)
            {
                A[i].tikslas = true;
            }
        }
    }

    //----------spausdinimas-------
    ofstream fr("rezultatai");
    for(int i=0; i<n; i++)
    {
        if(A[i].tikslas)
        {
            fr << "Pasiektas tikslas";
            for(int j=0; j<A[i].kom; j++)
            {
                fr << A[i].k[j] << " ";
            }
            fr << A[i].kom << endl;
        }
        else
        {
            fr << "Sekos pabaiga";
            for(int j=0; j<A[i].kom; j++)
            {
                fr << A[i].k[j] << " ";
            }
            fr << A[i].kom << endl;
        }
        }
    }

    return 0;
}

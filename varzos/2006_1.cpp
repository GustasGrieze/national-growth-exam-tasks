#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int n, i, k, j;
    double r, r_suma, l_suma;
    ifstream fd("duomenys.txt");
    ofstream fr ("rezultatai.txt");
    fd >> n;
    l_suma = 0;
    for(i = 0; i < n; i++)
     {
         fd >> k;
         r_suma = 0;
         for(j = 0; j < k; j++ )
         {
            fd >> r;
            r_suma = r_suma + 1/r;
         }
        l_suma = l_suma + 1/r_suma;

     }
    fr << setw(8)<<fixed << setprecision(2)<<l_suma<<endl;
    fd.close();
    fr.close();
    return 0;
}

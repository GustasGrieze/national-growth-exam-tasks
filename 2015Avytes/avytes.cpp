#include <bits/stdc++.h>

using namespace std;

struct Avys
  {
  string vardas, dnr;
  int koef;
  bool taip = false;
  };

void Nuskaitymas(Avys A[], int &n, int &m, int &nr);
int Koeficentas(Avys a, Avys b, int m);
void Rikiavimas(Avys A[], int n);
void Spausdinimas(Avys A[], int n);

int main()
  {
  Avys A[20];
  int n, m, nr;
  Nuskaitymas(A, n, m, nr);
  for ( int i = 1; i <= n ; i++)
      A[i].koef =  Koeficentas(A[i],A[nr], m);

  Rikiavimas(A, n);
  Spausdinimas(A, n);
  return 0;
  }

void Nuskaitymas(Avys A[], int &n, int &m, int &nr)
  {
  int i;
  char eil[13];
  ifstream fd("duomenys.txt");
  fd >> n >> m >> nr;
  fd.ignore();
  for ( i = 1; i <= n ; i++)
    {
    fd.get(eil, 12);
    A[i].vardas = eil;
    fd >> A[i].dnr;
    if (i == nr) A[i].taip = true;
    fd.ignore();
    }
  fd.close();
  }

int Koeficentas(Avys a, Avys b, int m)
  {
  int i, k = 0;
  for(i = 0; i < m; i++)
    if (a.dnr[i] == b.dnr[i]) k++;
  return k;
  }

void Rikiavimas(Avys A[], int n)
  {
  int i, j;
  for (i = 1 ; i < n ; i++)
  {
    for (j = i + 1; j <= n; j++)
      {
        if ( A[i].koef < A[j].koef)  swap(A[i], A[j]) ;
        if (A[i].koef == A[j].koef && A[i].vardas > A[j].vardas)  swap(A[i], A[j]) ;
      }

  }
  }

void Spausdinimas(Avys A[], int n)
  {
  ofstream fr("rezultatai.txt");
  for ( int i = 1; i <= n ; i++)
  if (A[i].taip)  { fr << A[i].vardas<<endl; break;}
  for ( int i = 1; i <= n ; i++)
    if (!A[i].taip) fr <<A[i].vardas<< A[i].koef<<endl;
  fr.close();
  }


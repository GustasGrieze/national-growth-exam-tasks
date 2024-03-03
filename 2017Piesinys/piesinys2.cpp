#include <iostream>
#include <fstream>

using namespace std;

struct taskas
  {
  int x;
  int y[100];
  int r[100];
  int g[100];
  int b[100];
  };

void Nuskaitymas();
void Staciakampis(int minx, int miny, int maxx, int maxy, int r, int g, int b);
void Spausdinimas();

int n,min_x, min_y, max_x, max_y;
taskas A[1000];

int main()
  {
  Nuskaitymas();
  Spausdinimas();
  return 0;
  }

void Nuskaitymas()
  {
  int i, j, x0, y0, dx, dy, red, green, blue;
  ifstream fd("duomenys.txt");
  min_x = 100;
  min_y = 100;
  max_x = 0;
  max_y = 0;
  fd >> n;
  for (i = 0; i < 100; i++)
    {
    A[i].x = i;
    for(j = 0; j < 100; j++)
      {
      A[i].y[j] = j;
      A[i].r[j] = 255;
      A[i].g[j] = 255;
      A[i].b[j] = 255;

      }
    }
  for(i = 0; i < n ; i++)
    {
    fd >> x0 >> y0 >> dx >> dy >> red >> green >> blue;
    if (x0 < min_x) min_x = x0;
    if (y0 < min_y) min_y = y0;
    if (x0+dx > max_x) max_x = x0 + dx;
    if (y0 + dy > max_y ) max_y = y0 + dy;
    Staciakampis(x0, y0, dx, dy, red, green, blue);
    }
  fd.close();
  }

void Staciakampis(int minx, int miny, int maxx, int maxy, int r, int g, int b)
  {
  int i, j;
  for (i = minx ; i < minx + maxx ; i ++)
    {
    A[i].x = i;
    for(j = miny ; j < miny + maxy ; j++)
      {
      A[i].y[j] = j;
      A[i].r[j] = r;
      A[i].g[j] = g ;
      A[i].b[j] = b;
      }
    }
  }

void Spausdinimas()
  {
  int i, j, eile = 0;
  ofstream fr("rezultatai.txt");
  while (eile < max_x)
    {
    for( i = min_x ; i < max_x; i++)
      {
      for (j=min_y ; j < max_y; j++)
        if (j == eile ) fr << A[i].r[j] << " "<<A[i].g[j]<< " "<<A[i].b[j]<<endl;
      }
    eile++;
    }
  fr.close();
  }

#include <iostream>
#include <fstream>
using namespace std;

void Skaiciavimas();

int main(){

    Skaiciavimas();
    return 0;

}

void Skaiciavimas(){

int l1, l3, l5, litrai; //talpos ir litrai
int isl, k1, k3, k5; // islaidos ir kainos
int pri1, pri3, pri5; //pripilta
int ne1, ne3, ne5; //nepanaudota
int neispilste; // likes aliejus
int reik1, reik3, reik5;
int kaina;

ifstream fd("U1.txt");
ofstream fr("U1_rez.txt");

fd >> l1 >> l3 >> l5 >> litrai;
fd >> isl >> k1 >> k3 >> k5;

pri5 = litrai / 5;
if(pri5 > l5){
    pri5 = l5;
    ne5 = 0;
}
else{
    ne5 = l5 - pri5;
}
litrai = litrai - pri5 * 5;

pri3 = litrai / 3;
if(pri3 > l3){
    pri3 = l3;
    ne3 = 0;
}
else ne3 = l3 - pri3;
litrai = litrai - pri3*3;

if(litrai > l1){
    pri1 = l1;
    ne1 = 0;
}
else {
    pri1 = litrai;
    ne1 = l1 - pri1;
}

neispilste = litrai - pri1;

reik5 = neispilste / 5;
reik3 = neispilste % 5 / 3;
reik1 = neispilste % 5 % 3;

kaina = (pri1 + reik1) * k1 + (pri3 + reik3) * k3 + (pri5 + reik5) * k5 - isl;
fr << pri1 <<" "<< pri3 <<" "<< pri5 <<" "<<neispilste<<endl;
fr << ne1 <<" "<< ne3 <<" "<< ne5 << endl;
fr << reik1 <<" "<< reik3 <<" "<<reik5<<endl;
fr << kaina;

cout << litrai;

fr.close();
fd.close();

}

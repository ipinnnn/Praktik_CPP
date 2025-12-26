#include <iostream>
using namespace std;

int main()
{
   string kalimat_091;
   int count=0;
   cout << "=============================" << endl;
   cout << "Pogram Menentukan Huruf Vokal" << endl;
   cout << "=============================" << endl;
   cout << "Masukan Kalimat yang anda inginkan: "   ;
   cin  >> kalimat_091; 

   for (int i=0; i<kalimat_091.length(); i++)
   {
       if(kalimat_091[i]=='a'|| kalimat_091[i]=='i'|| kalimat_091[i]=='u'|| kalimat_091[i]=='e'|| kalimat_091[i]=='o')
       {
             count++;
       }
   }
   cout << "Jumlah huruf vokal pada kalimat tersebut adalah : " << count;
   
}
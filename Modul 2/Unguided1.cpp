#include <iostream> 
using namespace std; 

int main() { 
    int bilangan_091 [10]; 
    
    //data array yang akan di proses
    cout << "Data Array : " ; 
    for (int i=0; i<10; i++){ 
        cin >> bilangan_091 [i] ; 
    }
     //proses pemilihan nomor ganjil yang akan di outputkan
    cout << "Bilangan Ganjil : " ; 
    for (int i=0; i<10; i++){ 
        if (bilangan_091 [i]%2 != 0){ 
            cout << bilangan_091 [i] << " " ; 
         } 
    }       
    //proses pemilihan nomor genap yang akan di outputkan
    cout << "\nBilangan Genap : " ; 
    for (int i=0; i<10; i++){ 
        if (bilangan_091 [i]%2 == 0){ 
            cout << bilangan_091 [i] << " " ;  
        } 
    } 
    return 0; 
    
}
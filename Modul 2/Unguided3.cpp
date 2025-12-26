#include <iostream> 
using namespace std; 

int main() { 
    int a_091; 
    cout << "Masukkan jumlah elemen array yang diinginkan : "; 
    cin >> a_091; 
    
    //Input elemen array
    int arr[a_091]; 
    for (int i = 0; i < a_091; i++) { 
        cout << "Input elemen array ke-" << i+1 << ": "; 
        cin >> arr[i]; 
        } 
        //Pilih menua array
        int choose; 
        if (true) { 
            cout << endl; 
            cout << "Pilih menu yang diinginkan : " << endl; 
            cout << "1. Cari nilai maksimum" << endl; 
            cout << "2. Cari nilai minimum" << endl; 
            cout << "3. Cari nilai rata-rata" << endl; 
            cout << "Pilih Menu : "; 
            cin >> choose; 
            switch(choose) { 
                //Proses dan output nilai maksimum
                case 1: { 
                    int maks = arr[0]; 
                    for (int i = 1; i < a_091; i++) {
                    if (arr[i] > maks) { 
                        maks = arr[i]; 
                        } 
                } 
                cout << "Nilai maksimum : " << maks << endl; 
                break; 
                }
                //Proses dan output nilai minimum
                case 2: { 
                    int min = arr[0]; 
                    for (int i = 1; i < a_091; i++) { 
                    if (arr[i] < min) { 
                        min = arr[i]; 
                        } 
                } 
                cout << "Nilai minimum : " << min << endl; 
                break; 
                }
                //Proses dan output rata-rata
                 case 3: { 
                    int sum = 0; 
                    for (int i = 0; i < a_091; i++) { 
                        sum += arr[i]; 
                        } 
                        double ratarata = (double)sum / a_091; 
                        cout << "Nilai rata-rata : " << ratarata << endl;   
                        break;    
                    } 
                    //Output default
                    default: { 
                    cout << "Pilihan tidak valid" << endl;       
                    break;        
                } 
            } 
        } 
    return 0; 
}
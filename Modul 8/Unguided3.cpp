#include <iostream>
using namespace std;

int HitungAngka( const int array[], int size, int target_091) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] == target_091) {
            count++;
        }
    }
    
    return count;
}

int main() {
    const int size = 10;
    int array[size] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target_091 = 4;
    
    int count = HitungAngka(array, size, target_091);
    
    cout << "=======================================" << endl;
    cout << "========Menghitung Angka Target========" << endl;
    cout << "=======================================" << endl;
    cout << "Jumlah angka " << target_091 <<  endl; 
    cout << "Ditemukan dalam data sebanyak: " << count << endl;
    
    return 0;
}
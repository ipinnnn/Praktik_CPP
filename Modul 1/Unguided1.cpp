#include <iostream>
using namespace std;

//fungsi untuk menghitung keliling persegi
double hitungkelilingpersegi_091(double sisi) {
    return sisi * 4;
}

//fungsi untuk menghitung luas persegi
double hitungluaspersegi_091(double sisi) {
    return sisi * sisi;
}



int main() {
    double sisi;

    //memasukan panjang sisi persegi
    cout << "Masukkan panjang sisi: ";
    cin >> sisi;

    //pemanggilan fungsi
    double kelilingpersegi = hitungkelilingpersegi_091(sisi);
    double luaspersegi = hitungluaspersegi_091(sisi);

    //tampailan output
    cout << "Keiling persegi dengan sisi " << sisi << " adalah: " << kelilingpersegi << endl;
    cout << "Luas persegi dengan sisi " << sisi << " adalah: " << luaspersegi << endl;

    return 0;
}
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//contoh struct
struct menu {
string nama_091;
int harga, jumlah;

};

//contoh class
class reservasi
{
private:
    string nama_091;
    int waktu;
    int harga;

public:
    //inisialisasi objek reservasi
    reservasi(string namareservasi, int waktureservasi, int hargareservasi) {
        nama_091 = namareservasi;
        waktu = waktureservasi;
        harga = hargareservasi;
}

    //menampilkan informasi reservasi
    void tampilkanInfo() {
        cout << "Nama Pemain : " << nama_091 << endl;
        cout << "Durasi Main : " << waktu << " jam " << endl;
        cout << "Harga : Rp. " <<harga << endl << endl;
    }
};

int main() {

    //penggunaan struct
    menu minuman, makanan;

    minuman.nama_091 = "Es Kelapa Sawit";
    minuman.jumlah = 4;
    minuman.harga = 25000;

    cout << "Nama Minuman : " << minuman.nama_091 << endl   
         << "Jumlah : " << minuman.jumlah << endl 
         << "Harga : Rp." <<minuman.harga << endl << endl;

    //penggunaan class
    reservasi billiard("Stev", 10, 500000);
    reservasi vip("Jhon", 5, 250000);
    billiard.tampilkanInfo();
    vip.tampilkanInfo();
}

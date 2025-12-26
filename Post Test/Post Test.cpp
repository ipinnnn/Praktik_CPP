//Muhammad Hamzah Haifan M
//2311102091
//IF-11-C
#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string kode;
    string nama;
    int jumlah;
    double harga;
};

const int MAX_BARANG = 6;
Barang daftarBarang[MAX_BARANG];
int jumlahBarang = 0;

void tambahData() {
    if (jumlahBarang < MAX_BARANG) {
        cout << "Masukkan kode barang: ";
        cin >> daftarBarang[jumlahBarang].kode;
        cout << "Masukkan nama barang: ";
        cin >> daftarBarang[jumlahBarang].nama;
        cout << "Masukkan harga barang: ";
        cin >> daftarBarang[jumlahBarang].harga;
        cout << "Masukkan jumlah barang: ";
        cin >> daftarBarang[jumlahBarang].jumlah;
        jumlahBarang++;
        cout << "Data barang berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, kapasitas maksimum sudah tercapai." << endl;
    }
}

void hapusData() {
    string kodeHapus;
    cout << "Masukkan kode barang yang ingin dihapus: ";
    cin >> kodeHapus;
    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].kode == kodeHapus) {
            for (int j = i; j < jumlahBarang - 1; j++) {
                daftarBarang[j] = daftarBarang[j + 1];
            }
            jumlahBarang--;
            cout << "Data barang berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Data barang tidak ditemukan." << endl;
}

void updateData() {
    string kodeUpdate;
    cout << "Masukkan kode barang yang ingin diupdate: ";
    cin >> kodeUpdate;
    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].kode == kodeUpdate) {
            cout << "Masukkan harga baru: ";
            cin >> daftarBarang[i].harga;
            cout << "Masukkan jumlah baru: ";
            cin >> daftarBarang[i].jumlah;
            cout << "Data barang berhasil diupdate." << endl;
            return;
        }
    }
    cout << "Data barang tidak ditemukan." << endl;
}

void hapusDataUrutanTertentu() {
    int indexHapus;
    cout << "Masukkan indeks barang yang ingin dihapus: ";
    cin >> indexHapus;
    if (indexHapus >= 0 && indexHapus < jumlahBarang) {
        for (int i = indexHapus; i < jumlahBarang - 1; i++) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlahBarang--;
        cout << "Data barang pada indeks " << indexHapus << " berhasil dihapus." << endl;
    } else {
        cout << "Indeks barang tidak valid." << endl;
    }
}

void hapusSeluruhData() {
    jumlahBarang = 0;
    cout << "Seluruh data barang berhasil dihapus." << endl;
}

void cariData() {
    int posisi;
    cout << "Masukkan posisi data yang ingin dicari: ";
    cin >> posisi;
    if (posisi >= 0 && posisi < jumlahBarang) {
        cout << "Data pada posisi " << posisi << ":" << endl;
        cout << "Kode: " << daftarBarang[posisi].kode << ", Nama: " << daftarBarang[posisi].nama << ", Harga: " << daftarBarang[posisi].harga << ", Jumlah: " << daftarBarang[posisi].jumlah << endl;
    } else {
        cout << "Posisi data tidak valid." << endl;
    }
}

void tambahDataUrutanTertentu() {
    int posisi;
    if (jumlahBarang < MAX_BARANG) {
        cout << "Masukkan posisi data yang ingin ditambahkan: ";
        cin >> posisi;
        if (posisi >= 0 && posisi <= jumlahBarang) {
            for (int i = jumlahBarang - 1; i >= posisi; i--) {
                daftarBarang[i + 1] = daftarBarang[i];
            }
            cout << "Masukkan kode barang: ";
            cin >> daftarBarang[posisi].kode;
            cout << "Masukkan nama barang: ";
            cin >> daftarBarang[posisi].nama;
            cout << "Masukkan harga barang: ";
            cin >> daftarBarang[posisi].harga;
            cout << "Masukkan jumlah barang: ";
            cin >> daftarBarang[posisi].jumlah;
            jumlahBarang++;
            cout << "Data barang berhasil ditambahkan pada posisi " << posisi << endl;
        } else {
            cout << "Posisi data tidak valid." << endl;
        }
    } else {
        cout << "Maaf, kapasitas maksimum sudah tercapai." << endl;
    }
}

void tampilkanData() {
    cout << "Daftar Barang:" << endl;
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "Kode: " << daftarBarang[i].kode << ", Nama: " << daftarBarang[i].nama << ", Harga: " << daftarBarang[i].harga << ", Jumlah: " << daftarBarang[i].jumlah << endl;
    }
}

void menu() {
    cout << "Toko Alat Tulis Barokah" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Hapus Data Urutan Tertentu" << endl;
    cout << "5. Hapus Seluruh Data" << endl;
    cout << "6. Cari data di posisi tertentu" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Tambah Data Urutan Tertentu" << endl;
    cout << "9. Exit" << endl;
}

int main() {
    int pilihan;
    do {
        menu();
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                updateData();
                break;
            case 4:
                hapusDataUrutanTertentu();
                break;
            case 5:
                hapusSeluruhData();
                break;
            case 6:
                cariData();
                break;
            case 7:
                tampilkanData();
                break;
            case 8:
                tambahDataUrutanTertentu();
                break;
            case 9:
                cout << "Terima kasih telah menggunakan program kasir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 9);

    return 0;
}
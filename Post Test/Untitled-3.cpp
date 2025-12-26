#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MAX_BARANG = 100; // Maksimum jumlah barang yang dapat disimpan

struct Barang {
    string kode;
    string nama;
    int jumlah;
};

class Toko {
private:
    Barang barangList[MAX_BARANG];
    int barangCount;
    stack<Barang[MAX_BARANG]> undoStack;

public:
    Toko() : barangCount(0) {}

    void tambahBarang(const string& kode, const string& nama, int jumlah) {
        if (barangCount >= MAX_BARANG) {
            cout << "Kapasitas maksimal tercapai." << endl;
            return;
        }
        Barang barang = {kode, nama, jumlah};
        barangList[barangCount] = barang;
        barangCount++;
        simpanKeUndoStack();
    }

    void hapusBarang(const string& kode) {
        int index = -1;
        for (int i = 0; i < barangCount; ++i) {
            if (barangList[i].kode == kode) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < barangCount - 1; ++i) {
                barangList[i] = barangList[i + 1];
            }
            barangCount--;
            simpanKeUndoStack();
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }

    void updateKodeBarang(const string& kodeLama, const string& kodeBaru) {
        int index = -1;
        for (int i = 0; i < barangCount; ++i) {
            if (barangList[i].kode == kodeLama) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            barangList[index].kode = kodeBaru;
            simpanKeUndoStack();
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }

    void updateJumlahBarang(const string& kode, int jumlah) {
        int index = -1;
        for (int i = 0; i < barangCount; ++i) {
            if (barangList[i].kode == kode) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            barangList[index].jumlah = jumlah;
            simpanKeUndoStack();
        } else {
            cout << "Barang tidak ditemukan." << endl;
        }
    }

    void tampilkanBarang() {
        for (int i = 0; i < barangCount; ++i) {
            cout << "Kode: " << barangList[i].kode << ", Nama: " << barangList[i].nama << ", Jumlah: " << barangList[i].jumlah << endl;
        }
    }

    void hapusSeluruhData() {
        barangCount = 0;
        while (!undoStack.empty()) {
            undoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            Barang *prevData = undoStack.top();
            for (int i = 0; i < barangCount; ++i) {
                barangList[i] = prevData[i];
            }
            undoStack.pop();
        } else {
            cout << "Tidak ada data untuk di-undo." << endl;
        }
    }

private:
    void simpanKeUndoStack() {
        Barang *prevData = new Barang[MAX_BARANG];
        for (int i = 0; i < barangCount; ++i) {
            prevData[i] = barangList[i];
        }
        undoStack.push(prevData);
    }
};

void tampilkanMenu() {
    cout << "Toko Alat Tulis Atmajaya" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Kode Barang" << endl;
    cout << "4. Update Jumlah Barang" << endl;
    cout << "5. Tampilkan Data" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Undo" << endl;
    cout << "8. Exit" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Toko toko;
    int pilihan;
    string kode, nama;
    int jumlah;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline character dari buffer

        switch (pilihan) {
            case 1:
                cout << "Masukkan kode barang: ";
                getline(cin, kode);
                cout << "Masukkan nama barang: ";
                getline(cin, nama);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                toko.tambahBarang(kode, nama, jumlah);
                break;
            case 2:
                cout << "Masukkan kode barang yang akan dihapus: ";
                getline(cin, kode);
                toko.hapusBarang(kode);
                break;
            case 3:
                cout << "Masukkan kode barang yang akan diubah: ";
                getline(cin, kode);
                cout << "Masukkan kode barang baru: ";
                getline(cin, nama);
                toko.updateKodeBarang(kode, nama);
                break;
            case 4:
                cout << "Masukkan kode barang: ";
                getline(cin, kode);
                cout << "Masukkan jumlah barang baru: ";
                cin >> jumlah;
                toko.updateJumlahBarang(kode, jumlah);
                break;
            case 5:
                toko.tampilkanBarang();
                break;
            case 6:
                toko.hapusSeluruhData();
                break;
            case 7:
                toko.undo();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 8);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim_091;
    float nilai_091;
};

class HashTable {
private:
    static const int table_size = 10; // Ukuran hash table disetel ke 10 untuk contoh
    vector<Mahasiswa> table[table_size];

    int hash_func(string nim_091) {
        int sum = 0;
        for (char c : nim_091) {
            sum += int(c);
        }
        return sum % table_size;
    }

public:
    void tambah_data(Mahasiswa mahasiswa) {
        int index = hash_func(mahasiswa.nim_091);
        table[index].push_back(mahasiswa);
    }

    bool hapus_data(string nim_091) {
        int index = hash_func(nim_091);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i].nim_091 == nim_091) {
                table[index].erase(table[index].begin() + i);
                return true;
            }
        }
        return false;
    }

    Mahasiswa* cari_berdasarkan_nim(string nim_091) {
        int index = hash_func(nim_091);
        for (Mahasiswa &mahasiswa : table[index]) {
            if (mahasiswa.nim_091 == nim_091) {
                return &mahasiswa;
            }
        }
        return nullptr;
    }

    vector<Mahasiswa> cari_berdasarkan_rentang_nilai(float nilai_awal, float nilai_akhir) {
        vector<Mahasiswa> mahasiswa_ditemukan;
        for (int i = 0; i < table_size; ++i) {
            for (Mahasiswa &mahasiswa : table[i]) {
                if (mahasiswa.nilai_091 >= nilai_awal && mahasiswa.nilai_091 <= nilai_akhir) {
                    mahasiswa_ditemukan.push_back(mahasiswa);
                }
            }
        }
        return mahasiswa_ditemukan;
    }
};

// Fungsi untuk menampilkan menu
void tampilkan_menu() {
    cout << "Pilihan Menu:" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Hapus Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa Berdasarkan NIM" << endl;
    cout << "4. Cari Data Mahasiswa Berdasarkan Rentang Nilai (80-90)" << endl;
    cout << "5. Keluar" << endl;
}

int main() {
    HashTable hash_table;

    while (true) {
        tampilkan_menu();
        int pilihan;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            Mahasiswa mahasiswa;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> mahasiswa.nim_091;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> mahasiswa.nilai_091;
            hash_table.tambah_data(mahasiswa);
            cout << "Data mahasiswa telah ditambahkan." << endl;
        } else if (pilihan == 2) {
            string nim_091;
            cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
            cin >> nim_091;
            if (hash_table.hapus_data(nim_091)) {
                cout << "Data mahasiswa dengan NIM " << nim_091 << " telah dihapus." << endl;
            } else {
                cout << "Data mahasiswa dengan NIM " << nim_091 << " tidak ditemukan." << endl;
            }
        } else if (pilihan == 3) {
            string nim_091;
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim_091;
            Mahasiswa* mahasiswa = hash_table.cari_berdasarkan_nim(nim_091);
            if (mahasiswa != nullptr) {
                cout << "Data mahasiswa ditemukan:" << endl;
                cout << "NIM: " << mahasiswa->nim_091 << endl;
                cout << "Nilai: " << mahasiswa->nilai_091 << endl;
            } else {
                cout << "Data mahasiswa dengan NIM " << nim_091 << " tidak ditemukan." << endl;
            }
        } else if (pilihan == 4) {
            vector<Mahasiswa> mahasiswa_ditemukan = hash_table.cari_berdasarkan_rentang_nilai(80, 90);
            if (!mahasiswa_ditemukan.empty()) {
                cout << "Data mahasiswa dengan nilai antara 80 dan 90:" << endl;
                for (Mahasiswa &mahasiswa : mahasiswa_ditemukan) {
                    cout << "NIM: " << mahasiswa.nim_091 << endl;
                    cout << "Nilai: " << mahasiswa.nilai_091 << endl;
                }
            } else {
                cout << "Tidak ada data mahasiswa dengan nilai antara 80 dan 90." << endl;
            }
        } else if (pilihan == 5) {
            cout << "Terima kasih!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    }

    return 0;
}
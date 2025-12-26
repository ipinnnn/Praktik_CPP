#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string Nama_091;
    int Umur;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void inisialisasi() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool cek() {
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah Depan
void depan(string name, int age) {
    //Buat Node baru
    Node* baru = new Node;
    baru->Nama_091 = name;
    baru->Umur = age;
    baru->next = NULL;

    if (cek() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void belakang(string name, int age) {
    // Buat Node baru
    Node* baru = new Node;
    baru->Nama_091 = name;
    baru->Umur = age;
    baru->next = NULL;

    if (cek() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int jumlahlist() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Tambah Tengah
void tengah(string name, int age, int posisi) {
    if (posisi < 1 || posisi > jumlahlist()) {
        cout << "Tidak terjangkau!" << endl;
    }
    else if (posisi == 1) {
        cout << "Bukan di tengah." << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->Nama_091 = name;
        baru->Umur = age;

        // Tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapus() {
    Node* hapus;

    if (cek() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Belakang
void hapusbelakang() {
    Node* hapus;
    Node* bantu;

    if (cek() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Tengah
void hapustengah(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > jumlahlist()) {
        cout << "Tidak terjangkau!" << endl;
    }
    else if (posisi == 1) {
        cout << "Bukan yang tengah." << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahdepan(string name, int age) {
    if (cek() == false) {
        head->Nama_091 = name;
        head->Umur = age;
    }
    else {
        cout << "Tidak ada yang berubah!" << endl;
    }
}

// Ubah Tengah
void ubahtengah(string name, int age, int posisi) {
    Node* bantu;

    if (cek() == false) {
        if (posisi < 1 || posisi > jumlahlist()) {
            cout << "Tidak Terjangkau!" << endl;
        }
        else if (posisi == 1) {
            cout << "Bukan yang Tengah." << endl;
        }
        else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->Nama_091 = name;
            bantu->Umur = age;
        }
    }
    else {
        cout << "Kosong!" << endl;
    }
}

// Ubah Belakang
void ubahbelakang(string name, int age) {
    if (cek() == false) {
        tail->Nama_091 = name;
        tail->Umur = age;
    }
    else {
        cout << "Kosong" << endl;
    }
}

// Hapus List
void hapuslist() {
    Node* bantu, * hapus;
    bantu = head;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "Menghapus semua!" << endl;
}

// Tampilkan List
void tampillist() {
    Node* bantu;
    bantu = head;

    cout << left << setw(15) << "Nama" << right << setw(4) << "Usia" << endl; 

    if (cek() == false) {
        while (bantu != NULL) {
            cout << left << setw(15) << bantu->Nama_091 << right << setw(4) << bantu->Umur << endl; 
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "Kosong!" << endl;
    }
}

int main() {
    // Inisialisasi Linked List
    inisialisasi(); 

    // Menampilkan nama dan umur awal & menjawab poin a
    cout << "(A) Menampilkan data sesuai urutan data pertama nama dan usia user\n" << endl;
    depan("Karin", 18);
    depan("Hoshino", 18);
    depan("Akechi", 20); 
    depan("Yusuke", 19);
    depan("Michael", 18);
    depan("Jane", 20);
    depan("John", 19);
    depan("Ipin", 19);
    tampillist();

    // b. Menghapus data Akheci
    cout << "(B) Hapus data Akechi\n" << endl;
    hapustengah(6);
    tampillist();

    // c. Menambahkan data Futaba (18) diantara John dan Jane
    cout << "(C) Tambah data Futaba (18) diantara John & Jane\n" << endl;
    tengah("Futaba", 18, 3);
    tampillist();

    // d. Menambahkan data Igor diawal (20)
    cout << "(D) Tambah data Igor (20) diawal\n" << endl;
    depan("Igor", 20);
    tampillist();

    // e. Mengubah data Michael menjadi Reyn (18) 
    cout << "(E) Ubah data Michael menjadi Reyn (18)\n" << endl;
    ubahtengah("Reyn", 18, 6);
    tampillist();

    // f. Menampillkan seuruh data
    cout << "(F) Tampilan seluruh data\n" << endl;
    tampillist();
    return 0;
}
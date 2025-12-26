#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std; 

// Deklarasi Class Node untuk Double LL
class Node { 
public: 
    string Nama_Produk_091; 
    int harga;
    Node* prev;
    Node* next;
};

// Deklarasi Class DoublyLL untuk Double LL
class DoublyLinkedList { 
public: 
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
 
    // Menambahkan produk ke dalam LL di bagian atas
    void tambahproduk(string Nama_Produk_091, int harga) { 
        Node* newNode = new Node;
        newNode->Nama_Produk_091 = Nama_Produk_091; 
        newNode->harga = harga; 
        newNode->prev = nullptr; 
        newNode->next = head; 
        if (head != nullptr) {
            head->prev = newNode; 
        }
        else {
            tail = newNode; 
        }
        head = newNode; 
    }

    // Menghapus produk teratas dari LL
    void hapusproduk() { 
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    // Mengubah data produk berdasarkan nama produk
    bool ubahproduk(string Nama_Produk_Lama, string Nama_Produk_Baru, int Harga_Baru) { 
        Node* current = head;
        while (current != nullptr) { 
            if (current->Nama_Produk_091 == Nama_Produk_Lama) { 
                current->Nama_Produk_091 = Nama_Produk_Baru; 
                current->harga = Harga_Baru; 
                return true;
            }
            current = current->next;
        }
        return false; 
    }

    // Menambahkan data produk pada posisi tertentu
    void sisipposisi(string Nama_Produk_091, int harga, int posisi) { 
        if (posisi < 1) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        // Jika posisi adalah 1 maka tambahkan data produk di depan linked list
        Node* newNode = new Node;
        newNode->Nama_Produk_091 = Nama_Produk_091;
        newNode->harga = harga;
        if (posisi == 1) { 
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            else {
                tail = newNode;
            }
            head = newNode;
            return;
        }
        // Looping sampai posisi sebelum posisi yang diinginkan 
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) { 
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        // Pointer prev node setelah current menunjuk ke newNode jika node setelah current tidak nullptr
        if (current->next != nullptr) {
            current->next->prev = newNode; 
        }
        else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // Menghapus data produk pada posisi tertentu
    void hapusposisi(int posisi) { 
        if (posisi < 1 || head == nullptr) { 
            cout << "Posisi tidak ada atau list kosong" << endl;
            return;
        }
        Node* current = head;
        if (posisi == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete current;
            return;
        }
        // Looping sampai posisi yang diinginkan
        for (int i = 1; current != nullptr && i < posisi; ++i) { 
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi tidak ada" << endl;
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    // Menghapus semua data produk
    void hapussemua() { 
        Node* current = head; 
        while (current != nullptr) {
            Node* temp = current; 
            current = current->next; 
            delete temp; 
        }
        head = nullptr;
        tail = nullptr;
    }

    // Menampilkan data produk
    void tampilan() {
        Node* current = head;
        cout << "\nDaftar Produk dan harga yang tersedia :" << endl;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl; 
        while (current != nullptr) {
            cout << left << setw(20) << current->Nama_Produk_091 << current->harga << endl;  
            current = current->next;
        }
        cout << endl;
    }
};

// Deklarasi objek list dari class DoublyLL
int main() {
    DoublyLinkedList list; 
    
    list.tambahproduk("Hanasui", 30000);
    list.tambahproduk("Wardah", 50000);
    list.tambahproduk("Skintific", 100000);
    list.tambahproduk("Somethinc", 150000);
    list.tambahproduk("Originote", 60000);

    cout << "\nToko Skincare Purwokerto" << endl;
    list.tampilan();

    // Looping menu utama
    while (true) { 
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan;
        cout << "Pilih Menu: ";
        cin >> pilihan; 
        // Switch case untuk memilih menu
        switch (pilihan) { 
        // Memanggil fungsi tambah_produk
        case 1: {
            string Nama_Produk_091;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> Nama_Produk_091;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.tambahproduk(Nama_Produk_091, harga); 
            cout << "Produk berhasil ditambahkan teratas" << endl;
            break;
        }
        // Memanggil fungsi hapus_produk
        case 2: {
            list.hapusproduk(); 
            cout << "Produk teratas berhasil dihapus" << endl;
            break;
        }
        // Memanggil fungsi ubah_produk
        case 3: { 
            string Nama_Produk_Lama, Nama_Produk_Baru;
            int Harga_Baru;
            cout << "Input nama produk lama: ";
            cin >> Nama_Produk_Lama;
            cout << "Input nama produk baru: ";
            cin >> Nama_Produk_Baru;
            cout << "Input harga baru: ";
            cin >> Harga_Baru;
            bool updated = list.ubahproduk(Nama_Produk_Lama, Nama_Produk_Baru, Harga_Baru); 
            if (!updated) {
                cout << "Data produk tidak ditemukan" << endl;
            }
            else {
                cout << "Data produk berhasil diupdate" << endl;
            }
            break;
        }
        // Memanggil fungsi sisipkan_posisi_tertentu
        case 4: {
            string Nama_Produk_091;
            int harga, position;
            cout << "Input nama produk: ";
            cin >> Nama_Produk_091;
            cout << "Input harga: ";
            cin >> harga;
            cout << "Input posisi: ";
            cin >> position;
            list.sisipposisi(Nama_Produk_091, harga, position); 
            cout << "Produk berhasil ditambahkan pada posisi " << position << endl;
            break;
        }
        // Memanggil fungsi hapus_posisi_tertentu
        case 5: {
            int position;
            cout << "Input posisi yang ingin dihapus: ";
            cin >> position;
            list.hapusposisi(position); 

            break;
        }
        // Memanggil fungsi hapus_semua
        case 6: {
            list.hapussemua(); 
            break;
        }
        // Memanggil fungsi display
        case 7: {
            list.tampilan(); 
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Input Invalid" << endl; 
            break;
        }
        }
    }
    return 0;
}
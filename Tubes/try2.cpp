#include <iostream>
#include <cstring> // untuk strcpy, strcmp

using namespace std;

const int MAX_BARANG = 100;
const int MAX_QUEUE = 100;
const int MAX_NOTES = 100;
const int MAX_CHAR = 100;

// Barang structure
struct Barang {
    int id;
    char nama[MAX_CHAR];
    int jumlah;
    char lokasi[MAX_CHAR];

    Barang() : id(0), jumlah(0) {
        strcpy(nama, "");
        strcpy(lokasi, "");
    }

    Barang(int id, const char* nama, int jumlah, const char* lokasi)
        : id(id), jumlah(jumlah) {
        strcpy(this->nama, nama);
        strcpy(this->lokasi, lokasi);
    }
};

// Node class for linked list
class Node {
public:
    Barang barang;
    Node* next;

    Node(Barang barang) : barang(barang), next(nullptr) {}
};

// Linked list class to handle a list of items
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void add(Barang barang) {
        Node* newNode = new Node(barang);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool update(int id, int jumlahBaru, const char* lokasiBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->barang.id == id) {
                current->barang.jumlah = jumlahBaru;
                strcpy(current->barang.lokasi, lokasiBaru);
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool remove(int id) {
        if (head == nullptr) return false;
        if (head->barang.id == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->barang.id != id) {
            current = current->next;
        }

        if (current->next == nullptr) return false;
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->barang.id << ", Nama: " << current->barang.nama
                 << ", Jumlah: " << current->barang.jumlah << ", Lokasi: " << current->barang.lokasi << endl;
            current = current->next;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

// Hash table class
class HashTable {
private:
    LinkedList* table;
    int size;

public:
    HashTable(int size) : size(size) {
        table = new LinkedList[size];
    }

    ~HashTable() {
        delete[] table;
    }

    int hashFunction(int id) {
        return id % size;
    }

    void addBarang(Barang barang) {
        int index = hashFunction(barang.id);
        table[index].add(barang);
    }

    void displayTable() {
        for (int i = 0; i < size; ++i) {
            if (!table[i].isEmpty()) {
                cout << "Index " << i << ":" << endl;
                table[i].display();
            }
        }
    }

    bool updateBarang(int id, int jumlahBaru, const char* lokasiBaru) {
        int index = hashFunction(id);
        return table[index].update(id, jumlahBaru, lokasiBaru);
    }

    bool removeBarang(int id) {
        int index = hashFunction(id);
        return table[index].remove(id);
    }

    bool isEmpty() {
        for (int i = 0; i < size; ++i) {
            if (!table[i].isEmpty()) {
                return false;
            }
        }
        return true;
    }
};

// Queue class
class Queue {
private:
    Barang antrian[MAX_QUEUE];
    int frontIndex;
    int rearIndex;
    int size;

public:
    Queue() : frontIndex(0), rearIndex(0), size(0) {}

    void enqueue(Barang barang) {
        if (size == MAX_QUEUE) {
            cout << "Antrian penuh. Tidak bisa menambahkan barang." << endl;
        } else {
            antrian[rearIndex] = barang;
            rearIndex = (rearIndex + 1) % MAX_QUEUE;
            size++;
            cout << "Barang berhasil ditambahkan ke antrian." << endl;
        }
    }

    void dequeue() {
        if (size == 0) {
            cout << "Antrian kosong. Tidak ada barang yang dapat diproses." << endl;
        } else {
            frontIndex = (frontIndex + 1) % MAX_QUEUE;
            size--;
            cout << "Barang berhasil diproses dari antrian." << endl;
        }
    }

    Barang front() {
        if (size == 0) {
            cout << "Antrian kosong." << endl;
        }
        return antrian[frontIndex];
    }

    void tampilkanQueue() {
        if (size == 0) {
            cout << "Antrian kosong." << endl;
            return;
        }
        int tempIndex = frontIndex;
        for (int i = 0; i < size; i++) {
            Barang barang = antrian[tempIndex];
            cout << "ID: " << barang.id << ", Nama: " << barang.nama
                 << ", Jumlah: " << barang.jumlah << ", Lokasi: " << barang.lokasi << endl;
            tempIndex = (tempIndex + 1) % MAX_QUEUE;
        }
    }

    bool isEmpty() {
        return size == 0;
    }
};

// Stack class
class Stack {
private:
    Barang data[MAX_NOTES];
    int top;

public:
    Stack() : top(-1) {}

    void push(const Barang & barang) {
        if (top == MAX_NOTES - 1) {
            cout << "Gudang kedua penuh. Tidak bisa menambahkan barang." << endl;
        } else {
            data[++top] = barang;
            cout << "Barang berhasil ditambahkan ke gudang kedua." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Gudang kedua kosong. Tidak ada barang yang dapat dikeluarkan." << endl;
        } else {
            cout << "Barang yang dikeluarkan dari gudang kedua: "
                 << "ID: " << data[top].id << ", Nama: " << data[top].nama
                 << ", Jumlah: " << data[top].jumlah << ", Lokasi: " << data[top].lokasi << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Gudang kedua kosong." << endl;
        } else {
            cout << "Isi gudang kedua:" << endl;
            for (int i = top; i >= 0; --i) {
                cout << "ID: " << data[i].id << ", Nama: " << data[i].nama
                     << ", Jumlah: " << data[i].jumlah << ", Lokasi: " << data[i].lokasi << endl;
            }
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Gudang class
class Gudang {
private:
    HashTable* tabelBarang;

public:
    Gudang(int size) {
        tabelBarang = new HashTable(size);
    }

    ~Gudang() {
        delete tabelBarang;
    }

    void tambahBarang(int id, const char* nama, int jumlah, const char* lokasi) {
        Barang barang(id, nama, jumlah, lokasi);
        tabelBarang->addBarang(barang);
        cout << "Barang berhasil ditambahkan." << endl;
    }

    void tampilkanBarang() {
        if (tabelBarang->isEmpty()) {
            cout << "Gudang kosong." << endl;
        } else {
            tabelBarang->displayTable();
        }
    }

    void perbaruiBarang(int id, int jumlahBaru, const char* lokasiBaru) {
        if (!tabelBarang->updateBarang(id, jumlahBaru, lokasiBaru)) {
            cout << "Barang dengan ID ini tidak ditemukan." << endl;
        } else {
            cout << "Barang berhasil diperbarui." << endl;
        }
    }

    void hapusBarang(int id) {
        if (!tabelBarang->removeBarang(id)) {
            cout << "Barang dengan ID ini tidak ditemukan." << endl;
        } else {
            cout << "Barang berhasil dihapus." << endl;
        }
    }
};

int main() {
    Gudang gudang(MAX_BARANG);
    Stack gudangKedua;
    Queue antrian;
    int pilihan;

    // Menambahkan data dummy ke gudang utama
    gudang.tambahBarang(1, "Buku", 100, "Rak A1");
    gudang.tambahBarang(2, "Pensil", 200, "Rak B1");
    gudang.tambahBarang(3, "Penghapus", 150, "Rak C1");

    while (true) {
        cout << "\nGudang Management System" << endl;
        cout << "1. Tambah Barang ke Gudang Utama" << endl;
        cout << "2. Tampilkan Barang di Gudang Utama" << endl;
        cout << "3. Perbarui Barang di Gudang Utama" << endl;
        cout << "4. Hapus Barang dari Gudang Utama" << endl;
        cout << "5. Tambah Barang ke Antrian" << endl;
        cout << "6. Proses Barang dari Antrian" << endl;
        cout << "7. Tampilkan Barang di Antrian" << endl;
        cout << "8. Pindahkan Barang ke Gudang Kedua" << endl;
        cout << "9. Tampilkan Barang di Gudang Kedua" << endl;
        cout << "10. Keluarkan Barang dari Gudang Kedua" << endl;
        cout << "11. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 11) {
            break;
        }

        switch (pilihan) {
            case 1: {
                int id, jumlah;
                char nama[MAX_CHAR], lokasi[MAX_CHAR];
                cout << "Masukkan ID barang: ";
                cin >> id;
                cout << "Masukkan nama barang: ";
                cin.ignore();
                cin.getline(nama, MAX_CHAR);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                cout << "Masukkan lokasi barang: ";
                cin.ignore();
                cin.getline(lokasi, MAX_CHAR);
                gudang.tambahBarang(id, nama, jumlah, lokasi);
                break;
            }
            case 2: {
                gudang.tampilkanBarang();
                break;
            }
            case 3: {
                int id, jumlahBaru;
                char lokasiBaru[MAX_CHAR];
                cout << "Masukkan ID barang yang ingin diperbarui: ";
                cin >> id;
                cout << "Masukkan jumlah baru: ";
                cin >> jumlahBaru;
                cout << "Masukkan lokasi baru: ";
                cin.ignore();
                cin.getline(lokasiBaru, MAX_CHAR);
                gudang.perbaruiBarang(id, jumlahBaru, lokasiBaru);
                break;
            }
            case 4: {
                int id;
                cout << "Masukkan ID barang yang ingin dihapus: ";
                cin >> id;
                gudang.hapusBarang(id);
                break;
            }
            case 5: {
                int id, jumlah;
                char nama[MAX_CHAR], lokasi[MAX_CHAR];
                cout << "Masukkan ID barang: ";
                cin >> id;
                cout << "Masukkan nama barang: ";
                cin.ignore();
                cin.getline(nama, MAX_CHAR);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                cout << "Masukkan lokasi barang: ";
                cin.ignore();
                cin.getline(lokasi, MAX_CHAR);
                Barang barang(id, nama, jumlah, lokasi);
                antrian.enqueue(barang);
                break;
            }
            case 6: {
                if (!antrian.isEmpty()) {
                    Barang barang = antrian.front();
                    antrian.dequeue();
                    gudangKedua.push(barang);
                } else {
                    cout << "Antrian kosong." << endl;
                }
                break;
            }
            case 7: {
                antrian.tampilkanQueue();
                break;
            }
            case 8: {
                if (!antrian.isEmpty()) {
                    Barang barang = antrian.front();
                    antrian.dequeue();
                    gudangKedua.push(barang);
                } else {
                    cout << "Antrian kosong." << endl;
                }
                break;
            }
            case 9: {
                gudangKedua.display();
                break;
            }
            case 10: {
                gudangKedua.pop();
                break;
            }
            default: {
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    }

    return 0;
}
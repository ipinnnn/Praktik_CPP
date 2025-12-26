#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <stdexcept>

using namespace std;

const int MAX_NOTES = 11;

// Barang structure
struct Barang {
    int id;
    string nama;
    int jumlah;
    string lokasi;

    Barang() : id(0), nama(""), jumlah(0), lokasi("") {}
    Barang(int id, const string& nama, int jumlah, const string& lokasi)
        : id(id), nama(nama), jumlah(jumlah), lokasi(lokasi) {}
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

    bool update(int id, int jumlahBaru, string lokasiBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->barang.id == id) {
                current->barang.jumlah = jumlahBaru;
                current->barang.lokasi = lokasiBaru;
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

class Gudang {
private:
    unordered_map<int, LinkedList> tabelBarang;

public:
    void tambahBarang(int id, string nama, int jumlah, string lokasi) {
        Barang barang(id, nama, jumlah, lokasi);
        tabelBarang[id].add(barang);
        cout << "Barang berhasil ditambahkan." << endl;
    }

    void tampilkanBarang() {
        if (tabelBarang.empty()) {
            cout << "Gudang kosong." << endl;
            return;
        }
        for (auto& pair : tabelBarang) {
            cout << "Lokasi ID: " << pair.first << endl;
            pair.second.display();
        }
    }

    void perbaruiBarang(int id, int jumlahBaru, string lokasiBaru) {
        if (tabelBarang.find(id) == tabelBarang.end() || !tabelBarang[id].update(id, jumlahBaru, lokasiBaru)) {
            cout << "Barang dengan ID ini tidak ditemukan." << endl;
            return;
        }
        cout << "Barang berhasil diperbarui." << endl;
    }

    void hapusBarang(int id) {
        if (tabelBarang.find(id) == tabelBarang.end() || !tabelBarang[id].remove(id)) {
            cout << "Barang dengan ID ini tidak ditemukan." << endl;
            return;
        }
        if (tabelBarang[id].isEmpty()) {
            tabelBarang.erase(id);
        }
        cout << "Barang berhasil dihapus." << endl;
    }
};

class Note {
public:
    string text;

    Note() : text("") {}
    Note(string text) : text(text) {}
};


// Queue class to manage incoming goods
class Queue {
private:
    queue<Barang> antrian;

public:
    void enqueue(Barang barang) {
        antrian.push(barang);
        cout << "Barang berhasil ditambahkan ke antrian." << endl;
    }

    void dequeue() {
        if (antrian.empty()) {
            throw std::runtime_error("Antrian kosong. Tidak ada barang yang dapat diproses.");
        }
        antrian.pop();
        cout << "Barang berhasil diproses dari antrian." << endl;
    }

    Barang front() {
        if (antrian.empty()) {
            throw runtime_error("Antrian kosong.");
        }
        return antrian.front();
    }

    void tampilkanQueue() {
        if (antrian.empty()) {
            cout << "Antrian kosong." << endl;
            return;
        }
        queue<Barang> tempQueue = antrian;
        while (!tempQueue.empty()) {
            Barang barang = tempQueue.front();
            cout << "ID: " << barang.id << ", Nama: " << barang.nama
                 << ", Jumlah: " << barang.jumlah << ", Lokasi: " << barang.lokasi << endl;
            tempQueue.pop();
        }
    }

    bool isEmpty() {
        return antrian.empty();
    }
};


// Stack class to manage goods moved to second warehouse
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
            data[top++] = barang;
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

int main() {
    Gudang gudang;
    Stack gudangKedua;
    Queue antrian;
    Note notes[100];
    int noteCount = 0;
    int pilihan;

    // Menambahkan data dummy ke gudang utama
    gudang.tambahBarang(1, "Buku", 100, "Rak A1");
    gudang.tambahBarang(2, "Pensil", 200, "Rak B1");
    gudang.tambahBarang(3, "Penggaris", 150, "Rak C1");
    gudang.tambahBarang(4, "Penghapus", 180, "Rak D1");
    cout<<endl;
    gudang.tampilkanBarang();
    cout<<endl;

    do {
        cout << "Menu Utama:" << endl;
        cout << "1. Kelola Gudang Utama" << endl;
        cout << "2. Kelola Gudang Kedua (Stack)" << endl;
        cout << "3. Catatan" << endl;
        cout << "4. Barang Masuk (Queue)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int pilihanGudang;
                do {
                    cout << "Menu Gudang Utama:" << endl;
                    cout << "1. Tambah Barang" << endl;
                    cout << "2. Tampilkan Barang" << endl;
                    cout << "3. Perbarui Barang" << endl;
                    cout << "4. Hapus Barang" << endl;
                    cout << "0. Kembali ke Menu Utama" << endl;
                    cout << "Pilih: ";
                    cin >> pilihanGudang;

                    switch (pilihanGudang) {
                        case 1: {
                            int id, jumlah;
                            string nama, lokasi;
                            cout << "Masukkan ID barang: ";
                            cin >> id;
                            cout << "Masukkan Nama barang: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan Jumlah barang: ";
                            cin >> jumlah;
                            cout << "Masukkan Lokasi barang: ";
                            cin.ignore();
                            getline(cin, lokasi);
                            gudang.tambahBarang(id, nama, jumlah, lokasi);
                            break;
                        }
                        case 2:
                            gudang.tampilkanBarang();
                            break;
                        case 3: {
                            int id, jumlahBaru;
                            string lokasiBaru;
                            cout << "Masukkan ID barang yang ingin diperbarui: ";
                            cin >> id;
                            cout << "Masukkan Jumlah barang baru: ";
                            cin >> jumlahBaru;
                            cout << "Masukkan Lokasi barang baru: ";
                            cin.ignore();
                            getline(cin, lokasiBaru);
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
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                } while (pilihanGudang != 0);
                break;
            }
            case 2: {
                int pilihanGudangKedua;
                do {
                    cout << "Menu Gudang Kedua (Stack):" << endl;
                    cout << "1. Tambah Barang ke Gudang Kedua" << endl;
                    cout << "2. Keluarkan Barang dari Gudang Kedua" << endl;
                    cout << "3. Tampilkan Isi Gudang Kedua" << endl;
                    cout << "0. Kembali ke Menu Utama" << endl;
                    cout << "Pilih: ";
                    cin >> pilihanGudangKedua;

                    switch (pilihanGudangKedua) {
                        case 1: {
                            int id, jumlah;
                            string nama, lokasi;
                            cout << "Masukkan ID barang: ";
                            cin >> id;
                            cout << "Masukkan Nama barang: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan Jumlah barang: ";
                            cin >> jumlah;
                            cout << "Masukkan Lokasi barang: ";
                            cin.ignore();
                            getline(cin, lokasi);
                            Barang barang(id, nama, jumlah, lokasi);
                            gudangKedua.push(barang);
                            break;
                        }
                        case 2:
                            gudangKedua.pop();
                            break;
                        case 3:
                            gudangKedua.display();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                } while (pilihanGudangKedua != 0);
                break;
            }
            case 3: {
                int pilihanCatatan;
                do {
                    cout << "Menu Catatan:" << endl;
                    cout << "1. Tambah Catatan" << endl;
                    cout << "2. Tampilkan Catatan" << endl;
                    cout << "3. Perbarui Catatan" << endl;
                    cout << "4. Hapus Catatan" << endl;
                    cout << "0. Kembali ke Menu Utama" << endl;
                    cout << "Pilih: ";
                    cin >> pilihanCatatan;

                    switch (pilihanCatatan) {
                        case 1: {
                            if (noteCount < 100) {
                                string text;
                                cout << "Masukkan teks catatan: ";
                                cin.ignore();
                                getline(cin, text);
                                notes[noteCount++] = Note(text);
                                cout << "Catatan berhasil ditambahkan." << endl;
                            } else {
                                cout << "Catatan penuh. Tidak bisa menambah catatan baru." << endl;
                            }
                            break;
                        }
                        case 2:
                            if (noteCount == 0) {
                                cout << "Tidak ada catatan." << endl;
                            } else {
                                for (int i = 0; i < noteCount; ++i) {
                                    cout << "Catatan " << i + 1 << ": " << notes[i].text << endl;
                                }
                            }
                            break;
                        case 3: {
                            int index;
                            string text;
                            cout << "Masukkan nomor catatan yang ingin diperbarui: ";
                            cin >> index;
                            if (index < 1 || index > noteCount) {
                                cout << "Nomor catatan tidak valid." << endl;
                            } else {
                                cout << "Masukkan teks catatan baru: ";
                                cin.ignore();
                                getline(cin, text);
                                notes[index - 1].text = text;
                                cout << "Catatan berhasil diperbarui." << endl;
                            }
                            break;
                        }
                        case 4: {
                            int index;
                            cout << "Masukkan nomor catatan yang ingin dihapus: ";
                            cin >> index;
                            if (index < 1 || index > noteCount) {
                                cout << "Nomor catatan tidak valid." << endl;
                            } else {
                                for (int i = index - 1; i < noteCount - 1; ++i) {
                                    notes[i] = notes[i + 1];
                                }
                                --noteCount;
                                cout << "Catatan berhasil dihapus." << endl;
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                } while (pilihanCatatan != 0);
                break;
            }
            case 4: {
                int pilihanQueue;
                do {
                    cout << "Menu Barang Masuk (Queue):" << endl;
                    cout << "1. Tambah Barang ke Antrian" << endl;
                    cout << "2. Proses Barang dari Antrian ke Gudang" << endl;
                    cout << "3. Tampilkan Antrian Barang Masuk" << endl;
                    cout << "0. Kembali ke Menu Utama" << endl;
                    cout << "Pilih: ";
                    cin >> pilihanQueue;

                    switch (pilihanQueue) {
                        case 1: {
                            int id, jumlah;
                            string nama, lokasi;
                            cout << "Masukkan ID barang: ";
                            cin >> id;
                            cout << "Masukkan Nama barang: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan Jumlah barang: ";
                            cin >> jumlah;
                            cout << "Masukkan Lokasi barang: ";
                            cin.ignore();
                            getline(cin, lokasi);
                            Barang barang(id, nama, jumlah, lokasi);
                            antrian.enqueue(barang);
                            break;
                        }
                        case 2: {
                            try {
                                Barang barang = antrian.front();
                                gudang.tambahBarang(barang.id, barang.nama, barang.jumlah, barang.lokasi);
                                antrian.dequeue();
                            } catch (runtime_error& e) {
                                cout << e.what() << endl;
                            }
                            break;
                        }
                        case 3:
                            antrian.tampilkanQueue();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                            break;
                    }
                } while (pilihanQueue != 0);
                break;
            }
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
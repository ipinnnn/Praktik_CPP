#include <iostream>
using namespace std;

//simpul untuk node dalam linked list
struct Mahasiswa {
    string nama_091;
    string nim_091;
    Mahasiswa* next_091;
};

//kelas queue yang menggunakan linked list
class Queue {
private:
    //pointer ke depan antrian
    Mahasiswa* front; 
    //pointer ke belakang antrian
    Mahasiswa* back;  

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    //fungsi untuk mengecek apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    //fungsi untuk menambahkan data ke antrian
    void enqueue(string nama_091_, string nim_091_) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama_091 = nama_091_;
        newNode->nim_091 = nim_091_;
        newNode->next_091 = nullptr;

        //jika antrian kosong, node baru menjadi front dan back
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            //jika antrian tidak kosong, tambahkan node baru ke belakang dan update back
            back->next_091 = newNode;
            back = newNode;
        }
        cout << "Data berhasil dimasukkan ke dalam antrian" << endl;
    }

    //untuk menghapus data dari antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            //jika antrian tidak kosong, hapus node pertama dan update front
            Mahasiswa* temp = front;
            front = front->next_091;
            delete temp;
            cout << "Data berhasil dihapus dari antrian" << endl;
        }
    }

    //untuk menghitung jumlah data dalam antrian
    int countQueue() {
        int count = 0;
        Mahasiswa* temp = front;
        while (temp != nullptr) {
            count++;
            temp = temp->next_091;
        }
        return count;
    }

    //untuk menghapus semua data dari antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Data berhasil di-reset" << endl;
    }

    //untuk menampilkan data dalam antrian
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian Mahasiswa: " << endl;
            Mahasiswa* temp = front;
            int pos = 1;
            while (temp != nullptr) {
                cout << pos << ". Nama: " << temp->nama_091 << " || NIM: " << temp->nim_091 << endl;
                temp = temp->next_091;
                pos++;
            }
        }
    }
};

int main() {
    Queue queue;
    int choice;

    do {
        cout << "=== Menu Antrian Mahasiswa Telkom ===" << endl;
        cout << "1. Masukkan data" << endl;
        cout << "2. Hapus satu data" << endl;
        cout << "3. Reset data" << endl;
        cout << "4. Tampil data" << endl;
        cout << "5. Keluar" << endl;
        cout << "=====================================\n" << endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string nama, nim;
                cout << "Masukkan Nama Mahasiswa : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa  : ";
                cin >> nim;
                queue.enqueue(nama, nim);
                break;
            }
            case 2: {
                if (queue.isEmpty()) {
                    cout << "Antrian kosong" << endl;
                } else {
                    queue.dequeue ();
                }
                break;
            }
            case 3: {
                if (queue.isEmpty()) {
                    cout << "Antrian kosong" << endl;
                } else {
                    queue.clearQueue();
                }
                break;
            }
            case 4: {
                queue.viewQueue();
                break;
            }
            case 5: {
                cout << "Terima kasih telah menggunakan layanan kami ;)" << endl;
                break;
            }
            default: {
                cout << "Pilihan yang Anda masukkan tidak valid" << endl;
                break;
            }
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}
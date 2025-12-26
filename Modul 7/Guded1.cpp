#include <iostream>
using namespace std;

//mengecek antrian apakah sudah penuh
const int maksimalAntrian = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull(){
    if (back == maksimalAntrian){
        return true;
    } else {
        return false;
    }
}

//mengecek antrian apakah masih kosong
bool isEmpty(){
    if(back == 0){
        return true;
    } else {
        return false;
    }
}

//menambah antrian
void tambahData(string nama){
    if (isFull ()){
        cout<<"Antrian sudah penuh."<<endl;
    } else {
        if (isEmpty ()){
            queueTeller[0] = nama;
            front++;
            back++;
        } else{
            queueTeller[back] = nama;
            back++;
        }
    }
}

//mengurangi antrian
void kurangAntrian (){
    if (isEmpty ()){
        cout<<"Antrian kosong."<<endl;
    } else {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back --;
    }
}

//menghitung banyak antrian
int count () {
    return back;
}

//menghapus seluruh antrian
void clearQueue (){
    if (isEmpty ()){
        cout<<"Antrian kosong"<<endl;
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

//melihat antrian
void viewQueue (){
    cout<<"Data antrian: "<<endl;
    for (int i = 0; i < maksimalAntrian; i++){
        if (queueTeller[i] !=""){
            cout<<i+1<<"."<<queueTeller[i]<<endl;
        }else {
            cout<<i+1<<"."<<"(kosong)"<<endl;
        }
    }
}

//main fungsi
int main (){
    tambahData("Alya");
    tambahData("Kiki");
    tambahData("Artika");
    viewQueue();

    //mengurangi antrian
    kurangAntrian();
    viewQueue();

    //menghapus seluruh antrian
    clearQueue();
    viewQueue();
}
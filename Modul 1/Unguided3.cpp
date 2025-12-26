#include <iostream>
#include <map>

using namespace std;

int main() {
    //map untuk menyimpan data nama dan umur
    map<string, int> kda_091;

    //masukkan data ke dalam map
    kda_091["Lancelot"] = 5;
    kda_091["Khufra"] = 12;
    kda_091["Claude"] = 8;

    //menampilkan data dari map
    cout << "Kill Lancelot: " << kda_091["Lancelot"] << endl;
    cout << "Death Khufra: " << kda_091["Khufra"] << endl;
    cout << "Assist Claude: " << kda_091["Claude"] << endl;

    return 0;
}
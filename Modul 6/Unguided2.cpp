#include <iostream>
#include <stack>
#include <string>
using namespace std;

//membalikkan kalimat menggunakan stack
string reverseSentence_091(string sentence) {
    stack<char> charStack_091;
    string reversedSentence_091 = "";
    //push setiap karakter ke dalam stack
    for (char c : sentence) {
        charStack_091.push(c);
    }
    //pop setiap karakter dari stack untuk mendapatkan kalimat terbalik
    while (!charStack_091.empty()) {
        reversedSentence_091 += charStack_091.top();
        charStack_091.pop();
    }
    return reversedSentence_091;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    string hasilPembalikan = reverseSentence_091(kalimat);
    cout << "Hasil pembalikan: " << hasilPembalikan << endl;
    
    return 0;
}
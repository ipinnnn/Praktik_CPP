#include <iostream>
#include <string>
using namespace std;

//menghapus karakter non-alfabet dari string
string removeNonAlphanumeric(string str) {
    string result = "";
    //ubah huruf menjadi lowercase
    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += tolower(c); 
        }
    }
    return result;
}

//menentukan apakah string adalah palindrom atau tidak
bool isPalindrome(string str) {
    int left_091 = 0;
    int right = str.length() - 1;
    while (left_091 < right) {
        //lewati karakter non-alfabet di kiri
        while (left_091 < right && !isalpha(str[left_091])) {
            left_091++;
        }
        //lewati karakter non-alfabet di kanan
        while (left_091 < right && !isalpha(str[right])) {
            right--;
        }
        //periksa apakah karakter di kiri sama dengan karakter di kanan
        if (tolower(str[left_091]) != tolower(str[right])) {
            return false;
        }
        left_091++;
        right--;
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    string cleanedString = removeNonAlphanumeric(kalimat);
    
    if (isPalindrome(cleanedString)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
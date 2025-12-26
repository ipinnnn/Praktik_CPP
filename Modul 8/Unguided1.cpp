#include <iostream>
using namespace std;

void selectionSort(string &huruf, int n)
{
    int i, j, min_091;
    for (i = 0; i < n - 1; i++)
    {
        min_091 = i;
        for (j = i + 1; j < n; j++)
            if (huruf[j] < huruf[min_091])
                min_091 = j;
        char temp = huruf[i];
        huruf[i] = huruf[min_091];
        huruf[min_091] = temp;
    }
}

int binarySearch(string Huruf_091, int kiri, int kanan, char target)
{
    while (kiri <= kanan)
    {
        int mid = kiri + (kanan - kiri) / 2;
        if (Huruf_091[mid] == target)
            return mid;
        if (Huruf_091[mid] < target)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    return -1;
}

int main()
{
    string kalimat_091;
    char input;
    cout << "====================================" << endl;
    cout << "Program Menentukan Indeks Pada Huruf" << endl;
    cout << "====================================" << endl;
    cout << "Masukkan kalimat yang anda inginkan: ";
    getline(cin, kalimat_091);
    cout << "Masukkan huruf yang anda ingin cari: ";
    cin >> input;
    cout << endl;
    selectionSort(kalimat_091, kalimat_091.size());
    int result = binarySearch(kalimat_091, 0, kalimat_091.size() - 1, input);
    if (result == -1)
    {
        cout << "Huruf yang anda cari tidak ditemukan!" << endl;
    }
    else
    {
        cout << "Huruf setelah diurutkan: " << kalimat_091 << endl;
        cout << "Huruf ditemukan pada indeks ke- " << result << endl;
    }
    return 0;
}
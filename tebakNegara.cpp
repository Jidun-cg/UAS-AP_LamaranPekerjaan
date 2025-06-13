#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include "NationList.h"

using namespace std;

// Fungsi ubah string jadi uppercase
string toUpperCase(const string& input) {
    string hasil = input;
    for (char& c : hasil) {
        c = toupper(c);
    }
    return hasil;
}

// Fungsi menyembunyikan huruf 
string sembunyikanHuruf(const string& negara) {
    string hasil = negara;
    vector<int> hurufIndex;

    for (int i = 0; i < hasil.size(); ++i) {
        if (hasil[i] != ' ')
            hurufIndex.push_back(i);
    }

    int totalHuruf = hurufIndex.size();
    int jumlahDisembunyikan = totalHuruf / 2;

    random_shuffle(hurufIndex.begin(), hurufIndex.end());

    for (int i = 0; i < jumlahDisembunyikan; ++i) {
        hasil[hurufIndex[i]] = '_';
    }

    return hasil;
}


int main() {
    srand(time(0));
    int skor = 0;
    char ulang;

    do {
        int acak = rand() % daftarNegara.size();
        string negara = daftarNegara[acak];
        string clue = sembunyikanHuruf(negara);

        cout << "Tebak negara: " << clue << endl;
        cout << "Negara apakah yang dimaksud? ";
        string jawaban;
        getline(cin >> ws, jawaban);  // ws untuk menangkap whitespace

        if (toUpperCase(jawaban) == toUpperCase(negara)) {
            cout << "Selamat! Anda benar." << endl;
            skor++;
        } else {
            cout << "Maaf, Jawaban Anda salah. Jawaban benar: " << negara << endl;
        }

        cout << "Skor Anda: " << skor << endl;
        cout << "Ingin bermain lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Game Selesai :D" << endl;
    return 0;
}

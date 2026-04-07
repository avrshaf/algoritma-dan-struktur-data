#include <iostream>
#define max 5

using namespace std;

struct Stack {
    int atas;
    int data[max];
} Tumpuk;

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh() {
    if (Tumpuk.atas == max - 1)
        return 1;
    else
        return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack\n";
    }
    else {
        cout << "Tumpukan Penuh\n";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    }
    else {
        cout << " Data Kosong\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << "\n";
        }
    }
    else {
        cout << "Tumpukan Kosong\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !\n";
}

int main() {
    Tumpuk.atas = -1;

    input(10);
    input(20);
    input(30);
    cout << endl;

    tampil();
    cout << endl;

    hapus();
    cout << endl;

    tampil();
    cout << endl;

    bersih();

    return 0;
}

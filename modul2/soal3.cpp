#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define n 10

using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();

int PIL, F, R; 
char HURUF;
char Q[n];

int main () {
    Inisialisasi();
    do {
        cout<<"QUEUE"<<endl;
        cout<<"==============="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. QUIT"<<endl;
        cout<<"PILIHAN : "; 
        cin>>PIL;

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                cout<<"TERIMA KASIH"<<endl;
                break;
            default:
                cout<<"Pilihan tidak valid, silakan coba lagi!"<<endl;
                break;
        }
        
        if (PIL != 4) {
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");
        }
        
    } while (PIL != 4);
    
    return 0;
}

void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue Penuh!" << endl;
    } else {
        cout << "Masukkan satu huruf: ";
        cin >> HURUF;
        
        if (F == -1 && R == -1) {
            F = 0;
            R = 0;
        } else {
            R++;
        }
        Q[R] = HURUF;
        cout << "Data '" << HURUF << "' berhasil masuk antrian." << endl;
    }
}

void DELETE() {
    if (F == -1 && R == -1) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Data '" << Q[F] << "' berhasil keluar dari antrian." << endl;
        
        if (F == R) {
            F = -1;
            R = -1;
        } else {
            for (int i = F; i < R; i++) {
                Q[i] = Q[i + 1];
            }
            R--;
        }
    }
}

void CETAKLAYAR() {
    if (F == -1 && R == -1) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Isi Antrian saat ini: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}

#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
} TNode;

TNode *head, *tail;

int pil, menu;
char pilihan[2];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

int hitungNodeH();
int hitungNodeHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();

void hapusDepanH();
void hapusDepanHT();

void tampilkanH();
void tampilkanHT();

void hapusBelakangH();
void hapusBelakangHT();

void clearH();
void clearHT();

void hapusTargetH();
void hapusTargetHT();

int main() {
menu:
    cout << "Double Linked List Non Circular (DLLNC) " << endl;
    cout << "======================================= " << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");
    
    cin.ignore(); 

    if (menu == 1) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "==============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "8. Hapus Target" << endl; 
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            cin.ignore();

            switch (pil) {
                case 1: tambahDepanH(); break;
                case 2: tambahBelakangH(); break;
                case 3: tampilkanH(); break;
                case 4: hapusDepanH(); break;
                case 5: hapusBelakangH(); break;
                case 6: clearH(); break;
                case 7: system("cls"); goto menu;
                case 8: hapusTargetH(); break;
                default: cout << "Pilihan tidak ada!" << endl;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil != 7);
    } else if (menu == 2) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "=======================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "8. Hapus Target" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            cin.ignore();

            switch (pil) {
                case 1: tambahDepanHT(); break;
                case 2: tambahBelakangHT(); break;
                case 3: tampilkanHT(); break;
                case 4: hapusDepanHT(); break;
                case 5: hapusBelakangHT(); break;
                case 6: clearHT(); break;
                case 7: system("cls"); goto menu;
                case 8: hapusTargetHT(); break;
                default: cout << "Pilihan tidak ada!" << endl;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil != 7);
    } else if (menu == 3) {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Aurora Shafa Salsabila (2510817220010)." << endl;
    } else {
        cout << "Pilihan salah!" << endl;
        getch();
        system("cls");
        goto menu;
    }
    return 0;
}

void initH() { head = NULL; }
void initHT() { head = NULL; tail = NULL; }
int isEmptyH() { return (head == NULL) ? 1 : 0; }
int isEmptyHT() { return (tail == NULL) ? 1 : 0; }

int hitungNodeH() {
    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL) { count++; bantu = bantu->next; }
    return count;
}

int hitungNodeHT() {
    return hitungNodeH(); 
}

void tambahDepanH() {
    string arrData[100];
    int jumlah = 0;
    char pemisah;
    cout << "Masukkan data: ";
    do {
        cin >> arrData[jumlah++];
        pemisah = cin.get();
    } while (pemisah != '\n');

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arrData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru; 
        }
    }
    cout << "Berhasil menambah " << jumlah << " data di depan.";
}

void tambahDepanHT() {
    string arrData[100];
    int jumlah = 0;
    char pemisah;
    cout << "Masukkan data: ";
    do {
        cin >> arrData[jumlah++];
        pemisah = cin.get();
    } while (pemisah != '\n');

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arrData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Berhasil menambah " << jumlah << " data di depan.";
}

void tambahBelakangH() {
    string arrData[100];
    int jumlah = 0;
    char pemisah;
    cout << "Masukkan data: ";
    do {
        cin >> arrData[jumlah++];
        pemisah = cin.get();
    } while (pemisah != '\n');

    for (int i = 0; i < jumlah; i++) {
        TNode *baru = new TNode;
        baru->data = arrData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL) { bantu = bantu->next; }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Berhasil menambah " << jumlah << " data di belakang.";
}

void tambahBelakangHT() {
    string arrData[100];
    int jumlah = 0;
    char pemisah;
    cout << "Masukkan data: ";
    do {
        cin >> arrData[jumlah++];
        pemisah = cin.get();
    } while (pemisah != '\n');

    for (int i = 0; i < jumlah; i++) {
        TNode *baru = new TNode;
        baru->data = arrData[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (isEmptyHT() == 1) {
            head = tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Berhasil menambah " << jumlah << " data di belakang.";
}

void tampilkanH() {
    TNode *bantu = head;
    if (isEmptyH() == 0) {
        while (bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void tampilkanHT() {
    TNode *bantu = head;
    if (isEmptyHT() == 0) {
        while (bantu != NULL) { 
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List";
}

void hapusDepanH() {
    if (isEmptyH() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else { initH(); }
        delete hapus;
        cout << "Data \"" << data << "\" di depan berhasil dihapus.";
    } else cout << "List Kosong";
}

void hapusDepanHT() {
    if (isEmptyHT() == 0) {
        TNode *hapus = head;
        string data = hapus->data;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else { initHT(); }
        delete hapus;
        cout << "Data \"" << data << "\" di depan berhasil dihapus.";
    } else cout << "List Kosong";
}

void hapusBelakangH() {
    if (isEmptyH() == 0) {
        int n;
        cout << "Hapus node ke berapa dari belakang? : ";
        cin >> n;

        int total = hitungNodeH();
        n = n % total;
        if (n == 0) n = total; 

        TNode *bantu = head;
        while (bantu->next != NULL) { bantu = bantu->next; }

        for (int i = 1; i < n; i++) {
            bantu = bantu->prev;
        }

        string data = bantu->data;

        if (bantu == head && bantu->next == NULL) {
            initH();
        } else if (bantu == head) {
            head = head->next;
            head->prev = NULL;
        } else if (bantu->next == NULL) { 
            bantu->prev->next = NULL;
        } else { 
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
        }
        delete bantu;
        cout << "Data \"" << data << "\" ,posisi ke-" << n << " dari belakang, berhasil dihapus.";
    } else cout << "List Kosong";
}

void hapusBelakangHT() {
    if (isEmptyHT() == 0) {
        int n;
        cout << "Hapus node ke berapa dari belakang? : ";
        cin >> n;

        int total = hitungNodeHT();
        n = n % total;
        if (n == 0) n = total;

        TNode *bantu = tail;
        for (int i = 1; i < n; i++) {
            bantu = bantu->prev;
        }

        string data = bantu->data;

        if (bantu == head && bantu == tail) {
            initHT();
        } else if (bantu == head) {
            head = head->next;
            head->prev = NULL;
        } else if (bantu == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            bantu->prev->next = bantu->next;
            bantu->next->prev = bantu->prev;
        }
        delete bantu;
        cout << "Data \"" << data << "\" ,posisi ke-" << n << " dari belakang, berhasil dihapus.";
    } else cout << "List Kosong";
}

void clearH() {
    if (isEmptyH() == 0) {
        int urutan = 1;
        while (head != NULL) {
            TNode *hapus;
            if (urutan % 2 != 0) {
                hapus = head;
                cout << "Penghapusan " << urutan << " , Hapus Depan  : " << hapus->data << endl;
                
                if (head->next == NULL) { initH(); }
                else {
                    head = head->next;
                    head->prev = NULL;
                }
            } else {
                hapus = head;
                while (hapus->next != NULL) { hapus = hapus->next; }
                cout << "Penghapusan " << urutan << " , Hapus Belakang : " << hapus->data << endl;

                if (hapus == head) { initH(); }
                else {
                    hapus->prev->next = NULL;
                }
            }
            delete hapus;
            urutan++;
        }
        cout << "\nSeluruh data telah bersih.";
    } else cout << "List Kosong";
}

void clearHT() {
    if (isEmptyHT() == 0) {
        int urutan = 1;
        while (head != NULL) {
            TNode *hapus;
            if (urutan % 2 != 0) {
                hapus = head;
                cout << "Penghapusan " << urutan << " , Hapus Depan  : " << hapus->data << endl;
                
                if (head == tail) { initHT(); }
                else {
                    head = head->next;
                    head->prev = NULL;
                }
            } else {
                hapus = tail;
                cout << "Penghapusan " << urutan << " , Hapus Belakang : " << hapus->data << endl;

                if (head == tail) { initHT(); }
                else {
                    tail = tail->prev;
                    tail->next = NULL;
                }
            }
            delete hapus;
            urutan++;
        }
        cout << "\nSeluruh data telah bersih.";
    } else cout << "List Kosong";
}

void hapusTargetH() {
    if (isEmptyH() == 0) {
        string target;
        cout << "Masukkan data target yang ingin dihapus: ";
        cin >> target;

        TNode *bantu = head;
        bool ketemu = false;

        while (bantu != NULL) {
            if (bantu->data == target) {
                ketemu = true;
                TNode *hapus = bantu;
                bantu = bantu->next; 

                if (hapus == head && hapus->next == NULL) {
                    initH();
                } else if (hapus == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (hapus->next == NULL) { 
                    hapus->prev->next = NULL;
                } else { 
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
                delete hapus;
            } else {
                bantu = bantu->next;
            }
        }
        if (ketemu) cout << "Semua data \"" << target << "\" berhasil dihapus.";
        else cout << "Data target tidak ditemukan.";
    } else cout << "List Kosong";
}

void hapusTargetHT() {
    if (isEmptyHT() == 0) {
        string target;
        cout << "Masukkan data target yang ingin dihapus: ";
        cin >> target;

        TNode *bantu = head;
        bool ketemu = false;

        while (bantu != NULL) {
            if (bantu->data == target) {
                ketemu = true;
                TNode *hapus = bantu;
                bantu = bantu->next;

                if (hapus == head && hapus == tail) {
                    initHT();
                } else if (hapus == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (hapus == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                }
                delete hapus;
            } else {
                bantu = bantu->next;
            }
        }
        if (ketemu) cout << "Semua data \"" << target << "\" berhasil dihapus.";
        else cout << "Data target tidak ditemukan.";
    } else cout << "List Kosong";
}
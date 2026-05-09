#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan[2];
string dataBaru, dataHapus;

void init();
int isEmpty();
int hitungNode(); 

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main() {
    do {
        cout << "Single Linked List Circular (SLLC)               " << endl;
        cout << "==================================               " << endl;
        cout << "1. Tambah Depan                                  " << endl;
        cout << "2. Tambah Belakang                               " << endl;
        cout << "3. Hapus Depan                                   " << endl;
        cout << "4. Hapus Belakang                                " << endl;
        cout << "5. Tampilkan Data                                " << endl;
        cout << "6. Hapus Semua Elemen                            " << endl;
        cout << "7. Cari Data                                     " << endl;
        cout << "8. Hapus Setiap Data Tertentu                    " << endl;
        cout << "9. Sisipkan Node/Data Baru Sebelum Data Tertentu " << endl;
        cout << "10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout << "11. Quit                                         " << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        pil = atoi(pilihan);
        
        cin.ignore(); 

        switch (pil) {
            case 1: tambahDepan(); break;
            case 2: tambahBelakang(); break;
            case 3: hapusDepan(); break;
            case 4: hapusBelakang(); break;
            case 5: tampilkan(); break;
            case 6: reset(); break;
            case 7: cariData(); break;
            case 8: hapusData(); break;
            case 9: sisipkanSebelum(); break;
            case 10: sisipkanSetelah(); break;
            case 11:
                cout << "TERIMA KASIH" << endl;
                cout << "Program was made by Aurora Shafa Salsabila" << endl;
                break;
            default:
                cout << "\nPilihan tidak ada!" << endl;
        }

        if (pil != 11) {
            cout << "\nPress any key to continue!" << endl;
            getch();
            system("cls");
        }

    } while (pil < 11);
    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    if (head == NULL) return 1;
    else return 0;
}

int hitungNode() {
    if (isEmpty() == 1) return 0;
    
    int jumlah = 0;
    TNode *bantu = head;
    do {
        jumlah++;
        bantu = bantu->next;
    } while (bantu != head);
    
    return jumlah;
}

void tambahDepan() {
    string arrData[100]; 
    int jumlahInput = 0;
    char pemisah;

    cout << "Masukkan data : ";
    
    do {
        cin >> arrData[jumlahInput];
        jumlahInput++;
        pemisah = cin.get(); 
    } while (pemisah != '\n');

    for (int i = jumlahInput - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arrData[i];
        baru->next = baru;

        if (isEmpty() == 1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan" << endl;
}

void tambahBelakang() {
    cout << "Masukkan data : ";
    TNode *baru = new TNode;
    cin >> dataBaru;
    baru->data = dataBaru;
    baru->next = baru;

    if (isEmpty() == 1) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data \"" << dataBaru << "\" berhasil dimasukkan di belakang" << endl;
}

void hapusDepan() {
    if (isEmpty() == 0) {
        int n;
        cout << "Masukkan node ke-N yang ingin dihapus : ";
        cin >> n;

        int totalNode = hitungNode();

        if (n > totalNode) {
            cout << n << " lebih besar dari jumlah node, TAIL dihapus" << endl;
            TNode *hapus = tail;
            if (head != tail) {
                TNode *bantu = head;
                while (bantu->next != tail) {
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = head;
            } else {
                init();
            }
            cout << "Data \"" << hapus->data << "\" berhasil dihapus" << endl;
            delete hapus;
        } 
        else if (n == 1) {
            TNode *hapus = head;
            if (head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            cout << "Data \"" << hapus->data << "\" berhasil dihapus" << endl;
            delete hapus;
        } 
        else {
            TNode *bantu = head;
            TNode *sebelum = NULL;
            
            for (int i = 1; i < n; i++) {
                sebelum = bantu;
                bantu = bantu->next;
            }
            
            sebelum->next = bantu->next;
            if (bantu == tail) {
                tail = sebelum; 
            }
            cout << "Data \"" << bantu->data << "\" berhasil dihapus" << endl;
            delete bantu;
        }
    } else cout << "Data tidak ada pada Linked List" << endl;
}

void hapusBelakang() {
    if (isEmpty() == 0) {
        int n;
        cout << "Masukkan node ke-N yang ingin dihapus : ";
        cin >> n;

        int totalNode = hitungNode();

        if (n > totalNode) {
            cout << n << " lebih besar dari jumlah node, HEAD dihapus" << endl;
            TNode *hapus = head;
            if (head != tail) {
                head = head->next;
                tail->next = head;
            } else {
                init();
            }
            cout << "Data \"" << hapus->data << "\" berhasil dihapus" << endl;
            delete hapus;
        } 
        else {
            int posisiDariDepan = totalNode - n + 1;

            if (posisiDariDepan == 1) {
                TNode *hapus = head;
                if (head != tail) {
                    head = head->next;
                    tail->next = head;
                } else {
                    init();
                }
                cout << "Data \"" << hapus->data << "\" berhasil dihapus" << endl;
                delete hapus;
            } 
            else {
                TNode *bantu = head;
                TNode *sebelum = NULL;
                
                for (int i = 1; i < posisiDariDepan; i++) {
                    sebelum = bantu;
                    bantu = bantu->next;
                }
                
                sebelum->next = bantu->next;
                if (bantu == tail) {
                    tail = sebelum;
                }
                cout << "Data \"" << bantu->data << "\" berhasil dihapus" << endl;
                delete bantu;
            }
        }
    } else cout << "Data tidak ada pada Linked List" << endl;
}

void tampilkan() {
    if (isEmpty() == 0) {
        TNode *bantu = head;
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else cout << "Data tidak ada pada Linked List" << endl;
}

void reset() {
    if (isEmpty() == 0) {
        int nomor = 1; 
        
        while (head != NULL) {
            TNode *hapus = head;
            
            cout << "Menghapus node ke-" << nomor << " , isi: " << hapus->data << endl;
            
            if (head == tail) { // Kalau sisa 1 node
                head = NULL;
                tail = NULL;
            } else {
                head = head->next;
                tail->next = head;
            }
            delete hapus;
            nomor++;
        }
        cout << "Semua elemen pada Linked List sudah bersih" << endl;
    } else cout << "Data tidak ada pada Linked List" << endl;
}

void cariData() {
    if (isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dicari : ";
        cin >> cari;

        TNode *bantu = head, *bantuTampilkan;
        bool apaDitemukan = false;

        do {
            if (cari == bantu->data) {
                cout << "Setiap data yang berada di dalam tanda kurung siku ([...]) adalah data yang anda cari" << endl;
                cout << "Linked List : ";
                bantuTampilkan = head;

                do {
                    if (cari == bantuTampilkan->data)
                        cout << "[" << bantuTampilkan->data << "] ";
                    else
                        cout << bantuTampilkan->data << ' ';
                    bantuTampilkan = bantuTampilkan->next;
                } while (bantuTampilkan != head);

                apaDitemukan = true;
                cout << endl;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan == false)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List" << endl;
    } else cout << "Data tidak ada pada Linked List" << endl;
}

void hapusData() {
    if (isEmpty() == 0) {
        string cari;
        cout << "Masukkan data yang ingin dihapus : ";
        cin >> cari;

        TNode *bantu = head, *sebelum, *hapusArr[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        do {
            bantu2 = bantu;
            if (cari == bantu->data) {
                hapusArr[hitung++] = bantu;
                apaDitemukan = true;
                if (bantu != head && bantu != tail) {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        } while (bantu != head);

        if (apaDitemukan == true) {
            for (int i = 0; i < hitung; i++) {
                if (hapusArr[i] == head) {
                     if (head != tail) {
                        head = head->next;
                        tail->next = head;
                     } else {
                        init();
                     }
                     delete hapusArr[i];
                } else if (hapusArr[i] == tail) {
                    TNode *newTail = head;
                    while (newTail->next != tail) {
                         newTail = newTail->next;
                    }
                    tail = newTail;
                    tail->next = head;
                    delete hapusArr[i];
                } else {
                    delete hapusArr[i];
                }
            }
            cout << "Setiap data \"" << cari << "\" yang terdapat pada Linked List sudah dihapus" << endl;
        } else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List" << endl;

    } else cout << "Data tidak ada pada Linked List" << endl;
}

void sisipkanSebelum() {
    if (isEmpty() == 0) {
        TNode *bantu = head, *sebelum = tail;
        string nextData;
        bool apaAda = false;

        cout << "Sisipkan data baru sebelum data : ";
        cin >> nextData;

        do {
            if (nextData == bantu->data) {
                apaAda = true;
                break;
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while (bantu != head);

        if (apaAda == true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu;
            sebelum->next = baru;

            if (bantu == head) head = baru;

            cout << "Data berhasil disisipkan" << endl;
        } else cout << "Data tidak ditemukan" << endl;
    } else cout << "List Kosong" << endl;
}

void sisipkanSetelah() {
    if (isEmpty() == 0) {
        TNode *bantu = head;
        string prevData;
        bool apaAda = false;

        cout << "Sisipkan data baru setelah data : ";
        cin >> prevData;

        do {
            if (prevData == bantu->data) {
                apaAda = true;
                break;
            } else {
                bantu = bantu->next;
            }
        } while (bantu != head);

        if (apaAda == true) {
            cout << "Masukkan data yang ingin ditambahkan : ";
            cin >> dataBaru;

            TNode *baru = new TNode;
            baru->data = dataBaru;
            baru->next = bantu->next;
            bantu->next = baru;

            if (bantu == tail) tail = baru;

            cout << "Data berhasil disisipkan" << endl;
        } else cout << "Data tidak ditemukan" << endl;
    } else cout << "List Kosong" << endl;
}
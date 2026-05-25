#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target) {
    cout << "\n--- Melakukan Sequential Search ---\n";
    cout << "Daftar Angka:\n";

    for (int i = 0; i < nums.size(); ++i) {
        cout << "[" << i + 1 << "] " << nums[i] << " ";
    }
    cout << "\n";

    bool found = false;
    vector<int> found_indices;
    int comparisons = 0;

    for (int i = 0; i < nums.size(); ++i) {
        comparisons++;
        if (nums[i] == target) {
            found = true;
            found_indices.push_back(i + 1);
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan!\n";
        cout << "Ditemukan sebanyak " << found_indices.size() << " kali pada urutan: ";
        for (int i = 0; i < found_indices.size(); ++i) {
            cout << found_indices[i];
            if (i < found_indices.size() - 1) cout << ", ";
        }
        cout << "\n";
    } else {
        cout << "Angka " << target << " tidak ditemukan.\n";
    }
    cout << "Jumlah perbandingan: " << comparisons << "\n";
}

void binarySearch(const vector<int> &nums, int target) {
    cout << "\n--- Melakukan Binary Search ---\n";

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    cout << "Daftar Angka (terurut):\n";
    for (int i = 0; i < sorted_nums.size(); ++i) {
        cout << "[" << i + 1 << "] " << sorted_nums[i] << " ";
    }
    cout << "\n";

    int left = 0, right = sorted_nums.size() - 1;
    bool found = false;
    int index = -1, comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        comparisons++;
        if (sorted_nums[mid] == target) {
            found = true;
            index = mid + 1;
            break;
        } else if (sorted_nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found) {
        cout << "Angka " << target << " ditemukan pada urutan: " << index << ".\n";
    } else {
        cout << "Angka " << target << " tidak ditemukan.\n";
    }
    cout << "Jumlah perbandingan: " << comparisons << "\n";
}

void clearScreen() {
    system("cls");
}

void explain() {
    clearScreen();
    cout << "=== PERBEDAAN SEQUENTIAL SEARCH DAN BINARY SEARCH ===\n\n";

    cout << "1. SEQUENTIAL SEARCH (PENCARIAN SEKUENSIAL):\n";
    cout << "   - Cara Kerja : Memeriksa setiap elemen secara berurutan dari indeks pertama sampai akhir.\n";
    cout << "   - Syarat Data : Bebas, tidak wajib diurutkan terlebih dahulu (bisa acak).\n";
    cout << "   - Waktu Proses : O(n), waktu pencarian berbanding lurus dengan jumlah elemen.\n";
    cout << "   - Ruang memori : O(1).\n\n";

    cout << "2. BINARY SEARCH (PENCARIAN BINER):\n";
    cout << "   - Cara Kerja : Membelah area pencarian menjadi dua bagian (kiri/kanan) secara terus menerus.\n";
    cout << "   - Syarat data : Wajib dalam keadaan sudah diurutkan (sorting) sebelum dicari.\n";
    cout << "   - Waktu proses : O(log n), jauh lebih cepat dan efisien memangkas waktu.\n";
    cout << "   - Ruang memori: O(1).\n\n";

    cout << "RINGKASAN:\n";
    cout << "Gunakan Sequential Search jika data berskala kecil atau belum terurut.\n";
    cout << "Gunakan Binary Search untuk memproses dataset besar yang kondisinya sudah rapi/terurut.\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu \n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val : nums) val = dist(rng);

                cout << "\n--- Memulai Sequential Search --- \n";
                for (int i = 0; i < nums.size(); ++i)
                    cout << "[" << i + 1 << "] " << nums[i] << " ";
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val : nums) val = dist(rng);

                cout << "\n--- Memulai Binary Search --- \n";
                for (int i = 0; i < nums.size(); ++i)
                    cout << "[" << i + 1 << "] " << nums[i] << " ";
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Aurora Shafa Salsabila (2510817220010)\n";
                break;

            default:
                cout << "Opsi tidak valid. Coba lagi.\n";
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
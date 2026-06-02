#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearchFirst(int arr[], int kiri, int kanan, int target) {
    int hasil = -1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == target) {
            hasil = tengah;
            kanan = tengah - 1; 
        } else if (arr[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return hasil;
}

int main() {
    int n, x;
    
    if (!(cin >> n >> x)) return 0;

    int *arr = new int[n];
    
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 31; 
        cout << arr[i];
        if (i < n - 1) {
            cout << " "; 
        }
    }
    cout << endl; 

    bubbleSort(arr, n);

    int totalPasangan = 0;

    for (int i = 0; i < n - 1; i++) {
        int angkaDicari = x - arr[i];

        int indeksKetemu = binarySearchFirst(arr, i + 1, n - 1, angkaDicari);

        if (indeksKetemu != -1) {
            int j = indeksKetemu;
            while (j < n && arr[j] == angkaDicari) {
                totalPasangan++;
                j++;
            }
        }
    }

    cout << totalPasangan << endl;

    delete[] arr;

    return 0;
}

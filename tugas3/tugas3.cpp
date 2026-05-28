#include <iostream>
#include <algorithm> 

using namespace std;

int binarySearch(int arr[], int kiri, int kanan, int target) {
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target) {
            return tengah; 
        } 
        else if (arr[tengah] < target) {
            kiri = tengah + 1; 
        } 
        else {
            kanan = tengah - 1;
        }
    }
    return -1; 
}

int main() {
    int n, x;
    
    cin >> n >> x;
    
    int *arr = new int[n]; 
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    int jumlahPasangan = 0;
    
    for (int i = 0; i < n - 1; i++) {
        
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        
        int angkaDicari = x - arr[i];
        
        int indeksKetemu = binarySearch(arr, i + 1, n - 1, angkaDicari);
        
        if (indeksKetemu != -1) {
            jumlahPasangan++; 
        }
    }
    
    cout << jumlahPasangan << endl;
    
    delete[] arr;
    
    return 0;
}
#include <iostream>
#include <algorithm> 

using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
    
    Node(int nilai) {
        data = nilai;
        kiri = nullptr;
        kanan = nullptr;
    }
};

Node* insert(Node* root, int nilai) {
    if (root == nullptr) {
        return new Node(nilai);
    }
    
    if (nilai < root->data) {
        root->kiri = insert(root->kiri, nilai);
    } 
    else if (nilai > root->data) {
        root->kanan = insert(root->kanan, nilai);
    }
    
    return root;
}

int cariJarakTerjauh(Node* root, int& jarakMaksimal) {
    if (root == nullptr) {
        return 0;
    }
    
    int kedalamanKiri = cariJarakTerjauh(root->kiri, jarakMaksimal);
    int kedalamanKanan = cariJarakTerjauh(root->kanan, jarakMaksimal);
    
    jarakMaksimal = max(jarakMaksimal, kedalamanKiri + kedalamanKanan);
    
    return 1 + max(kedalamanKiri, kedalamanKanan);
}

int main() {
    int n;
    
    if (!(cin >> n)) return 0;
    
    Node* root = nullptr;
    
    for (int i = 0; i < n; i++) {
        int angka;
        cin >> angka;
        root = insert(root, angka);
    }
    
    int hasilJarak = 0;
    
    cariJarakTerjauh(root, hasilJarak);
    
    cout << hasilJarak << endl;
    
    return 0;
}
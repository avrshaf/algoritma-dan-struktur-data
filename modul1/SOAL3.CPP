#include<iostream>

using namespace std;

int main(){
    char huruf;
    char kata[10];
    int angka;

    cout<< "Masukkan sebuah huruf : ";
    cin>>huruf; 
    cout<< "Masukkan sebuah kata  : ";
    cin>>kata; 
    cout<< "Masukkan Angka        : ";
    cin>>angka;
    
    cout<< "Huruf yang Anda masukkan adalah : "<<huruf<< endl;
    cout<< "Kata yang Anda masukkan adalah  : "<<kata<< endl;
    cout<< "Angka yang Anda masukkan adalah : "<<angka<< endl;

    return 0;
}
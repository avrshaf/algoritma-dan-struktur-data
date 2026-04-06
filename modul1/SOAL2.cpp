#include<iostream>

using namespace std;

struct plat
{
    char nomor[10]  = "DA1234MK";
    char jenis[10]  = "RUSH";
    char nama[20]   = "Andika Hartanto";
    char alamat[30] = "Jl.kayu Tangi 1";
    char kota[20]   = "Banjarmasin";
};

int main()
{
    plat mobil;

    cout<< "Plat Nomor Kendaraan : "<<mobil.nomor<<endl;
    cout<< "Jenis Kendaraan      : "<<mobil.jenis<<endl;
    cout<< "Nama Pemilik         : "<<mobil.nama<<endl;
    cout<< "Alamat               : "<<mobil.alamat<<endl;
    cout<< "kota                 : "<<mobil.kota<<endl;
    return 0;
}
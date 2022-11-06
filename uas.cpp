#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//membuat fungsi
void cetak()
{
    cout << "------------------------------------------" << endl;
    cout << "|	           TOKO BAJU                  |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "\t===============================================" << endl;

    cout << "\t===============================================" << endl;
}

void menu()
{
    cout << "\n1. Input data baju\n";         //push
    cout << "2. Tampilkan isi keranjang\n";   //display
    cout << "3. Searching item\n";            //searching
    cout << "4. Sorting berdasarkan harga\n"; //sorting
    cout << "5. Ambil/baca buku teratas\n";   //pop
    cout << "6. Pembayaran\n";
    cout << "7. Exit\n";
    cout << "Masukkan pilihan : ";
}

struct item
{
    int jumlah[50], harga[50];
    string jenis_pakaian[50];
} item;

struct toko
{
    int jum_item, bayar, diskon, sub_tot[50];
    string nama;
} kasir;


int top = 0;

void display() // menampilkan barang belanjaan
{
    if (top <= 0)
    {
        cout << " stack empty";
        return;
    }
    for (int i = top; i > 0; i--)
        cout << item.jenis_pakaian[i] << " " << item.harga[i] << endl;
}

void ambilbaju() // melakukan pop pada barang belanjaan
{
    int temp;
    string tempbaju;
    if (top <= 0)
    {
        cout << "Keranjang Kosong." << endl;
        return;
    }
    tempbaju = item.jenis_pakaian[top];
    temp = item.harga[top];
    top--;
    cout << "Kembalikan Belanjaan ke rak : " << temp << endl;
}

void searching() // melakukan searching barang belanjaan
{
    string cari;
    cout << "masukan item yang ingin dicari ";
    cin >> cari;

    int i;
    bool cek = false;

    for (int i = 0; i < top; i++)
    {
        if (item.jenis_pakaian[i] == cari)
        {
            cout << "item " << item.jenis_pakaian[i] << " dengan harga " << item.harga[1] << " ditemukan pada urutan ke- " << i << endl;
            cek = true;
        }
    }
    if (cek == false)
    {
        cout << "item tidak tidemukan" << endl;
    }
}

void sorting()
{
    int maks;
    string maksbaju;
    for (int i = top; i > 0; i--)
    {
        for (int j = top; j > i; j--)
        {
            if (item.harga[j] > item.harga[j - 1])
            {
                maks = item.harga[j];
                maksbaju = item.jenis_pakaian[j];
                item.harga[j] = item.harga[j - 1];
                item.jenis_pakaian[j] = item.jenis_pakaian[j - 1];
                item.harga[j - 1] = maks;
                item.jenis_pakaian[j - 1] = maksbaju;
            }
        }
    }
    cout << "urut berdasar harga : ";
    for (int i = top; i > 0; i--)
    {
        cout << item.harga[i] << " " << item.jenis_pakaian[i] << endl;
    }
}

int main()
{
    //Inisialisasi atau deklarasi variabel
    string pilih;
    double *tot, x;
    tot = &x;
    int pil;

    cetak();
    cout << "Member atau Non member <YA/TIDAK>: ";
    cin >> pilih;
    cout << "------------------------------------------" << endl;

    if (pilih == "YA")
    {
    menu:
        menu();
        cin >> pil;
        system("cls");

        switch (pil)
        {
        case 1:
            cout << "========== Hai Member Toko Zalza ==========" << endl;
            cout << "Nama: ";
            cin.ignore();
            getline(cin, kasir.nama);

            cout << "------------------------------------------" << endl;
            cout << "Masukan Barang Ke-" << top + 1 << endl;
            cout << "Jenis Pakaian : ";
            cin >> item.jenis_pakaian[top + 1]; //Pengguna input Jenis Pakaian disimpan pada array jenis_pakaian
            cout << "Jumlah      : ";
            cin >> item.jumlah[top + 1]; //Pengguna input jumlah disimpan pada array jumlah
            cout << "Harga       : ";
            cin >> item.harga[top + 1];                                          //Pengguna input harga disimpan pada array harga
            kasir.sub_tot[top + 1] = item.jumlah[top + 1] * item.harga[top + 1]; // Menjumlahkan Harga sub total item
            *tot += kasir.sub_tot[top + 1];                                      //Menjumlahkan seluruh sub total item

            top++;
            break;

        case 2:
            display();
            break;

        case 3:
            searching();
            break;

        case 4:
            sorting();
            break;

        case 5:
            ambilbaju();
            break;

        case 6:
            //Kondisi untuk menentukan diskon yang didapatkan berdasarkan total belanja
            if (*tot >= 100000)
            {
                kasir.diskon = 0.10 * *tot; // diskon sebesar 10%
                //Menampilkan Keterangan
                cout << "=============== PEMBAYARAN ===============" << endl;
                cout << "Jenis Member 	: Ya" << endl;
                cout << "Nama Pelanggan	: " << kasir.nama << endl;
                cout << "Jumlah Bayar 	: Rp." << *tot << endl;                //Menampilkan jumlah bayar (belum termasuk diskon)
                cout << "Diskon        	: Rp." << kasir.diskon << endl;        //Menampilkan diskon
                cout << "Total Bayar  	: Rp." << *tot - kasir.diskon << endl; //Menampilkan total harga yang harus dibayar
                cout << "Bayar        	: Rp.";
                cin >> kasir.bayar;                                                              // Input dari user untuk jumlah yang dibayar
                cout << "Kembali      	: Rp." << (kasir.bayar - (*tot - kasir.diskon)) << endl; // Menampilkan uang kembali
                cout << "-------------- TERIMA KASIH --------------" << endl;
            }
            else
            {
                cout << "=============== PEMBAYARAN ===============" << endl;
                cout << "Jenis Member 	: Ya" << endl;
                cout << "Nama Pelanggan	: " << kasir.nama << endl;
                cout << "Diskon        	: Rp.-" << endl;
                cout << "Total Bayar  	: Rp." << *tot << endl;
                cout << "Bayar          : Rp.";
                cin >> kasir.bayar;
                cout << "Kembali      	: Rp." << (kasir.bayar - (*tot - kasir.diskon)) << endl;
                cout << "-------------- TERIMA KASIH --------------" << endl;
            }
            break;
        case 7:
            return 0;
            break;

        default:
            break;
        }
        goto menu;
    }

    else if (pilih == "TIDAK")
    {
    menu2:
        menu();
        cin >> pil;
        system("cls");
        switch (pil)
        {
        case 1:
            cout << "========== Hai Member Toko Zalza ==========" << endl;
            cout << "Nama: ";
            cin.ignore();
            getline(cin, kasir.nama);
            cout << "------------------------------------------" << endl;
            cout << "Masukan Barang Ke-" << top + 1 << endl;
            cout << "Jenis Pakaian : ";
            cin >> item.jenis_pakaian[top + 1]; //Pengguna input jenis pakaian disimpan pada array nama_barang
            cout << "Jumlah      : ";
            cin >> item.jumlah[top + 1]; //Pengguna input jumlah disimpan pada array jumlah
            cout << "Harga       : ";
            cin >> item.harga[top + 1];                                          //Pengguna input harga disimpan pada array harga
            kasir.sub_tot[top + 1] = item.jumlah[top + 1] * item.harga[top + 1]; // Menjumlahkan Harga sub total barang
            *tot += kasir.sub_tot[top + 1];                                      //Menjumlahkan seluruh sub total barang

            top++;
            break;
        case 2:
            display();
            break;

        case 3:
            searching();
            break;

        case 4:
            sorting();
            break;

        case 5:
            ambilbaju();
            break;

        case 6:
            //Menampilkan Keterangan
            cout << "=============== PEMBAYARAN ===============" << endl;
            cout << "Jenis Member 	: Tidak" << endl;
            cout << "Nama Pelanggan	: " << kasir.nama << endl;
            cout << "Jumlah Bayar 	: Rp." << *tot << endl; //Menampilkan jumlah bayar (belum termasuk diskon)
            cout << "Diskon        	: Rp.-" << endl;        //Menampilkan diskon
            cout << "Total Bayar  	: Rp." << *tot << endl; //Menampilkan total harga yang harus dibayar
            cout << "Bayar        	: Rp.";
            cin >> kasir.bayar;                                           // Input dari user untuk jumlah yang dibayar
            cout << "Kembali      	: Rp." << kasir.bayar - *tot << endl; // Menampilkan uang kembal
            cout << "-------------- TERIMA KASIH --------------" << endl;
            break;

        case 7:
            return 0;
            break;

        default:
            break;
        }
        goto menu2;
    }
    else
    {
        cout << "Data yang anda masukan salah" << endl;
    }

    cin.get();

    return 0;
}

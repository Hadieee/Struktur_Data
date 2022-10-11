#include <iostream>  // Untuk penggunaan fungsi cout, cin, dan endl
#include <conio.h>   // Untuk penggunaan fungsi getch
#include <iomanip>   // Digunakan untuk ngerapihin spasi membuat table
using namespace std; // Agar tidak perlu menuliskan "std::"

struct anggota // Terdapat sebuah struct untuk mendeklarasi array dari nama, jenis kelamin, tinggi badan, umur dan berat raket
{
    string nama;
    string kelamin;
    int tinggi;
    int umur;
    int berat;
};

struct anggota data_anggota[5]; // Untuk mendeklarasikan sebuah array data_anggota yang bertipe struct data

int a, b, c, i, j, pilih; // Untuk keperluan pertambahan indeks array, nomor, pilihan, dan perulangan

string Nama; // Untuk variabel saat mencari nama

// Untuk tanya saat ingin keluar dari program
char tanya;

// Prototype
void inputdata(anggota *ptr_anggota);
void lihatdata(anggota *ptr_anggota);
void editdata(anggota *ptr_anggota);
void hapusdata(anggota *ptr_anggota);

// Fungsi utama
int main()
{

    anggota *ptr_anggota;
    ptr_anggota = &data_anggota[0];

// Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
awal:
    system("cls");
    system("color 5A");
    cout << "\n============================= PROGRAM CRUD DATA ANGGOTA =============================";
    cout << "\n=================================== PILIHAN MENU ====================================\n";
    cout << "\n\t\t\t\t1. Masukkan data";
    cout << "\n\t\t\t\t2. Lihat Data";
    cout << "\n\t\t\t\t3. Edit Data";
    cout << "\n\t\t\t\t4. Hapus Data";
    cout << "\n\t\t\t\t5. Keluar\n";
    cout << "\n=====================================================================================\n";
    cout << "\nMasukkan Pilihan : ";
    pilih = getch();
    switch (pilih)
    {
    case '1':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata(ptr_anggota);
            goto awal;
        }
    case '2':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            lihatdata(ptr_anggota);
            goto awal;
        }
    case '3':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            editdata(ptr_anggota);
            goto awal;
        }
    case '4':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata(ptr_anggota);
            goto awal;
        }
    case '5':
    {
        system("cls");
    // Terdapat label Tanya sebagai tempat untuk kembali ke pilihan ingin keluar program ketika salah dalam memilih
    Tanya:

        cout << "\nApakah anda ingin keluar dari program ? (Y / T) : " << endl; // Untuk menanyakan user apakah ingin keluar dari program
        tanya = getch();
        switch (tanya)
        {
        case ('y'):
        case ('Y'):
            system("cls");
            cout << "=======================================================================" << endl;
            cout << "Terimakasih telah menggunakan program ini :) Semoga harimu menyenangkan" << endl;
            cout << "=======================================================================";
            exit(0);

        case ('t'):
        case ('T'):
            system("cls");
            goto awal;

        // Untuk kesalahan dalam memilih
        default:
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            goto Tanya;
        }
    }
    // Untuk kesalahan dalam memilih
    default:
    {
        cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
        getch();
        goto awal;
    }
    }
}

// Prosedur untuk input data
void inputdata(anggota *ptr_anggota)
{
    for (int i = 0; i < 5; i++)
    {
        if (ptr_anggota->nama == "")
        {
            system("color 5A");
            cout << "Nama Anggota\t\t\t\t: ";
            getline(cin, ptr_anggota->nama);
            fflush(stdin);
            cout << "Jenis Kelamin (L / P)\t\t\t: ";
            cin >> ptr_anggota->kelamin;
            fflush(stdin);
            cout << "Tinggi Badan\t\t\t\t: ";
            cin >> ptr_anggota->tinggi;
            fflush(stdin);
            cout << "Berat Badan\t\t\t\t: ";
            cin >> ptr_anggota->berat;
            fflush(stdin);
            cout << "Umur\t\t\t\t\t: ";
            cin >> ptr_anggota->umur;
            fflush(stdin);
            break;
        }
        ptr_anggota++;
    }

    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}

// Prosedur untuk lihat data
void lihatdata(anggota *ptr_anggota)
{
    system("color 5A");
    cout << "\n============================================================= Menampilkan Data =======================================================================\n\n";
    cout << "======================================================================================================================================================\n";
    cout << "||" << setw(5) << "NO" << setw(5) << "||" << setw(25) << "Nama Anggota" << setw(15) << "||" << setw(25) << "Jenis Kelamin" << setw(15) << "||" << setw(15) << "Tinggi Badan" << setw(5) << "||" << setw(15) << "Berat Badan" << setw(5) << "||" << setw(10) << "Umur" << setw(8) << "||";
    cout << "\n======================================================================================================================================================";

    // Variabel j untuk penomoran dalam tabel
    j = 0;
    for (i = 0; i < 5; i++)
    {
        j += 1;
        cout << "\n";
        cout << "||" << setw(4) << j << setw(6) << "||";
        cout << setw(25) << ptr_anggota->nama << setw(15) << "||";
        cout << setw(20) << ptr_anggota->kelamin << setw(20) << "||";
        cout << setw(10) << ptr_anggota->tinggi << setw(10) << "||";
        cout << setw(10) << ptr_anggota->berat << setw(10) << "||";
        cout << setw(10) << ptr_anggota->umur << setw(8) << "||";
        ptr_anggota++;
        cout << "\n======================================================================================================================================================";
    }
    getch();
    system("cls");
}

void editdata(anggota *ptr_anggota) // Prosedur untuk edit data
{
// Terdapat label apa sebagai tempat untuk kembali mengedit data ketika salah dalam memilih pilihan
apa:
    system("cls");
    system("color 5A");
    cout << "Masukan nama yang ingin diedit\t\t: ";
    getline(cin, Nama);

    for (b = 0; b < 5; b++)
    {
        if (ptr_anggota->nama == Nama)
        {
            cout << "Nama Panggilan\t\t\t\t: ";
            getline(cin, ptr_anggota->nama);
            fflush(stdin);
            cout << "Jenis Kelamin (L / P)\t\t\t: ";
            cin >> ptr_anggota->kelamin;
            fflush(stdin);
            cout << "Tinggi Badan\t\t\t\t\t: ";
            cin >> ptr_anggota->tinggi;
            fflush(stdin);
            cout << "Berat Badan\t\t\t\t\t: ";
            cin >> ptr_anggota->berat;
            fflush(stdin);
            cout << "Umur\t\t\t\t\t: ";
            cin >> ptr_anggota->umur;
            fflush(stdin);
            cout << "\n============================================================ Data berhasil diedit ============================================================\n";
            break;
        }
        if (b == 5)
        {
            cout << "Nama tidak ditemukan";

            // Untuk menanyakan user apakah ingin mengedit data lagi
            cout << "\nApakah anda ingin mengedit kembali ? (Y / T) : " << endl;
            tanya = getch();
            switch (tanya)
            {
            case ('y'):
            case ('Y'):
                system("cls");
                goto apa;

            case ('t'):
            case ('T'):
                goto langsung;

            // Untuk kesalahan dalam memilih
            default:
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto apa;
            }
        }
    }

// Terdapat label langsung sebagai tempat untuk melihat data ketika sudah tidak ingin mengedit data
langsung:
    lihatdata(ptr_anggota);
}

// Prosedur untuk hapus data
void hapusdata(anggota *ptr_anggota)
{
// Terdapat label iya sebagai tempat untuk kembali menghapus data ketika salah dalam memilih pilihan
iya:
    system("color 5A");
    cout << "Masukan nama yang ingin dihapus\t\t: ";
    getline(cin, Nama);

    for (c = 0; c < 10; c++)
    {
        if (ptr_anggota->nama == Nama)
        {
            for (int i = c; i < 4; i++)
            {
                data_anggota[i] = data_anggota[i + 1];
            }
            system("cls");
            cout << "\n============================================================ Data berhasil dihapus ============================================================\n";
            break;
        }
        if (c == 10)
        {
            cout << "Nama tidak ditemukan";

            // Untuk menanyakan user apakah ingin menghapus data lagi
            cout << "\nApakah anda ingin mengedit kembali ? (Y / T) : " << endl;
            tanya = getch();
            switch (tanya)
            {
            case ('y'):
            case ('Y'):
                system("cls");
                goto iya;

            case ('t'):
            case ('T'):
                goto langsungg;

            // Untuk kesalahan dalam memilih
            default:
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto iya;
            }
        }
        ptr_anggota = data_anggota;
    }

// Terdapat label langsungg sebagai tempat untuk melihat data ketika sudah tidak ingin menghapus data
langsungg:
    lihatdata(ptr_anggota);
}
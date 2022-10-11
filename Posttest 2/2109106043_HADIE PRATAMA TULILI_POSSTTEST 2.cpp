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

struct Node
{
    anggota data;
    Node *next;
};

int isEmpty(Node **head)
{
    if (*head == NULL)
        return 1;
    else
        return 0;
}

struct anggota data_anggota; // Untuk mendeklarasikan sebuah  struct data yang bernama data_anggota

int a, b, c, i, j, pilih, middle; // Untuk keperluan pertambahan indeks array, nomor, pilihan, dan perulangan

string Nama; // Untuk variabel saat mencari nama data anggota

// Untuk tanya saat ingin keluar dari program
char tanya;

// Prototype
int jumlah(Node *Head);
void inputdata_first(Node **Head);
void inputdata_middle(Node **Head);
void inputdata_last(Node **Head);
void lihatdata(Node *Head);
void editdata(Node **Head);
void hapusdata_first(Node **Head);
void hapusdata_middle(Node **Head);
void hapusdata_last(Node **Head);

// Fungsi utama
int main()
{

	Node *Head = NULL;

// Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
awal:
    system("cls");
    system("color 6A");
    cout << "\n============================= PROGRAM CRUD DATA ANGGOTA =============================";
    cout << "\n=================================== PILIHAN MENU ====================================\n";
    cout << "\n\t\t\t\t1. Masukkan data di depan";
    cout << "\n\t\t\t\t2. Masukkan data di sela2 data";
    cout << "\n\t\t\t\t3. Masukkan data di terakhir";
    cout << "\n\t\t\t\t4. Lihat Data";
    cout << "\n\t\t\t\t5. Edit Data";
    cout << "\n\t\t\t\t6. Hapus data di depan";
    cout << "\n\t\t\t\t7. Hapus data di sela2 data";
    cout << "\n\t\t\t\t8. Hapus data di terakhir";
    cout << "\n\t\t\t\t9. Keluar\n";
    cout << "\n=====================================================================================\n";
    cout << "\nMasukkan Pilihan : ";
    pilih = getch();
    switch (pilih)
    {
    case '1':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata_first(&Head);
            goto awal;
        }
    case '2':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata_middle(&Head);
            goto awal;
        }
    case '3':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata_last(&Head);
            goto awal;
        }
    case '4':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            lihatdata(Head);
            goto awal;
        }
    case '5':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            editdata(&Head);
            goto awal;
        }
    case '6':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata_first(&Head);
            goto awal;
        }
    case '7':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            // hapusdata_middle(&Head);
            goto awal;
        }
    case '8':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            // hapusdata_last(&Head);
            goto awal;
        }
    case '9':
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

// Menghitung panjang node
int jumlah(Node *Head){
	int i;
	while(Head != NULL){
		Head = Head->next;
		i++;
	}
	return i;
}

// Prosedur untuk input data
void inputdata_first(Node **Head)
{
    Node *nodeBaru = new Node;

    system("color 6A");
    cout << "Nama Anggota\t\t\t\t: ";
    getline(cin, nodeBaru->data.nama);
    fflush(stdin);
    cout << "Jenis Kelamin (L / P)\t\t\t: ";
    cin >> nodeBaru->data.kelamin;
    fflush(stdin);
    cout << "Tinggi Badan\t\t\t\t: ";
    cin >> nodeBaru->data.tinggi;
    fflush(stdin);
    cout << "Berat Badan\t\t\t\t: ";
    cin >> nodeBaru->data.berat;
    fflush(stdin);
    cout << "Umur\t\t\t\t\t: ";
    cin >> nodeBaru->data.umur;
    fflush(stdin);

    nodeBaru->next = *Head;
    *Head = nodeBaru;

    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}

void inputdata_middle(Node **Head)
{
    middle = 0;

    if (*Head == NULL) {
        cout << ">> LinkedList masih kosong <<" << endl;
        getch();
        return;
    }
    lihatdata(*Head);
    cout << endl << "Pilih letak Tambah Data : ";cin >> middle;fflush(stdin);
    system("cls");
	Node *temp = *Head;
	Node *nodeBaru = new Node;

    if (middle > 1 && middle < jumlah(*Head))
    {
        for (int i = 1; i < jumlah(*Head);i++)
        {
            if (i == middle-1)
            {
                system("color 6A");
                cout << "Nama Anggota\t\t\t\t: ";
                getline(cin, nodeBaru->data.nama);
                fflush(stdin);
                cout << "Jenis Kelamin (L / P)\t\t\t: ";
                cin >> nodeBaru->data.kelamin;
                fflush(stdin);
                cout << "Tinggi Badan\t\t\t\t: ";
                cin >> nodeBaru->data.tinggi;
                fflush(stdin);
                cout << "Berat Badan\t\t\t\t: ";
                cin >> nodeBaru->data.berat;
                fflush(stdin);
                cout << "Umur\t\t\t\t\t: ";
                cin >> nodeBaru->data.umur;
                fflush(stdin);

                nodeBaru->next = temp->next;
                temp->next = nodeBaru;

                cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
                getch();
                system("cls");    
                break;
            }        
            temp = temp->next;
        }
    }
}

void inputdata_last(Node **Head)
{
    Node *nodeBaru = new Node;

    system("color 6A");
    cout << "Nama Anggota\t\t\t\t: ";
    getline(cin, nodeBaru->data.nama);
    fflush(stdin);
    cout << "Jenis Kelamin (L / P)\t\t\t: ";
    cin >> nodeBaru->data.kelamin;
    fflush(stdin);
    cout << "Tinggi Badan\t\t\t\t: ";
    cin >> nodeBaru->data.tinggi;
    fflush(stdin);
    cout << "Berat Badan\t\t\t\t: ";
    cin >> nodeBaru->data.berat;
    fflush(stdin);
    cout << "Umur\t\t\t\t\t: ";
    cin >> nodeBaru->data.umur;
    fflush(stdin);

	if (*Head == NULL){
		*Head = nodeBaru;
	}else {
		Node *temp = *Head;
		while(temp->next != NULL){
			temp = temp->next;
		}temp->next = nodeBaru;
	}

    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}


// Prosedur untuk lihat data
void lihatdata(Node *Head)
{
    system("color 6A");

    if (Head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        getch();
        return;
    } else
    {
        j = 0;
        cout << "\n============================================================= Menampilkan Data =======================================================================\n\n";
        cout << "======================================================================================================================================================\n";
        cout << "||" << setw(5) << "NO" << setw(5) << "||" << setw(25) << "Nama Anggota" << setw(15) << "||" << setw(25) << "Jenis Kelamin" << setw(15) << "||" << setw(15) << "Tinggi Badan" << setw(5) << "||" << setw(15) << "Berat Badan" << setw(5) << "||" << setw(10) << "Umur" << setw(8) << "||";
        cout << "\n======================================================================================================================================================";
       
        while(Head != NULL)
        {
            
            // Variabel j untuk penomoran dalam tabel
            j += 1;
            cout << "\n";
            cout << "||" << setw(4) << j << setw(6) << "||";
            cout << setw(25) << Head->data.nama << setw(15) << "||";
            cout << setw(20) << Head->data.kelamin << setw(20) << "||";
            cout << setw(10) << Head->data.tinggi << setw(10) << "||";
            cout << setw(10) << Head->data.berat << setw(10) << "||";
            cout << setw(10) << Head->data.umur << setw(8) << "||";
            Head = Head->next;
            cout << "\n======================================================================================================================================================";
        }
        getch();
        system("cls");
    }

}

void editdata(Node **Head) // Prosedur untuk edit data
{

    if (Head == NULL)
    {
        cout << "LinkedList masih kosong" << endl;
        return;
    }

// Terdapat label apa sebagai tempat untuk kembali mengedit data ketika salah dalam memilih pilihan
apa:
    system("cls");
    system("color 6A");
    cout << "Masukan nama anggota yang ingin diedit\t: ";
    getline(cin, Nama);

    Node *temp = *Head;

    while (temp != NULL)
    {
        if (temp->data.nama == Nama)
        {
            cout << "Nama Panggilan\t\t\t\t: ";
            getline(cin, temp->data.nama);
            fflush(stdin);
            cout << "Jenis Kelamin (L / P)\t\t\t: ";
            cin >> temp->data.kelamin;
            fflush(stdin);
            cout << "Tinggi Badan\t\t\t\t\t: ";
            cin >> temp->data.tinggi;
            fflush(stdin);
            cout << "Berat Badan\t\t\t\t\t: ";
            cin >> temp->data.berat;
            fflush(stdin);
            cout << "Umur\t\t\t\t\t: ";
            cin >> temp->data.umur;
            fflush(stdin);
            cout << "\n============================================================ Data berhasil diedit ============================================================\n";
            }
        temp = temp->next;
    }
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
            goto langsungg;

        // Untuk kesalahan dalam memilih
        default:
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            goto apa;
        }
    // Terdapat label langsungg sebagai tempat untuk melihat data ketika sudah tidak ingin menghapus data
    langsungg:
        lihatdata(*Head);
}

// Prosedur untuk hapus data
void hapusdata_first(Node **Head)
{
// Terdapat label iya sebagai tempat untuk kembali menghapus data ketika salah dalam memilih pilihan
iya:
    system("color 6A");
    system("cls");
    cout << "\n============================================================ Data berhasil dihapus ============================================================\n";
    break;
        if (c == 10)
        {
            cout << "Nama tidak ditemukan";

            // Untuk menanyakan user apakah ingin menghapus data lagi
            cout << "\nApakah anda ingin menghapus kembali ? (Y / T) : " << endl;
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
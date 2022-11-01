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
    Node *prev;
};

struct anggota data_anggota; // Untuk mendeklarasikan sebuah  struct data yang bernama data_anggota

int a, b, c, i, j, pilih, middle, hapus; // Untuk keperluan perinputan indeks array, nomor, pilihan, dan perulangan

string Nama, arah; // Untuk variabel saat mencari nama data anggota

// Untuk tanya saat ingin keluar dari program
char tanya;

// Prototype
int jumlah(Node *Head);
void inputdata(Node **Head, Node **Tail);
void inputdata_first(Node **Head, Node **Tail);
void inputdata_middle(Node **Head, Node **Tail);
void inputdata_last(Node **Head, Node **Tail);
void lihatdata(Node *Head, Node *Tail, string arah);
void editdata(Node **Head, Node **Tail);
void hapusdata(Node **Head, Node **Tail);
void hapusdata_first(Node **Head, Node **Tail);
void hapusdata_middle(Node **Head, Node **Tail);
void hapusdata_last(Node **Head, Node **Tail);
Node *Merge(Node *h1, Node *h2, int pilihan, string attribut);
void MergeSort(Node **head, int pilihan, string attribut);
int fibonacciSearch(Node *node, string x, int n);
void tampilan_sorting(Node **Head, Node **Tail, int pilihan, string arah);
void tampilan_arah(Node **Head, Node **Tail);
void tampilan_urutan_sorting(Node **Head, Node **Tail, string arah);
void tampilan_pilihan_searching(Node **Head, Node **Tail);
void tampilan_searching(Node **Head, Node **Tail);

// Fungsi utama
int main()
{

    Node *Head = NULL, *Tail = NULL;

// Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
awal:
    system("cls");
    system("color 3F");
    cout << "\n============================= PROGRAM CRUD DATA ANGGOTA =============================";
    cout << "\n=================================== PILIHAN MENU ====================================\n";
    cout << "\n\t\t\t\t1. Input  Data Anggota";
    cout << "\n\t\t\t\t2. Lihat  Data Anggota";
    cout << "\n\t\t\t\t3. Edit   Data Anggota";
    cout << "\n\t\t\t\t4. Hapus  Data Anggota";
    cout << "\n\t\t\t\t5. Search Data Anggota\n";
    cout << "\n\t\t\t\t0. Keluar\n";
    cout << "\n=====================================================================================\n";
    cout << "\nMasukkan Pilihan : ";
    pilih = getch();
    switch (pilih)
    {
    case '1':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata(&Head, &Tail);
            goto awal;
        }
    case '2':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            tampilan_arah(&Head, &Tail);
            goto awal;
        }
    case '3':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            editdata(&Head, &Tail);
            getch();
            goto awal;
        }
    case '4':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata(&Head, &Tail);
            goto awal;
        }
    case '5':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            tampilan_searching(&Head, &Tail);
            goto awal;
        }
    case '0':
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
int jumlah(Node *Head)
{
    int i;
    while (Head != NULL)
    {
        Head = Head->next;
        i++;
    }
    return i;
}

// Prosedur untuk input data
void inputdata_first(Node **Head, Node **Tail)
{
    Node *nodeBaru = new Node;

    system("color 3F");
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

    nodeBaru->prev = NULL;
    nodeBaru->next = *Head;

    if (*Head == NULL && *Tail == NULL)
    {
        *Head = nodeBaru;
        *Tail = nodeBaru;
    }
    else
    {
        (*Head)->prev = nodeBaru;
        *Head = nodeBaru;
    }

    cout << "\n=========================== Data Berhasil Diinputkan ===========================";
    getch();
    system("cls");
}

void inputdata_middle(Node **Head, Node **Tail)
{

    if (*Head == NULL && *Tail == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }

apa:
    middle = 0;
    lihatdata(*Head, *Tail, "forward");
    cout << "\n\nPilih letak input Data \t\t\t: ";
    cin >> middle;
    fflush(stdin);
    Node *temp = *Head;
    Node *nodeBaru = new Node;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    if (middle == 1)
    {
        system("color 3F");
        cout << "\nNama Anggota\t\t\t\t: ";
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
        (*Head)->prev = nodeBaru;
        *Head = nodeBaru;

        cout << "\n=========================== Data Berhasil Diinputkan ===========================";
        getch();
    }

    else
    {
        if (middle > 1 && middle < jumlah(*Head))
        {
            for (int i = 1; i < jumlah(*Head); i++)
            {
                if (i == middle - 1)
                {
                    system("color 3F");
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
                    nodeBaru->prev = temp;
                    temp->next = nodeBaru;
                    nodeBaru->next->prev = nodeBaru;

                    cout << "\n========================================================= Data Berhasil Diinputkan ==================================================================\n";
                    getch();
                    break;
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "Nomor data tidak ditemukan";

        apaa:
            // Untuk menanyakan user apakah ingin mengedit data lagi
            cout << "\nApakah anda ingin menambahkan kembali ? (Y / T) : " << endl;
            tanya = getch();
            switch (tanya)
            {
            case ('y'):
            case ('Y'):
                system("cls");
                goto apa;

            case ('t'):
            case ('T'):
                break;
            // Untuk kesalahan dalam memilih
            default:
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto apaa;
            }
        }
    }
}

// Prosedur untuk input data
void inputdata_last(Node **Head, Node **Tail)
{
    Node *nodeBaru = new Node;

    system("color 3F");
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

    nodeBaru->prev = *Tail;
    nodeBaru->next = NULL;

    if (*Head == NULL && *Tail == NULL)
    {
        *Head = nodeBaru;
        *Tail = nodeBaru;
    }
    else
    {
        (*Tail)->next = nodeBaru;
        *Tail = nodeBaru;
    }

    cout << "\n=========================== Data Berhasil Diinputkan ===========================";
    getch();
    system("cls");
}

// Prosedur untuk lihat data
void lihatdata(Node *Head, Node *Tail, string arah)
{
    system("color 3F");
    if (Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
        j = 0;
        cout << "\n============================================================= MENAMPILKAN DATA =======================================================================";
        if (arah == "forward")
        {
            cout << "\n============================================================== SECARA FORWARD ========================================================================\n\n";
            cout << "======================================================================================================================================================\n";
            cout << "||" << setw(5) << "NO" << setw(5) << "||" << setw(25) << "Nama Anggota" << setw(15) << "||" << setw(25) << "Jenis Kelamin" << setw(15) << "||" << setw(15) << "Tinggi Badan" << setw(5) << "||" << setw(15) << "Berat Badan" << setw(5) << "||" << setw(10) << "Umur" << setw(8) << "||";
            cout << "\n======================================================================================================================================================";

            while (Head != NULL)
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
        }

        else if (arah == "backward")
        {
            cout << "\n============================================================= SECARA BACKWARD ========================================================================\n\n";
            cout << "======================================================================================================================================================\n";
            cout << "||" << setw(5) << "NO" << setw(5) << "||" << setw(25) << "Nama Anggota" << setw(15) << "||" << setw(25) << "Jenis Kelamin" << setw(15) << "||" << setw(15) << "Tinggi Badan" << setw(5) << "||" << setw(15) << "Berat Badan" << setw(5) << "||" << setw(10) << "Umur" << setw(8) << "||";
            cout << "\n======================================================================================================================================================";

            Node *temp = Head;
            while (temp != NULL)
            {
                temp = temp->next;
            }
            Node *temp1 = Tail;
            j = jumlah(Head) + 1;
            while (temp1 != NULL)
            {
                // Variabel j untuk penomoran dalam tabel
                j -= 1;
                cout << "\n";
                cout << "||" << setw(4) << j << setw(6) << "||";
                cout << setw(25) << temp1->data.nama << setw(15) << "||";
                cout << setw(20) << temp1->data.kelamin << setw(20) << "||";
                cout << setw(10) << temp1->data.tinggi << setw(10) << "||";
                cout << setw(10) << temp1->data.berat << setw(10) << "||";
                cout << setw(10) << temp1->data.umur << setw(8) << "||";
                cout << "\n======================================================================================================================================================";
                temp1 = temp1->prev;
            }
        }
    }
}

void editdata(Node **Head, Node **Tail) // Prosedur untuk edit data
{

    if (*Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
    // Terdapat label apa sebagai tempat untuk kembali mengedit data ketika salah dalam memilih pilihan
    apa:

        system("color 3F");
        lihatdata(*Head, *Tail, "forward");
        cout << "\n\nMasukan nama anggota yang ingin diedit\t: ";
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
                cout << "Tinggi Badan\t\t\t\t: ";
                cin >> temp->data.tinggi;
                fflush(stdin);
                cout << "Berat Badan\t\t\t\t: ";
                cin >> temp->data.berat;
                fflush(stdin);
                cout << "Umur\t\t\t\t\t: ";
                cin >> temp->data.umur;
                fflush(stdin);
                cout << "\n=============================================================== Data berhasil diedit ================================================================\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Nama tidak ditemukan";

    apaa:
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
            goto apaa;
        }
    // Terdapat label langsungg sebagai tempat untuk melihat data ketika sudah tidak ingin menghapus data
    langsungg:
        lihatdata(*Head, *Tail, "forward");
    }
}

// Prosedur untuk hapus data
void hapusdata_first(Node **Head, Node **Tail)
{
    Node *deleteNode = *Head;
    if (*Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else if ((*Head)->next == NULL)
    {
        *Head = NULL;
        *Tail = NULL;
        delete deleteNode;
    }
    else
    {
        *Head = (*Head)->next;
        (*Head)->prev = NULL;
        delete deleteNode;
        system("color 3F");
        cout << "\n=========================================================== Data berhasil dihapus ====================================================================\n";
        lihatdata(*Head, *Tail, "forward");
    }
}

// Prosedur untuk hapus data
void hapusdata_middle(Node **Head, Node **Tail)
{
apa:
    hapus = 0;
    lihatdata(*Head, *Tail, "forward");
    system("color 3F");
    cout << "\n\nPilih letak data yang ingin dihapus : ";
    cin >> hapus;
    fflush(stdin);
    Node *deleteNode = *Head;

    if (*Head == NULL && *Tail == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else if (hapus == 1 && *Head != NULL)
    {
        *Head = (*Head)->next;
        free(deleteNode);
        if (*Head != NULL)
        {
            (*Head)->next = NULL;
        }
    }
    else
    {
        if (hapus > 1 && hapus < jumlah(*Head))
        {
            for (int i = 1; i < jumlah(*Head); i++)
            {
                if (i == hapus - 1)
                {
                    break;
                }
                deleteNode = deleteNode->next;
            }
            Node *temp = deleteNode->next;
            deleteNode->next = deleteNode->next->next;
            if (deleteNode->next->next != NULL)
            {
                deleteNode->next->next->prev = deleteNode->next;
            }

            free(temp);
            cout << "\n=========================================================== Data berhasil dihapus ====================================================================\n";
        }
        else
        {
            cout << "Data tidak ditemukan";
        apaa:
            // Untuk menanyakan user apakah ingin mengedit data lagi
            cout << "\nApakah anda ingin menghapus kembali ? (Y / T) : " << endl;
            tanya = getch();
            switch (tanya)
            {
            case ('y'):
            case ('Y'):
                system("cls");
                goto apa;

            case ('t'):
            case ('T'):
                break;

            // Untuk kesalahan dalam memilih
            default:
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto apaa;
            }
        }
    }
}

// Prosedur untuk hapus data
void hapusdata_last(Node **Head, Node **Tail)
{
    Node *deleteNode = *Head;
    if (*Head == NULL && *Tail == NULL)
    {
        cout << "\n=============================== LinkedList Kosong  =====================";
        return;
    }
    else if ((*Head)->next == NULL)
    {
        *Head = NULL;
        *Tail = NULL;
        delete deleteNode;
    }
    else
    {
        Node *temp = *Tail;
        *Tail = (*Tail)->prev;
        (*Tail)->next = NULL;
        delete deleteNode;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Node *deleteNode = temp->next;
        temp->next = NULL;
        delete deleteNode;

        system("color 3F");
        cout << "\n=========================================================== Data berhasil dihapus ====================================================================\n";
        lihatdata(*Head, *Tail, "forward");
    }
}

void inputdata(Node **Head, Node **Tail)
{
input1:
    system("cls");
    system("color 3F");
    cout << "\n================================ INPUT DATA ANGGOTA ================================";
    cout << "\n=================================== INPUT SECARA ===================================\n";
    cout << "\n\t\t\t\t1. Masukkan data di depan";
    cout << "\n\t\t\t\t2. Masukkan data di sela2 data";
    cout << "\n\t\t\t\t3. Masukkan data di terakhir\n";
    cout << "\n\t\t\t\t0. Exit" << endl;
    cout << "\n=====================================================================================\n";
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
        case '1':
        {
            system("cls");
            inputdata_first(Head, Tail);
            goto input1;
        }
        case '2':
        {
            system("cls");
            inputdata_middle(Head, Tail);
            goto input1;
        }
        case '3':
        {
            system("cls");
            inputdata_last(Head, Tail);
            goto input1;
        }
        case '0':
        {
            break;
        }

        default:
        {
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            system("cls");
            goto input1;
        }
    }
}

void hapusdata(Node **Head, Node **Tail)
{
hapus1:
    system("cls");
    system("color 3F");
    cout << "\n================================ HAPUS DATA ANGGOTA ================================";
    cout << "\n=================================== HAPUS SECARA ===================================\n";
    cout << "\n\t\t\t\t1. Hapus data di depan";
    cout << "\n\t\t\t\t2. Hapus data di sela2 data";
    cout << "\n\t\t\t\t3. Hapus data di terakhir\n";
    cout << "\n\t\t\t\t0. Exit" << endl;
    cout << "\n=====================================================================================\n";
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
        case '1':
        {
            system("cls");
            hapusdata_first(Head, Tail);
            goto hapus1;
        }
        case '2':
        {
            system("cls");
            hapusdata_middle(Head, Tail);
            goto hapus1;
        }
        case '3':
        {
            system("cls");
            hapusdata_last(Head, Tail);
            goto hapus1;
        }
        case '0':
        {
            break;
        }

        default:
        {
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            system("cls");
            goto hapus1;
        }
    }
}



Node *Merge(Node *h1, Node *h2, int pilihan, string attribut)
{
    Node *t1 = new Node;
    Node *t2 = new Node;
    Node *temp = new Node;

    // Return if the first list is empty.
    if (h1 == NULL)
        return h2;

    // Return if the Second list is empty.
    if (h2 == NULL)
        return h1;

    t1 = h1;

    // A loop to traverse the second list, to merge the Nodes to h1 in sorted way.
    while (h2 != NULL)
    {
        // Taking head Node of second list as t2.
        t2 = h2;

        // Shifting second list head to the next.
        h2 = h2->next;
        t2->next = NULL;
        if (pilihan == 1)
        {
            // If the data value is lesser than the head of first list add that Node at the beginning.
            if (attribut == "umur")
            {
                if (h1->data.umur > t2->data.umur)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.umur <= t2->data.umur)
                {
                    t1 = t1->next;
                    goto flag;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }

            else if (attribut == "tinggi")
            {
                if (h1->data.tinggi > t2->data.tinggi)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag1:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.tinggi <= t2->data.tinggi)
                {
                    t1 = t1->next;
                    goto flag1;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }

            else if (attribut == "nama")
            {
                if (h1->data.nama > t2->data.nama)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag2:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.nama <= t2->data.nama)
                {
                    t1 = t1->next;
                    goto flag2;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }
        }

        else if (pilihan == 2)
        {
            // If the data value is lesser than the head of first list add that Node at the beginning.
            if (attribut == "umur")
            {
                if (h1->data.umur < t2->data.umur)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag3:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.umur >= t2->data.umur)
                {
                    t1 = t1->next;
                    goto flag3;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }

            else if (attribut == "tinggi")
            {
                if (h1->data.tinggi < t2->data.tinggi)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag4:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.tinggi >= t2->data.tinggi)
                {
                    t1 = t1->next;
                    goto flag4;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }

            else if (attribut == "nama")
            {
                if (h1->data.nama < t2->data.nama)
                {
                    t2->next = h1;
                    h1 = t2;
                    t1 = h1;
                    continue;
                }
            // Traverse the first list.
            flag5:
                if (t1->next == NULL)
                {
                    t1->next = t2;
                    t1 = t1->next;
                }
                // Traverse first list until t2->data more than Node's data.
                else if ((t1->next)->data.nama >= t2->data.nama)
                {
                    t1 = t1->next;
                    goto flag5;
                }
                else
                {
                    // Insert the Node as t2->data is lesser than the next Node.
                    temp = t1->next;
                    t1->next = t2;
                    t2->next = temp;
                }
            }
        }
    }
    // Return the head of new sorted list.
    return h1;
}

// A function implementing Merge Sort on linked list using reference.
void MergeSort(Node **head, int pilihan, string attribut)
{
    Node *first = new Node;
    Node *second = new Node;
    Node *temp = new Node;
    first = *head;
    temp = *head;

    // Return if list have less than two Nodes.
    if (first == NULL || first->next == NULL)
    {
        return;
    }
    else
    {
        // Break the list into two half as first and second as head of list.
        while (first->next != NULL)
        {
            first = first->next;
            if (first->next != NULL)
            {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = NULL;
        first = *head;
    }

    if (pilihan == 1)
    {
        if (attribut == "umur")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "umur");
            MergeSort(&second, 1, "umur");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 1, "umur");
        }

        else if (attribut == "tinggi")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "tinggi");
            MergeSort(&second, 1, "tinggi");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 1, "tinggi");
        }

        else if (attribut == "nama")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "nama");
            MergeSort(&second, 1, "nama");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 1, "nama");
        }
    }

    else if (pilihan == 2)
    {
        if (attribut == "umur")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 2, "umur");
            MergeSort(&second, 2, "umur");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 2, "umur");
        }

        else if (attribut == "tinggi")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 2, "tinggi");
            MergeSort(&second, 2, "tinggi");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 2, "tinggi");
        }

        else if (attribut == "nama")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "nama");
            MergeSort(&second, 1, "nama");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 2, "nama");
        }
    }
}

// Fibonacci Search algorithm
int fibonacciSearch(Node *node, string x, int n)
{
    int F0 = 0;
    int F1 = 1;
    int F = F0 + F1;
    while (F < n)
    {
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }
    int offset = -1;
    while (F > 1)
    {
        // Inisiasi awal
        Node *head = node;
        int i = min(offset + F0, n - 1);
        for (int trv = 0; head->next != NULL && trv < i; trv++)
        {
            head = head->next;
        }
        if (head->data.nama < x)
        {
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }
        else if (head->data.nama > x)
        {
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }
        else
        {
            return i;
        }
    }

    Node *head2 = node;
    for (int trv = 0; head2->next != NULL && trv < offset + 1; trv++)
    {
        head2 = head2->next;
    }
    if (F1 && head2->data.nama == x)
        return offset + 1;
    return -1;
}

// prosedur untuk tampilan sorting dengan urutan secara asceding
void tampilan_sorting(Node **Head, Node **Tail, int pilihan, string arah)
{
sorting:
    cout << "\n================================ SORTING DATA ANGGOTA ================================";
    cout << "\n================================== PILIHAN SORTING ===================================\n";
    cout << "1. Mengurutkan nama anggota" << endl;
    cout << "2. Mengurutkan umur anggota" << endl;
    cout << "3. Mengurutkan tinggi anggota\n";
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    
    if(arah == "forward")
    {
        if (pilihan == 1)
        {
            switch (pilih)
            {
            case '1':
            {
                system("cls");
                MergeSort(Head, 1, "nama");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '2':
            {
                system("cls");
                MergeSort(Head, 1, "umur");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '3':
            {
                system("cls");
                MergeSort(Head, 1, "tinggi");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '0':
            {
                break;
            }

            default:
            {
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto sorting;
            }
            }
        }
        else if (pilihan == 2)
        {
            switch (pilih)
            {
            case '1':
            {
                system("cls");
                MergeSort(Head, 2, "nama");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '2':
            {
                system("cls");
                MergeSort(Head, 2, "umur");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '3':
            {
                system("cls");
                MergeSort(Head, 2, "tinggi");
                lihatdata(*Head, *Tail, "forward");
                getch();
                system("cls");
                goto sorting;
            }
            case '0':
            {
                break;
            }

            default:
            {
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto sorting;
            }
            }
        }
    }

    else if(arah == "backward")
    {
        if (pilihan == 1)
        {
            switch (pilih)
            {
            case '1':
            {
                system("cls");
                MergeSort(Head, 1, "nama");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '2':
            {
                system("cls");
                MergeSort(Head, 1, "umur");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '3':
            {
                system("cls");
                MergeSort(Head, 1, "tinggi");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '0':
            {
                break;
            }

            default:
            {
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto sorting;
            }
            }
        }
        else if (pilihan == 2)
        {
            switch (pilih)
            {
            case '1':
            {
                system("cls");
                MergeSort(Head, 2, "nama");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '2':
            {
                system("cls");
                MergeSort(Head, 2, "umur");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '3':
            {
                system("cls");
                MergeSort(Head, 2, "tinggi");
                lihatdata(*Head, *Tail, "backward");
                getch();
                system("cls");
                goto sorting;
            }
            case '0':
            {
                break;
            }

            default:
            {
                cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
                getch();
                goto sorting;
            }
            }
        }
    }
}

void tampilan_arah(Node **Head, Node **Tail)
{
arahan:
    cout << "\n================================ LIHAT DATA ANGGOTA ================================";
    cout << "\n================================== LIHAT SECARA ===================================\n";
    cout << "1. Forward"    << endl;
    cout << "2. Backward\n" << endl;
    cout << "0. Exit"       << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
    case '1':
    {
        system("cls");
        tampilan_urutan_sorting(Head, Tail, "forward");
        break;
    }
    case '2':
    {
        system("cls");
        tampilan_urutan_sorting(Head, Tail, "backward");
        break;
    }
    case '0':
    {
        break;
    }

    default:
    {
        cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
        getch();
        system("cls");
        goto arahan;
    }
    }
}

void tampilan_urutan_sorting(Node **Head, Node **Tail, string arah)
{
sorting:
    cout << "\n================================ SORTING DATA ANGGOTA ================================";
    cout << "\n================================== SORTING SECARA ===================================\n";
    cout << "1. Ascending" << endl;
    cout << "2. Descending\n"
         << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();

    if(arah == "forward")
    {
        switch (pilih)
        {
        case '1':
        {
            system("cls");
            tampilan_sorting(Head, Tail, 1, "forward");
            break;
        }
        case '2':
        {
            system("cls");
            tampilan_sorting(Head, Tail, 2, "forward");
            break;
        }
        case '0':
        {
            break;
        }

        default:
        {
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            system("cls");
            goto sorting;
        }
        }
    }

    else if(arah == "backward")
    {
        switch (pilih)
        {
        case '1':
        {
            system("cls");
            tampilan_sorting(Head, Tail, 1, "backward");
            break;
        }
        case '2':
        {
            system("cls");
            tampilan_sorting(Head, Tail, 2, "backward");
            break;
        }
        case '0':
        {
            break;
        }

        default:
        {
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            system("cls");
            goto sorting;
        }
        }
    }
}

void tampilan_pilihan_searching(Node **Head, Node **Tail)
{
searching:
    cout << "\n===================================== SEARCHING DATA ANGGOTA =====================================";
    cout << "\n===================================== SEARCHING BERDASARKAN ======================================\n";
    cout << "1. Nama Anggota" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
    case '1':
    {
        system("cls");
        tampilan_searching(Head, Tail);
        break;
    }
    case '0':
    {
        break;
    }

    default:
    {
        cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
        getch();
        goto searching;
    }
    }
}

void tampilan_searching(Node **Head, Node **Tail)
{
    MergeSort(Head, 1, "nama");
searching:
    cout << "\n=================================== SEARCHING DATA ANGGOTA ===================================";
    cout << "\n===================================== INPUT NAMA ANGGOTA =====================================\n";
    cout << "Masukan nama anggota yang ingin dicari : ";
    getline(cin, Nama);
    fflush(stdin);
    int ind = fibonacciSearch(*Head, Nama, jumlah(*Head));
    if (ind >= 0)
        cout << "Data ditemukan pada index : " << ind;
    else
        cout << Nama << " tidak ada dalam Linked List";

apa:
    // Untuk menanyakan user apakah ingin mengedit data lagi
    cout << "\nApakah anda ingin mencari data kembali ? (Y / T) : " << endl;
    tanya = getch();
    switch (tanya)
    {
    case ('y'):
    case ('Y'):
        system("cls");
        goto searching;

    case ('t'):
    case ('T'):
        break;

    // Untuk kesalahan dalam memilih
    default:
        cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
        getch();
        goto apa;
    }
}
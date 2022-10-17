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

struct anggota data_anggota; // Untuk mendeklarasikan sebuah  struct data yang bernama data_anggota

int a, b, c, i, j, pilih, pilihan, middle, hapus; // Untuk keperluan pertambahan indeks array, nomor, pilihan, dan perulangan

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
Node *Merge(Node *h1, Node *h2, int pilihan, string attribut);
void MergeSort(Node **head, int pilihan, string attribut);
void tampilan_sorting(Node **Head, int array[], int pilihan);
void tampilan_urutan_sorting(Node **Head, int array[]);

// Fungsi utama
int main()
{
    Node *Head = NULL;
    int arr[jumlah(Head)];

// Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
awal:
    system("cls");
    system("color 3F");
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
            inputdata_first(&Head);
            goto awal;
        }
    case '2':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            inputdata_middle(&Head);
            getch();
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
            tampilan_urutan_sorting(&Head, arr);
            system("cls");
            goto awal;
        }
    case '5':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            editdata(&Head);
            getch();
            system("cls");
            goto awal;
        }
    case '6':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata_first(&Head);
            getch();
            system("cls");
            goto awal;
        }
    case '7':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata_middle(&Head);
            getch();
            system("cls");
            goto awal;
        }
    case '8':
        // goto yang berfungsi untuk melompat ke baris label
        {
            system("cls");
            hapusdata_last(&Head);
            getch();
            system("cls");
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

// Menghitung panjang Node
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
void inputdata_first(Node **Head)
{
    Node *NodeBaru = new Node;

    system("color 3F");
    cout << "Nama Anggota\t\t\t\t: ";
    getline(cin, NodeBaru->data.nama);
    fflush(stdin);
    cout << "Jenis Kelamin (L / P)\t\t\t: ";
    cin >> NodeBaru->data.kelamin;
    fflush(stdin);
    cout << "Tinggi Badan\t\t\t\t: ";
    cin >> NodeBaru->data.tinggi;
    fflush(stdin);
    cout << "Berat Badan\t\t\t\t: ";
    cin >> NodeBaru->data.berat;
    fflush(stdin);
    cout << "Umur\t\t\t\t\t: ";
    cin >> NodeBaru->data.umur;
    fflush(stdin);

    NodeBaru->next = *Head;
    *Head = NodeBaru;

    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}

void inputdata_middle(Node **Head)
{
    middle = 0;

    if (*Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
    apa:
        lihatdata(*Head);
        cout << "\n\n\t\t\t\tPilih letak Tambah Data : ";
        cin >> middle;
        fflush(stdin);
        Node *temp = *Head;
        Node *NodeBaru = new Node;

        if (middle > 1 && middle < jumlah(*Head))
        {
            for (int i = 1; i < jumlah(*Head); i++)
            {
                if (i == middle - 1)
                {
                    system("color 3F");
                    cout << "Nama Anggota\t\t\t\t: ";
                    getline(cin, NodeBaru->data.nama);
                    fflush(stdin);
                    cout << "Jenis Kelamin (L / P)\t\t\t: ";
                    cin >> NodeBaru->data.kelamin;
                    fflush(stdin);
                    cout << "Tinggi Badan\t\t\t\t: ";
                    cin >> NodeBaru->data.tinggi;
                    fflush(stdin);
                    cout << "Berat Badan\t\t\t\t: ";
                    cin >> NodeBaru->data.berat;
                    fflush(stdin);
                    cout << "Umur\t\t\t\t\t: ";
                    cin >> NodeBaru->data.umur;
                    fflush(stdin);

                    NodeBaru->next = temp->next;
                    temp->next = NodeBaru;

                    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
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

void inputdata_last(Node **Head)
{
    Node *NodeBaru = new Node;

    system("color 3F");
    cout << "Nama Anggota\t\t\t\t: ";
    getline(cin, NodeBaru->data.nama);
    fflush(stdin);
    cout << "Jenis Kelamin (L / P)\t\t\t: ";
    cin >> NodeBaru->data.kelamin;
    fflush(stdin);
    cout << "Tinggi Badan\t\t\t\t: ";
    cin >> NodeBaru->data.tinggi;
    fflush(stdin);
    cout << "Berat Badan\t\t\t\t: ";
    cin >> NodeBaru->data.berat;
    fflush(stdin);
    cout << "Umur\t\t\t\t\t: ";
    cin >> NodeBaru->data.umur;
    fflush(stdin);

    if (*Head == NULL)
    {
        *Head = NodeBaru;
    }
    else
    {
        Node *temp = *Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NodeBaru;
    }

    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}

// Prosedur untuk lihat data
void lihatdata(Node *Head)
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
        cout << "\n============================================================= Menampilkan Data =======================================================================\n\n";
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
}

void editdata(Node **Head) // Prosedur untuk edit data
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
        lihatdata(*Head);
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
                cout << "\n============================================================ Data berhasil diedit ============================================================\n";
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
            break;

        // Untuk kesalahan dalam memilih
        default:
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
            getch();
            goto apaa;
        }
    }
}

// Prosedur untuk hapus data
void hapusdata_first(Node **Head)
{
    if (*Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
        *Head = (*Head)->next;
        system("color 3F");
        cout << "\n============================================================ Data berhasil dihapus ============================================================\n";
        lihatdata(*Head);
    }
}

// Prosedur untuk hapus data
void hapusdata_middle(Node **Head)
{
    hapus = 0;

    if (*Head == NULL)
    {
        cout << "\n===================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
    apa:
        lihatdata(*Head);
        system("color 3F");
        cout << "\n\nPilih letak data yang ingin dihapus: ";
        cin >> hapus;
        fflush(stdin);
        Node *temp = *Head;

        if (hapus > 1 && hapus < jumlah(*Head))
        {
            for (int i = 1; i < jumlah(*Head); i++)
            {
                if (i == hapus - 1)
                {
                    break;
                }
                temp = temp->next;
            }
            temp->next = temp->next->next;
            cout << "\n================================================================ Data berhasil dihapus ===============================================================\n";
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
void hapusdata_last(Node **Head)
{
    if (*Head == NULL)
    {
        cout << "\n=============================== LinkedList Kosong  =====================";
        return;
    }
    else
    {
        Node *temp = *Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Node *deleteNode = temp->next;
        temp->next = NULL;
        delete deleteNode;

        system("color 3F");
        cout << "\n============================================================ Data berhasil dihapus ============================================================\n";
        getch();
        lihatdata(*Head);
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
        if(pilihan == 1)
        {
            // If the data value is lesser than the head of first list add that Node at the beginning.
            if(attribut == "umur")
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

            else if(attribut == "tinggi")
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
        }   

        else if(pilihan == 2)
        {
            // If the data value is lesser than the head of first list add that Node at the beginning.
            if(attribut == "umur")
            {
                if (h1->data.umur < t2->data.umur)
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
                    else if ((t1->next)->data.umur >= t2->data.umur)
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

            else if(attribut == "tinggi")
            {
                if (h1->data.tinggi < t2->data.tinggi)
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
                    else if ((t1->next)->data.tinggi >= t2->data.tinggi)
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

    if(pilihan == 1)
    {
        if(attribut == "umur")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "umur");
            MergeSort(&second, 1, "umur");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 1, "umur");            
        }

        else if(attribut == "tinggi")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 1, "tinggi");
            MergeSort(&second, 1, "tinggi");
        
            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 1, "umur");        
        }
    }

    else if(pilihan == 2)
    {
        if(attribut == "umur")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 2, "umur");
            MergeSort(&second, 2, "umur");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 2, "umur");
        }

        else if(attribut == "tinggi")
        {
            // Implementing divide and conquer approach.
            MergeSort(&first, 2, "tinggi");
            MergeSort(&second, 2, "tinggi");

            // Merge the two part of the list into a sorted one.
            *head = Merge(first, second, 2, "tinggi");
        }
    }
}


// prosedur untuk tampilan sorting dengan urutan secara asceding
void tampilan_sorting(Node **Head, int array[], int pilihan)
{
sorting:
    cout << "\n================================ SORTING DATA ANGGOTA ================================";
    cout << "\n================================== PILIHAN SORTING ===================================\n";
    cout << "1. Mengurutkan umur anggota" << endl;
    cout << "2. Mengurutkan tinggi anggota\n" <<  endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    if(pilihan == 1)
    {
        switch (pilih)
        {
        case '1':
        {
            system("cls");
            MergeSort(Head, 1, "umur");
            lihatdata(*Head);
            getch();
            system("cls");
            goto sorting;
        }
        case '2':
        {
            system("cls");
            MergeSort(Head, 1, "tinggi");
            lihatdata(*Head);
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
    else if(pilihan == 2)
    {
        switch (pilih)
        {
        case '1':
        {
            system("cls");
            MergeSort(Head, 2, "umur");
            lihatdata(*Head);
            getch();
            system("cls");
            goto sorting;
        }
        case '2':
        {
            system("cls");
            MergeSort(Head, 2, "tinggi");
            lihatdata(*Head);
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

void tampilan_urutan_sorting(Node **Head, int array[])
{
sorting:
    cout << "\n================================ SORTING DATA ANGGOTA ================================";
    cout << "\n================================== SORTING SECARA ===================================\n";
    cout << "1. Ascending" << endl;
    cout << "2. Descending\n" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukan Pilihan anda : ";
    pilih = getch();
    switch (pilih)
    {
        case '1':
        {
            system("cls");
            tampilan_sorting(Head, array, 1);
            break;
        }
        case '2':
        {
            system("cls");
            tampilan_sorting(Head, array, 2);
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
            goto sorting;
        }
    }
}
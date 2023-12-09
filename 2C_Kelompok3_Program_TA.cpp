#include <iostream>//header untuk input output
#include <conio.h>//header untuk menampilkan hasil antar pengguna dan memanggil getch
#include <stdlib.h>//header untuk operasi pembanding dan konversi
#define MAX 20 // Antrian maksimal di restoran ini

using namespace std; //header untuk cout,cin supaya tidak cout::

//Deklarasi variabel pada program
int nomer[MAX];
int tail=-1;
int head=-1;

bool IsEmpty(){ // Fungsi untuk mengecek apakah antrian kosong atau tidak
   if(tail == -1){ //Jika tail bernilai -1 maka antrian kosong
       return true; //Mengembalikan nilai true, yang berarti benar bahwa antrian kosong
   }else{ //Jika nilai tail tidak sama dengan -1 maka antrian tidak kosong			
       return false; //Sehingga mengembalikan nilai false
   }
}

bool IsFull(){ // Fungsi untuk mengecek apakah antrian sudah penuh atau belum berdasarkan jumkah maksimal antrian
   if(tail == MAX-1){ //Jika nilai tail MAX-1 maka array sudah penuh, karena dalam array index dimulai dari 0 sehingga index terakhirnya MAX-1
       return true; //Mengembalikan nilai true
   }else{ //Jika nilai tail tidak sama dengan MAX-1 maka antrian belum penuh
       return false; //Sehingga mengembalikan nilai false
   }
}

void AntrianMasuk(int no){ //Fungsi untuk memasukkan data antrian baru
    if (IsEmpty()){ //Kondisi untuk mengecek apakah antrian kosong dengan memanggil fungsi  IsEmpty()
        head=tail=0; //Menginisialisasi nilai head dan tail menjadi 0 akan menambah antrian
    }else {
        tail++; //kalau tidak kosong akan mengalihkan kesini
    }
    nomer[tail]=no;
}


void AntrianKeluar(){ //Fungsi untuk mengeluarkan data dari antrian jika terdapat meja yang kosong
    if(IsEmpty()){ //Kondisi untuk mengecek apakah antrian kosong dengan memanggil fungsi  IsEmpty()
        cout<<"Tidak ada antrian! "; //Jika antrian kososng maka cetak "Tidak ada antrian!"
        getch();
    }else { //Kondisi jika antrian tidak kosong
        for(int a=head;a<tail;a++){ //Perulangan untuk menggeser data antrian dibelakang antrian yang dikeluarkan 
            nomer[a]=nomer[a+1]; //Setiap data antrian maju satu ke depan
        }
        tail--; //decrement index
        if(tail == -1){
            head = -1;
        }
    }
}

void Clear(){ //Fungsi untuk mengosongkan antrian
     head=tail=-1; //Menginisialisasi nilai head dan tail menjadi -1 akan mengosongkan antrian
}

void Display(){ //Fungsi untuk menampilkan daftar antrian
     if(IsEmpty()){ //Kondisi untuk mengecek apakah antrian kosong
         cout<<"Antrian sedang kosong ! "; //Cetak "Andtrian sedang kosong !" jika antrian kosong

     }else { //Kondisi jika antrian tidak kosong
         system("cls");
         for(int a=head;a<=tail;a++){ //Perulangan untuk menampilkan semua data antrian
              cout << "==============================="
                   << "\n >> No. Antri : [" << nomer[a] << "]"
                   << "\n==============================="<< endl;
         }
     }
}

int main(){ //Fungsi main untuk menampilkan menu utama program
    system("color 79"); //Memberi warna pada program
    int choose; //Deklarasi variabel untuk pilihan menu
	int p=1; //Deklarasi variabel sebagai initial value dari antrian
	int noUrut; //Deklarasi variabel untuk urutan antrian
    do{ 
        system("cls");
        cout << "\n\n===== PROGRAM ANTRIAN PEMESANAN MEJA RESTORAN C++ ====="
             << "\n========================================================="
             << "\n|1. Tambah Antrian Baru                                 |"
             << "\n|2. Panggil dan Keluarkan Antrian                       |"
             << "\n|3. Lihat Daftar Antrian                                |"
             << "\n|4. Kosongkan Antrian                                   |"
             << "\n|5. Keluar                                              |"
             << "\n=========================================================";
        cout << "\nPilih Menu : "; cin >> choose; //Input menu yang dipilih pada program
        cout << "\n\n";
        if(choose == 1){ //Kondisi jika memilih nomor 1
            if(IsFull()) { // Sebelum memasukkan antrian baru akan dicek apakah antrian penuh
                cout<<"Antrian sudah penuh, mohon tunggu beberapa saat lagi "; //Jika penuh akan ditampilkan pesan berikut
            }
            else{ //Kondisi jika antrian tidak penuh
                noUrut=p; //inisialisasi nomor urut dengan nilai p
                AntrianMasuk(noUrut); //Memanggil fungsi untuk menambahkan data ke daftar antrian baru
                cout << "---------------------------------" << endl;
                cout << "|          NO. ANTRIAN          |" << endl;
                cout << "|               " << p << "              ||" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Silahkan Mengantri      |" << endl;
                cout << "|      Menunggu " << tail << " Antrian      ||" << endl;
                cout << "---------------------------------" << endl;
                p++; // Increment p agar nomor antrian naik/bertambah 1 jika ada antrian baru
            }
        }
        else if(choose == 2){ //Kondisi jika memilih nomor 2
            cout << "=================================" << endl;
            cout << "No. Antri : [" << nomer[head] << "]";
            cout << "\n=================================" << endl;
            AntrianKeluar(); //Memanggil fungsi untuk mengeluarkan data dari antrian
            cout << "Anda mendapatkan meja !" << endl; //Mencetak pesan bahwa pelanggan sudah mendapatkan meja
        }
        else if(choose == 3){ //Kondisi jika memilih nomor 3
            Display(); //Memanggil fungsi untuk menampilkan semua data pada daftar antrian
        }
        else if(choose == 4){ //Kondisi jika memilih nomor 4
            Clear(); //Memanggil fungsi untuk mengosongkan antrian
            cout<<"Antrian berhasil dikosongkan ! "; //Menampilkan pesan bahwa antrian telah dikosongkan
        }
        else if(choose == 5){ //Kondisi jika memilih nomor 5 paka program akan dihentikan
        }
        else{ //Kondisi jika memilih nomor selain yang ada di menu
            cout << "Masukan anda salah ! \n"<< endl; //Menampilkan pesan bahwa input salah 
        }
        getch();
    }while(choose!=5); //Kondisi dimana program akan terus berjalan jika menu yang dipilih bukan nomor 5 (menu keluar)
}
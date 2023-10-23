#include "SLL.h"

int main()
{
    List L;
    adr P;
    int pilihan = 0; // Jika 0 maka Exit atau while berhenti.
    int n;

    string data;

    pilihan = selectMenu_1301223088();
    createList_1301223088(L);
    while (pilihan != 0) {
        if (pilihan == 1) {

            cout << "Jumlah data yang ditambahkan : ";
            cin >> n;
            int i = 0;

            while (i < n) {
                cout << "Masukkan data baru : ";
                cin >> data;

                P = createElement_1301223088(data);
                insertLast_1301223088(L, P);
                i++;
            }

            char pilihcase1;
            //melakukan repeat-until ketika inputan salah
            do {
                cout << "Kembali ke menu utama? (Y/N) : ";
                cin >> pilihcase1;

                if (pilihcase1 == 'Y' || pilihcase1 == 'y') {
                    cout << endl;
                    cout << "*Data berhasil diperbaharui*";
                    cout << endl;
                    pilihan = selectMenu_1301223088();
                } else if (pilihcase1 == 'N' || pilihcase1 == 'n') {
                    while (i > 0) {
                        deleteFirst_1301223088(L, P);
                        i--;
                    }
                    pilihan = 1;
                } else {
                    cout << "*Inputan anda SALAH*" << endl;
                }
            } while (pilihcase1 != 'Y' && pilihcase1 != 'N' && pilihcase1 != 'y' && pilihcase1 != 'n');

        } else if (pilihan == 2) {
            if (first(L) == NULL) {
                cout << "*Belum ada data* " << endl;
                pilihan = selectMenu_1301223088();
            } else {
                cout << "Data anda adalah :" << endl;
                showData_1301223088(L);
                pilihan = selectMenu_1301223088();
            }
        } else if (pilihan == 3) {
            if (first(L) == NULL) {
                cout << "*Belum ada data* " << endl;
                pilihan = selectMenu_1301223088();
            } else  {
                adr Long = longestName_1301223088(L);
                cout << "Nama yang terpanjang adalah : " << info(Long) << endl;
                pilihan = selectMenu_1301223088();
            }

        } else if (pilihan == 4) {
            if (first(L) == NULL) {
                cout << "*Belum ada data*" << endl;
                pilihan = selectMenu_1301223088();
            } else {
                 cout << "Masukkan jumlah data : ";
                int x;
                cin >> x;

                cout << "Masukkan huruf yang dicari : ";
                char huruf;
                cin >> huruf;

                showFirstKNameC_1301223088(L, x, huruf);

                pilihan = selectMenu_1301223088();
            }

        } else {
            cout << "Inputan anda salah";
            pilihan = selectMenu_1301223088();
        }
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    return 0;
}

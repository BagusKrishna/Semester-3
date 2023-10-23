#include "SLL.h"

int selectMenu_1301223088(){
    cout << endl;
    cout << "===== MENU =====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data baru" << endl;
    cout << "3. Menampilkan nama terpanjang" << endl;
    cout << "4. Menampilkan nama awalan pengunjung " << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu : ";

    int pilih;
    cin >> pilih;
    cout << endl;
    return pilih;
}

void createList_1301223088(List &L){
    first(L) = NULL;
}
adr createElement_1301223088(infotype x){
    adr P = new elmlist;
    info(P) = x;
    next(P) = NULL;

    return P;
}
void insertLast_1301223088(List &L, adr P){
    adr Q = first(L);
    if (first(L) == NULL){
        next(P) = first(L);
        first(L) = P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    }
}

void deleteFirst_1301223088(List &L, adr &P){
    P = first(L);
    if (P != NULL){
        first(L) = next(P);
        next(P) = NULL;
    }
}

void showData_1301223088(List L){
    adr P = first(L);
    int i = 1;
    while (P != NULL) {
        cout << i << "." << info(P) << endl;
        i++;
        P = next(P);
    }
    cout << endl;
}

adr longestName_1301223088(List L){
    adr Long = first(L), Q = first(L);

    if (first(L) == NULL) {
        next(Long) = first(L);
        first(L) = Long;
    } else {
        while (Q != NULL) {
            if (Q->info.length() > Long->info.length()){
                Long = Q;
            }
            Q = next(Q);
        }
    }
    return Long;
}
void showFirstKNameC_1301223088(List L, int k, char c) {
    int count = 0;
    int i = 1;
    adr P = first(L);
    cout << endl;


    cout << "Nama yang berawalan " << c <<  ": " <<endl;
    while (P != NULL && count < k) {
        if (P->info[0] == c) {
            cout << i << "." << info(P) << endl;
            count++;
            i++;
        }
        P = next(P);
    }

    if (count == 0) {
        cout << endl;
        cout << "Tidak ada data yang ditemukan "<< endl;
    }
}



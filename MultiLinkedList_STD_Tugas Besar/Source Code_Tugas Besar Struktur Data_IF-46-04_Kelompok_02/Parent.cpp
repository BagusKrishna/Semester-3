#include "Parent.h"

void createListMhs(List_mhs &L){
    first(L) = NULL;
}
//insert data parent (point 1)

void insertLastMhs(List_mhs &L, adr_mhs P){
    adr_mhs Q;
    if(first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    } else {
        Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

//hapus data parent
void deleteFirstMhs(List_mhs &L, adr_mhs &P){
    if (next(first(L)) == first(L)){ //kalo ada 1 elemen
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    } else { //kalo banyak
        adr_mhs Q = first(L);
        P = first(L);
        while (next(Q) != first(L)){
            Q = next(Q); //cari last;
        }
        next(Q) = next(first(L));
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLastMhs(List_mhs &L, adr_mhs &P){
    if (next(first(L)) == first(L)){ //kalo ada 1 elemen
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    } else { //kalo banyak
        adr_mhs Q = first(L);

        while (next(next(Q)) != first(L)){
            Q = next(Q); //cari last;
        }
        P = next(Q);
        next(Q) = first(L);
        next(P) = NULL;
    }
}
void deleteAfterMhs(List_mhs &L, adr_mhs Prec, adr_mhs &P){
    if (next(first(L)) == first(L)){ //kalo ada 1 elemen
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    } else { //kalo banyak

        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void deleteDataMhs(List_mhs &LM, string namaMhs ){

    adr_mhs M = findMhsByNama(LM,namaMhs);

    if (M == NULL){
        cout << "+----------------------------------+" << endl;
        cout << "|      *DATA TIDAK DITEMUKAN*     |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();
    } else {
        if (M == first(LM)){
            deleteFirstMhs(LM, M);
        }else if (next(M) == first(LM)){
            deleteLastMhs(LM, M);
        }else{
            adr_mhs Prec = first(LM);
            while (next(Prec) != M){
                Prec = next(Prec);
            }
            deleteAfterMhs(LM, Prec, M);
        }
        cout << "+----------------------------------+" << endl;
        cout << "|      *DATA BERHASIL DIHAPUS*     |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << endl;
        cout << "~Press any key" << endl;
        _getch();
    }
}

bool isEmptyMhs(List_mhs LM) {
    return first(LM) == NULL;
}
//show all data parent (point 2)
void printInfoMhs(List_mhs L){
    adr_mhs P = first(L);
    int j = 1;
    if (P != NULL) {
        do {
            cout << "+--------------------------------+" << endl;
            cout << "|       *DATA MAHASISWA " << j << "*"  << setw(27) << left;
            cout << setw(8) << right << "|" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| Nama       : " << setw(17) << left << info(P).nama << " |" << endl;
            cout << "| NIM        : " << setw(17) << left << info(P).nim << " |" << endl;
            cout << "| Umur       : " << setw(17) << left << info(P).umur << " |" << endl;
            cout << "| Semester   : " << setw(17) << left << info(P).semester << " |" << endl;
            cout << "| IPK        : " << setw(17) << left << info(P).ipk << " |" << endl;
            cout << "+--------------------------------+" << endl;


            bool adaPrestasi = false; //buat cek prestasi
            for (int i = 0; i < 10; i++) {
                if (!info(P).prestasi[i].empty()) {
                    adaPrestasi = true;
                    cout << "| Prestasi " << i + 1 << " : " << setw(17) << left << info(P).prestasi[i] << " |" << endl;
                }
            }
            //pembatas bawah kalo ada prestasi
            if (adaPrestasi){
                cout << "+--------------------------------+" << endl;
            }
            P = next(P);
            j++;

        } while (P != first(L));

    } else {
        cout << "+----------------------------------+" << endl;
        cout << "|         *TIDAK ADA DATA *        |" << endl;
        cout << "+----------------------------------+" << endl;

    }
}

//cari data parent (point 4)
adr_mhs findMhs(List_mhs L, string nimMhs){
    adr_mhs P = first(L);
    do {
        if(info(P).nim == nimMhs){
            return P;
        }
        P = next(P);
    } while (P != first(L));

    return NULL;
}

adr_mhs findMhsByNama(List_mhs L, string namaMhs){
    adr_mhs P = first(L);
    do {
        if(info(P).nama == namaMhs){
            return P;
        }
        P = next(P);
    } while (P != first(L));

    return NULL;
}

adr_mhs alokasiMhs(infotype_mhs x){
    adr_mhs P = new elmlist_mhs;
    info(P) = x;
    next(P) = NULL;
    firstRelasi(P) = NULL;
    return P;
}
void dealokasiMhs(adr_mhs &P){
    delete P;
}

adr_relasi findElmRelasi(List_mhs L, string namaOrg){
    adr_mhs M = first(L);
    bool found;
    adr_relasi R;
    while (M != NULL && !found){
        R = firstRelasi(M);
        while(R != NULL && info(nextChild(R)).nama != namaOrg){
            R = nextRelasi(R);
        }
        if (R != NULL){
            found = true;
        }
        M = next(M);
    }
    return R;
}

bool isConnected(List_mhs LM, List_org LO, string namaMhs, string namaOrg){
    adr_mhs M = findMhsByNama(LM, namaMhs);

    adr_relasi temp = firstRelasi(M);
    while (temp != NULL && info(nextChild(temp)).nama != namaOrg){
        temp = nextRelasi(temp);
    }

    if (temp != NULL){
        return true;
    }
    return false;
}

void connectRelasi(List_mhs &LM, List_org &LO){
    adr_relasi R = createElmRelasi();
    string namaOrg, namaMhs;
    cout << "Masukkan NAMA Mahasiswa  : "; cin >> namaMhs;
    cout << "Masukkan NAMA Organisasi : "; cin >> namaOrg;

    //search adr child yang mau di connect;
    //search parent
    adr_org cariOrg = findOrg(LO, namaOrg);
    adr_mhs M = findMhsByNama(LM, namaMhs);

    if (cariOrg == NULL || M == NULL){
        if (cariOrg == NULL && M == NULL){
            cout << "+--------------------------------+" << endl;
            cout << "|       DATA TIDAK DITEMUKAN     |" << endl;
            cout << "+--------------------------------+" << endl;

        } else if (M == NULL) {
            cout << "+---------------------------------+" << endl;
            cout << "|  DATA MAHASISWA TIDAK DITEMUKAN |" << endl;
            cout << "+---------------------------------+" << endl;

        } else {
            cout << "+---------------------------------+" << endl;
            cout << "| DATA ORGANISASI TIDAK DITEMUKAN |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "~Press any key" << endl;
            _getch();

        }
        cout << "~Press any key" << endl;
        _getch();

    } else if (isConnected(LM,LO,namaMhs,namaOrg)){
            cout << "+---------------------------------+" << endl;
            cout << "|      DATA SUDAH TERKONEKSI      |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "~Press any key" << endl;
            _getch();
    } else {
        if (firstRelasi(M) == NULL){ //parent tidak memiliki relasi
            firstRelasi(M) = R;
            nextChild(R) = cariOrg;
            nextRelasi(R) = NULL;
        } else { //kalau elemen relasi sudah ada
            adr_relasi last = firstRelasi(M);

            //cari last element
            while (nextRelasi(last) != NULL){
                last = nextRelasi(last);
            }

            nextRelasi(last) = R;
            nextChild(R) = cariOrg;
            nextRelasi(nextRelasi(last)) = NULL;
        }
        info(cariOrg).jumlah_anggota++;

        cout << "+-------------------------------+" << endl;
        cout << "|   *DATA BERHASIL TERKONEKSI*  |" << endl;
        cout << "+-------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();
    }

}


void disconnectRelasi(List_mhs &LM, List_org &LO, string namaMhs, string namaOrg){

    //search adr child yang mau di connect;
    adr_org cariOrg = findOrg(LO, namaOrg);
    //search parent
    adr_mhs M = findMhsByNama(LM, namaMhs);

    if (cariOrg == NULL || M == NULL){
        if (cariOrg == NULL && M == NULL){
            cout << "+--------------------------------+" << endl;
            cout << "|       DATA TIDAK DITEMUKAN     |" << endl;
            cout << "+--------------------------------+" << endl;

        } else if (M == NULL) {
            cout << "+---------------------------------+" << endl;
            cout << "|  DATA MAHASISWA TIDAK DITEMUKAN |" << endl;
            cout << "+---------------------------------+" << endl;

        } else {
            cout << "+---------------------------------+" << endl;
            cout << "| DATA ORGANISASI TIDAK DITEMUKAN |" << endl;
            cout << "+---------------------------------+" << endl;

        }
        cout << "~Press any key" << endl;
        _getch();

    } else {
        adr_relasi R = findElmRelasi(LM, namaOrg);
        if (R != NULL) {
            deleteByValue_Relasi(M, R);
            cout << "+-------------------------------+" << endl;
            cout << "| *DATA BERHASIL TERDISCONNECT* |" << endl;
            cout << "+-------------------------------+" << endl;
            cout << "~Press any key" << endl;
            _getch();
        }
        info(cariOrg).jumlah_anggota--;
    }

}

void deleteByValue_Relasi(adr_mhs P, adr_relasi &R) {
    if (firstRelasi(P) == R) {
        R = firstRelasi(P);
        firstRelasi(P) = nextRelasi(R);
        nextRelasi(R) = NULL;
    } else {
        adr_relasi prec = firstRelasi(P);
        while (nextRelasi(prec) != NULL && nextRelasi(prec) != R) {
            prec = nextRelasi(prec);
        }

        if (nextRelasi(prec) == R) {
            deleteAfterRelasi(R, prec);
        }
    }
}

void showAllRelasi(List_mhs LM) {
    adr_mhs P = first(LM);
    bool adaOrganisasi = false;

    int j = 1;
    if (P != NULL) {
        do {
            cout << "+--------------------------------+" << endl;
            cout << "|       *DATA MAHASISWA " << j << "*"  << setw(27) << left;
            cout << setw(8) << right << "|" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| Nama        : " << setw(16) << left << info(P).nama << " |" << endl;
            cout << "| NIM         : " << setw(16) << left << info(P).nim << " |" << endl;
            cout << "| Umur        : " << setw(16) << left << info(P).umur << " |" << endl;
            cout << "| Semester    : " << setw(16) << left << info(P).semester << " |" << endl;
            cout << "| IPK         : " << setw(16) << left << info(P).ipk << " |" << endl;
            cout << "+--------------------------------+" << endl;


            bool adaPrestasi = false; //buat cek prestasi
            for (int i = 0; i < 10; i++) {
                if (!info(P).prestasi[i].empty()) {
                    adaPrestasi = true;
                    cout << "| Prestasi " << i + 1 << "  : " << setw(16) << left << info(P).prestasi[i] << " |" << endl;
                }
            }
            //pembatas bawah kalo ada prestasi
            if (adaPrestasi){
                cout << "+--------------------------------+" << endl;
            }

            //PRINT RELASI
            adr_relasi R = firstRelasi(P);
            int k = 1;
            while (R != NULL) {
                adaOrganisasi = true;
                cout << "| Organisasi " << k << " : " << setw(15) << left << info(nextChild(R)).nama << " |" << endl;
                R = nextRelasi(R);
                k++;
            }
            if (adaOrganisasi){
                cout << "+--------------------------------+" << endl;
                adaOrganisasi = false;
            }
            P = next(P);
            j++;

        } while (P != first(LM));

        cout << "~Press any key" << endl;
        _getch();

    } else {
        cout << "+----------------------------------+" << endl;
        cout << "|         *TIDAK ADA DATA *        |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();

    }

}

void showRelasiMhs(List_mhs L, string namaMhs){
    adr_mhs P = findMhsByNama(L, namaMhs);
    bool adaOrganisasi = false;
    adr_relasi R = firstRelasi(P);
    if (R != NULL){
        int k = 1;
        cout << "+--------------------------------+" << endl;
        while (R != NULL) {
            adaOrganisasi = true;
            cout << "| Organisasi " << k << " : " << setw(15) << left << info(nextChild(R)).nama << " |" << endl;
            R = nextRelasi(R);
            k++;
        }
        if (adaOrganisasi){
            cout << "+--------------------------------+" << endl;
            adaOrganisasi = false;
        }
    }else{
        cout << "+----------------------------------+" << endl;
        cout << "|         *TIDAK ADA DATA *        |" << endl;
        cout << "+----------------------------------+" << endl;
    }
}

void deleteAllRelasi(List_mhs &LM, adr_org O){
    adr_mhs P = first(LM);
    if (P != NULL) {
        do {
            adr_relasi R = firstRelasi(P);
            while (R != NULL) {
                if (nextChild(R) == O){
                    deleteByValue_Relasi(P, R);
                }
                R = nextRelasi(R);
            }
            P = next(P);
        } while (P != first(LM));

    } else {
        cout << "+----------------------------------+" << endl;
        cout << "|         *TIDAK ADA DATA *        |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();

    }

}

void deleteDataOrg(List_mhs &LM, List_org &LO, string namaOrg){
    adr_org cariOrg = findOrg(LO, namaOrg);
    if (cariOrg != NULL){
        if (cariOrg == first(LO)){
            deleteFirstOrg(LO, cariOrg);
        }else if (cariOrg == last(LO)){
            deleteLastOrg(LO, cariOrg);
        }else{
            deleteAfterOrg(LO, prev(cariOrg), cariOrg);
        }
        if (!isEmptyMhs(LM)){
            deleteAllRelasi(LM, cariOrg);
        }
        cout << "+----------------------------------+" << endl;
        cout << "|      *DATA BERHASIL DIHAPUS*     |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();

    }else{
        cout << "+----------------------------------+" << endl;
        cout << "|      *DATA TIDAK DITEMUKAN*      |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "~Press any key" << endl;
        _getch();
    }
}

int countMhs(List_mhs M){
    int totalElm = 0;
    adr_mhs temp = first(M);
    if (isEmptyMhs(M)){
        return 0;
    }else{
        do {
            totalElm++;
            temp = next(temp);
        }while (temp != first(M));

    }
    return totalElm;
}

int countOrgByMhs(List_mhs LM, adr_mhs M){
    int totalElm = 0;
    if (!isEmptyMhs(LM)){
        adr_relasi R = firstRelasi(M);
        while (R != NULL){
            totalElm++;
            R = nextRelasi(R);
        }
    }
    return totalElm;
}


int mainMenu(){
    int pilihan;
    cout << "+---------------------------------------+" << endl;
    cout << "|              *MENU UTAMA*             |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| 1 |  Insert Data Mahasiswa            |" << endl; //first,after,last
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 2 |  Insert Data Organisasi           |" << endl; //first,after,last
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 3 |  Show Data Mahasiswa              |" << endl; //Elemen parent, dan parent dengan relasi child
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 4 |  Show Data Organisasi             |" << endl; //list child
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 5 |  Hapus Data Mahasiswa             |" << endl; //beserta relasinya
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 6 |  Hapus Data Organisasi            |" << endl; //Hapus elemen child dan menghapus parent yang mempunyai child tersebut
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 7 |  Cari Data Mahasiswa              |" << endl; //berdasarkan nim
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 8 |  Cari Data Organisasi             |" << endl; //berdasarkan nama organisasi
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 9 |  Connect Mahasiswa-Organisasi     |" << endl; //Menghubungkan parent dgn child
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 10|  Disconnect Mahasiswa-Organisasi  |" << endl; //Elemen parent, dan parent dengan relasi child
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 11|  Count Element                    |" << endl; //Jumlah elemen parent, child, child pada parent tertentu
    cout << "+---+-----------------------------------+" << endl;
    cout << "| 0 |  Exit*                            |" << endl;
    cout << "+---+-----------------------------------+" << endl;
    cout << "PILIHAN ANDA : "; cin >> pilihan;
    cout << endl;
    return pilihan;
}

int subMenuShowMhs(){
    int pilihan;
    cout << "+----------------------------------+" << endl;
    cout << "|            *SUB-MENU*            |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|       *SHOW DATA MAHASISWA*      |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| 1 |  Show List Mahasiswa         |" << endl; // semua mahasiswa (tanpa organisasi)
    cout << "+---+------------------------------+" << endl;
    cout << "| 2 |  Show Relasi Mahasiswa 'x'   |" << endl; // semua relasi dari mahasiswa tertentu
    cout << "+---+------------------------------+" << endl;
    cout << "| 3 |  Show All Data Mahasiswa     |" << endl; // semuanya sama child
    cout << "+---+------------------------------+" << endl;
    cout << "| 0 |  Kembali*                    |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "PILIHAN ANDA : "; cin >> pilihan;
    cout << endl;
    return pilihan;
}

int subMenuCountElm(){
    int pilihan;
    cout << "+-------------------------------------+" << endl;
    cout << "|               *SUB-MENU*            |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "|            *COUNT ELEMENT*          |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "| 1 |  Total Mahasiswa                |" << endl; //total data dari list mahasiswa
    cout << "+---+---------------------------------+" << endl;
    cout << "| 2 |  Total Organisasi               |" << endl; //total data dari list organisasi
    cout << "+---+---------------------------------+" << endl;
    cout << "| 3 |  Jumlah Organisasi pada Mhs 'x' |" << endl; //Total organisasi yang diikuti parent x
    cout << "+---+---------------------------------+" << endl;
    cout << "| 0 |  Kembali*                       |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "PILIHAN ANDA : "; cin >> pilihan;
    cout << endl;
    return pilihan;
}

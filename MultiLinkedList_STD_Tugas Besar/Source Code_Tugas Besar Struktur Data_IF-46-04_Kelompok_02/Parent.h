#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

#include "Relasi.h"
#include "Child.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define firstRelasi(P) P->firstRelasi

struct infotype_mhs {
    string nama, nim;
    string prestasi[10];
    int umur, semester;
    float ipk;

};

typedef struct elmlist_mhs *adr_mhs;

struct elmlist_mhs {
    infotype_mhs info;
    adr_relasi firstRelasi;  //include dari header relasi
    adr_mhs next;
};

struct List_mhs {
    adr_mhs first;
};

void createListMhs(List_mhs &L);
//insert data parent (point 1)
void insertLastMhs(List_mhs &L, adr_mhs P);
//hapus data parent
void deleteFirstMhs(List_mhs &L, adr_mhs &P);
void deleteLastMhs(List_mhs &L, adr_mhs &P);
void deleteAfterMhs(List_mhs &L, adr_mhs Prec, adr_mhs &P);

//show all data parent (point 2)
void printInfoMhs(List_mhs L);

//hapus data parent beserta relasi (point 3)
void deleteDataMhs(List_mhs &L, string namaMhs);

//cari data parent (point 4)
adr_mhs findMhs(List_mhs L, string nimMhs);
adr_mhs findMhsByNama(List_mhs L, string namaMhs);

//menghubungkan data parent ke child (point 7)
void connectRelasi(List_mhs &LM, List_org &LO);

//show all parent beserta child (point 8)
void ShowData(List_mhs L);

//cari data child pada parent tertentu (point 9)
void showRelasiMhs(List_mhs L, string namaMhs);

//hapus data child pada parent tertentu beserta relasinya (point 10)
void disconnectRelasi(List_mhs &LM, List_org &LO, string namaMhs, string namaOrg);

//menghitung jumlah data child pada parent tertentu (point 11)
int countOrgByMhs(List_mhs LM, adr_mhs M);



//Tambahan Pribadi
adr_mhs alokasiMhs(infotype_mhs x);
void dealokasiMhs(adr_mhs &P);
bool isEmptyMhs(List_mhs LM);

adr_relasi findElmRelasi(List_mhs L, adr_org P);
bool isConnected(List_mhs LM, List_org LO, string namaMhs, string namaOrg);
void deleteByValue_Relasi(adr_mhs P, adr_relasi &R);

void deleteDataOrg(List_mhs &LM, List_org &LO, string namaOrg);
void deleteAllRelasi(List_mhs &LM, List_org &LO); //menghapus relasi yang childnya sudah dihapus

void showAllRelasi(List_mhs LM);
int countMhs(List_mhs M);

//menu
int mainMenu();
int subMenuShowMhs();
int subMenuCountElm();

#endif // PARENT_H_INCLUDED

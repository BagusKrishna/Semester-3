#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct infotype_org {
    string nama, jenis;
    int tahun_terbit, jumlah_anggota;

};

typedef struct elmlist_org *adr_org;

struct elmlist_org{
    infotype_org info;
    adr_org next;
    adr_org prev;
};

struct List_org{
    adr_org first;
    adr_org last;
};

//cari data child (point 5)
adr_org findOrg(List_org L, string namaOrg);

//insert data child (point 6)
void insertFirstOrg(List_org &L, adr_org P);
void insertLastOrg(List_org &L, adr_org P);

//delete data child
void deleteFirstOrg(List_org &L, adr_org &P);
void deleteLastOrg(List_org &L, adr_org &P);
void deleteAfterOrg(List_org &L, adr_org Prec, adr_org &P);

//tambahan Pribadi
void createListOrg(List_org &L);
void printInfoOrg(List_org L);
adr_org alokasiOrg(infotype_org x);
void dealokasiOrg(adr_org &P);
bool isEmptyOrg(List_org L);
int countOrg(List_org L);
#endif // CHILD_H_INCLUDED

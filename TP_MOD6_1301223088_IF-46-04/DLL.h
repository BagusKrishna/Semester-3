#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(p) (p)->next
#define info(p) (p)->info
#define prev(p) (p)->prev

using namespace std;
struct Lagu {
    string judul;
    string band;
};

typedef Lagu infotype;

typedef struct elmtList *adr;
struct elmtList {
    adr prev;
    adr next;
    infotype info;

};

struct List {
    adr first, last;
};


bool isEmpty_1301223088(List L);
adr createNewElmt_1301223088(infotype X);
void insertFirst_1301223088(List &L, adr P);
void insertAfter_1301223088(List &L, adr Prec, adr P);
void insertLast_1301223088(List &L, adr P);
void deleteFirst_1301223088(List &L, adr &P);
void deleteAfter_1301223088(List &L, adr Prec, adr &P);
void deleteLast_1301223088(List &L, adr &P);
void concat_1301223088(List L1, List L2, List &L3);
adr findLagu_1301223088(string judul, List L);
void removeLagu_1301223088(string judul, List &L);

void show_1301223088(List L);
void createList_1301223088(List &L);
void tambahData_1301223088(List &L);

#endif // DLL_H_INCLUDED

#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED
#include <iostream>

#define first(L) ((L).first)
#define next(P) (P)->next
#define info(P) (P)->info

using namespace std;

typedef string infotype;

typedef struct elmlist *adr;

struct elmlist {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void createList_1301223088(List &L);
adr createElement_1301223088(infotype x);
void insertLast_1301223088(List &L, adr P);
void showData_1301223088(List L);
void deleteFirst_1301223088(List &L, adr &P);

adr longestName_1301223088(List L);
void showFirstKNameC_1301223088(List L, int k, char c);

//menu
int selectMenu_1301223088();
char menuDataBaru_1301223088(int i, int n);

#endif // SLL_H_INCLUDED

#include <iostream>
#include "list.h"
using namespace std;

void createList_1301223088(List &L){
    first(L) = NULL;
}

address allocate_1301223088(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst_1301223088(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void insertLast_1301223088(List &L, address P){
    address Q = first(L);
      if (first(L) == NULL) {
        insertFirst_1301223088(L,P);
    } else {
         while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;
    }

}
void printInfo_1301223088(List L){
    address p = first(L);

    while (p != NULL){
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}

void insertAfter_1301223088(List &L, infotype searchValue, address P){
    address Prec = searchInfo_1301223088(L, searchValue);

    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    } else {

        cout << "Elemen dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }
}
void deleteFirst_1301223088(List &L, address &P){
    P = first(L);
    if (P != NULL){
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLast_1301223088(List &L, address &P){
      address Q = first(L);
    P = NULL;
    if (first(L) != NULL) {
        while (next(Q) != NULL) {
            P = Q;
            Q = next(Q);
        }
        if (P != NULL) {
            next(P) = NULL;
        } else {
            first(L) = NULL;
        }
    }
}
void deleteAfter_1301223088(List &L, address &Prec, address &P){
    P = next(Prec);
    if (P != NULL) {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
address searchInfo_1301223088(List L, infotype x){
    address p = first(L);
    while (p != NULL) {
        if (info(p) == x) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}

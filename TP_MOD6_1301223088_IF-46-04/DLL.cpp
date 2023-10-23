#include "dll.h"

bool isEmpty_1301223088(List L) {
    return (first(L) == NULL);
}

adr createNewElmt_1301223088(infotype X) {
    adr P = new elmtList;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst_1301223088(List &L, adr P) {
    if (isEmpty_1301223088(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter_1301223088(List &L, adr Prec, adr P) {
    if (Prec != NULL) {
        if (next(Prec) != NULL) {
            prev(next(Prec)) = P;
            next(P) = next(Prec);
        } else {
            last(L) = P;
        }
        next(Prec) = P;
        prev(P) = Prec;
    }
}

void insertLast_1301223088(List &L, adr P) {
    if (isEmpty_1301223088(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst_1301223088(List &L, adr &P) {
    P = first(L);
    if (P != NULL) {
        if (next(P) == NULL) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteAfter_1301223088(List &L, adr Prec, adr &P) {
    if (Prec != NULL) {
        P = next(Prec);
        if (P != NULL) {
            next(Prec) = next(P);
            if (next(P) != NULL) {
                prev(next(P)) = Prec;
            } else {
                last(L) = Prec;
            }
            next(P) = NULL;
            prev(P) = NULL;
            P = NULL;
        }
    }
}


void deleteLast_1301223088(List &L, adr &P) {
    P = last(L);
    if (P != NULL) {
        if (prev(P) == NULL) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            next(prev(P)) = NULL;
            prev(P) = NULL;
        }
    }
}

//menggabungkan 2 List (L1 + L2 = L3)
void concat_1301223088(List L1, List L2, List &L3) {
    createList_1301223088(L3);

    adr P1 = first(L1);
    adr P2 = first(L2);

    while (P1 != NULL) {
        insertLast_1301223088(L3, P1);
        P1 = next(P1);
    }

    while (P2 != NULL) {
        insertLast_1301223088(L3, P2);
        P2 = next(P2);
    }
}

adr findLagu_1301223088(string judul, List L) {
    adr P = first(L);
    while (P != NULL) {
        if (info(P).judul == judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void removeLagu_1301223088(string judul, List &L) {
    adr alamatlagu = findLagu_1301223088(judul, L);

    if (alamatlagu != NULL) {
        adr prec = prev(alamatlagu);
        adr nextLagu = next(alamatlagu);

        if (prec == NULL) {
            deleteFirst_1301223088(L, alamatlagu);
        }
        else if (nextLagu == NULL) {
            deleteLast_1301223088(L, alamatlagu);
        }
        else {
            deleteAfter_1301223088(L, prec, alamatlagu);
        }

        delete alamatlagu;
    } else {
        cout << "Lagu tidak ditemukan" << endl;
    }
}

void show_1301223088(List L){
    adr P = first(L);
    if (isEmpty_1301223088(L)){
        cout << "List kosong.\n";
    } else {
        while (P != NULL){
            cout << "Judul: "<< info(P).judul << endl;
            cout << "Nama band:" << info(P).band << endl;
            P = next(P);
        }

    }
    cout << endl;
}

void createList_1301223088(List &L){
    first(L) = NULL;
    last(L) = NULL;
}

void tambahData_1301223088(List &L){
    int n, i;
    infotype Data;
    adr Element;

    cout << "Masukkan jumlah data : "; cin >> n;

    i = 1;
    while (i <= n){
        cout << i << endl;
        cout << "Judul Lagu : "; cin >> Data.judul;
        cout << "Nama Band : "; cin >> Data.band;

        Element = createNewElmt_1301223088(Data);
        insertLast_1301223088(L,Element);
        i++;
    }
    cout << endl;

}

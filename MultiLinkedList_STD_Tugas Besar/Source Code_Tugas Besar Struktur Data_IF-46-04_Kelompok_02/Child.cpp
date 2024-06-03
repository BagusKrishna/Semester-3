#include "Child.h"

void createListOrg(List_org &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_org findOrg(List_org L, string namaOrg){
    if (!isEmptyOrg(L)){
        adr_org P = first(L);
        while(P != NULL){
            if (info(P).nama == namaOrg){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void insertFirstOrg(List_org &L, adr_org P){
    if (isEmptyOrg(L)) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
        prev(P) = NULL;
    }
}

void insertLastOrg(List_org &L, adr_org P){
    if (isEmptyOrg(L)) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = NULL;
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}


void printInfoOrg(List_org L){
   if(!isEmptyOrg(L)){
        adr_org P = first(L);
        int j = 1;
        while (P != NULL){
            cout << "+--------------------------------+" << endl;
            cout << "|       *DATA ORGANISASI " << j << "*"  << setw(27) << left;
            cout << setw(7) << right << "|" << endl;
            cout << "+--------------------------------+" << endl;
            cout << "| Nama         : " << setw(15) << left << info(P).nama << " |" << endl;
            cout << "| Jenis        : " << setw(15) << left << info(P).jenis << " |" << endl;
            cout << "| Tahun Terbit : " << setw(15) << left << info(P).tahun_terbit << " |" << endl;
            cout << "| Anggota      : " << setw(15) << left << info(P).jumlah_anggota << " |" << endl;
            cout << "+--------------------------------+" << endl;
            P = next(P);
            j++;
        }
   }else{
        cout << "+----------------------------------+" << endl;
        cout << "|         *TIDAK ADA DATA*        |" << endl;
        cout << "+----------------------------------+" << endl;
   }

}

int countOrg(List_org L){
    int totalElm = 0;
    adr_org temp = first(L);
    if (isEmptyOrg(L)){
        return 0;
    }else{
        while (temp != NULL) {
            totalElm++;
            temp = next(temp);
        }
    }
    return totalElm;
}

adr_org alokasiOrg(infotype_org x){
    adr_org P = new elmlist_org;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasiOrg(adr_org &P){
    delete P;
}

bool isEmptyOrg(List_org L){
    return first(L) == NULL;
}

void deleteFirstOrg(List_org &L, adr_org &P){
    if (!isEmptyOrg(L)){
        P = first(L);
        if (next(P) != NULL) {
            first(L) = next(P);
            prev(next(P)) = NULL;
            next(P) = NULL;
        } else {
            first(L) = NULL;
            last(L) = NULL;
        }
    }
}
void deleteLastOrg(List_org &L, adr_org &P){
    if (!isEmptyOrg(L)){
        if (P != first(L)) {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        } else {
            last(L) = NULL;
            first(L) = NULL;
        }
    }
}
void deleteAfterOrg(List_org &L, adr_org Prec, adr_org &P){
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        if (next(P) != NULL) {
            prev(next(P)) = Prec;
        }
        prev(P) = NULL;
        next(P) = NULL;
    }
}


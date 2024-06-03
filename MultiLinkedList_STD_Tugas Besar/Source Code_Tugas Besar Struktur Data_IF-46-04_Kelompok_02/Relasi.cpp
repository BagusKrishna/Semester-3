#include "Relasi.h"

adr_relasi createElmRelasi(){
    adr_relasi P = new elmlist_relasi;
    nextRelasi(P) = NULL;
    nextChild(P) = NULL;
    return P;
}

void deleteLastRelasi(adr_relasi &R) {
    if (prevRelasi(R) != NULL) {
        deleteAfterRelasi(prevRelasi(R), prevRelasi(prevRelasi(R)));
    } else {
        // Jika R adalah relasi pertama
        if (nextRelasi(R) != NULL) {
            prevRelasi(nextRelasi(R)) = NULL;
        }
        nextRelasi(R) = NULL;
    }
}

void deleteAfterRelasi(adr_relasi &R, adr_relasi prec) {
    if (nextRelasi(prec) == R) {
        nextRelasi(prec) = nextRelasi(R);
        if (nextRelasi(R) != NULL) {
            prevRelasi(nextRelasi(R)) = prec;
        }
        nextRelasi(R) = NULL;
        prevRelasi(R) = NULL;
    }
}

void dealokasiRelasi(adr_relasi &P) {
    delete P;
}




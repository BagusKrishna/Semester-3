#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

//include child
#include "Child.h"

#define nextRelasi(P) P->nextRelasi
#define prevRelasi(P) P->prevRelasi
#define nextChild(P) P->nextChild
#define info(P) P->info

#include <iostream>
using namespace std;


typedef struct elmlist_relasi *adr_relasi;

struct elmlist_relasi{
    adr_relasi nextRelasi;
    adr_relasi prevRelasi;
    adr_org nextChild; //include child
};


adr_relasi createElmRelasi();
void dealokasiRelasi(adr_relasi &P);
void deleteLastRelasi(adr_relasi &R);
void deleteAfterRelasi(adr_relasi &R, adr_relasi prec);



#endif // RELASI_H_INCLUDED

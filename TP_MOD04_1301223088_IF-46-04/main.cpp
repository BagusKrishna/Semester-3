#include <iostream>
#include "list.h"
using namespace std;


int main()
{
    List L;
    address P,Prec;
    int angka,n, i;
    int dijit;

    createList_1301223088(L);

    cout << "Masukkan jumlah digit : ";
    cin >> n;

    i = 1;
    while (i <= n){
        cout << "Digit " << i << ": ";
        cin >> angka;

        P = allocate_1301223088(angka);
        insertLast_1301223088(L, P);
        i++;
    }

    printInfo_1301223088(L);

    //deleteFirst_1301223088(L,P);
    //printInfo_1301223088(L);
    //cin >> dijit;
    //P = searchInfo_1301223088(L,jit);
    //cout << info(P) << endl;

    return 0;
}

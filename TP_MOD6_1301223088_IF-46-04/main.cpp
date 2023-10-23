#include "dll.h"

int main() {
    List L1,L2,L3;
    adr P;
    createList_1301223088(L1);
    createList_1301223088(L2);
    createList_1301223088(L3);

    cout << "MENAMBAH DATA L1" << endl;
    tambahData_1301223088(L1);
    cout << "MENAMBAH DATA L2" << endl;
    tambahData_1301223088(L2);
    //terdapat pemanggilan prosedur createElement dan insertLast.

    cout << "DATA L1: " << endl;
    show_1301223088(L1);
    cout << "DATA L2: " << endl;
    show_1301223088(L2);

    cout << "*CONCAT (L1+L2)* " << endl;
    cout << endl;
    concat_1301223088(L1,L2,L3);

    cout << "DATA L3: " << endl;
    show_1301223088(L3);

    string judul;
    cout << "remove lagu (judul) : "; cin >> judul;
    removeLagu_1301223088(judul,L3);

    show_1301223088(L3);


    return 0;
}

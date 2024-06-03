#include "Parent.h"
#include "Child.h"

int main()
{
    //declare list
    List_mhs LM;
    List_org LO;

    //declare infotype
    infotype_mhs infoMhs;
    infotype_org infoOrg;

    createListMhs(LM);
    createListOrg(LO);

    int pilihan = mainMenu();

    while (pilihan != 0) {
        if (pilihan == 1){
            cout << "+----------------------------------+" << endl;
            cout << "|         *TAMBAH MAHASISWA*       |" << endl;
            cout << "+----------------------------------+" << endl;
            cout << "Nama            : "; cin >> infoMhs.nama;
            cout << "NIM             : "; cin >> infoMhs.nim;
            cout << "Umur            : "; cin >> infoMhs.umur;
            cout << "Semester        : "; cin >> infoMhs.semester;
            cout << "IPK             : "; cin >> infoMhs.ipk;
            cout << "+----------------------------------+" << endl;

            char adaPrestasi;
            int banyakPrestasi;
            cout << "Prestasi(y/n)   : "; cin >> adaPrestasi;
            if (adaPrestasi == 'y') {
                cout << "Banyak prestasi : "; cin >> banyakPrestasi;
                for(int i = 0; i < banyakPrestasi; i++) {
                    cout << "Prestasi " << i + 1 << "      : "; cin >> infoMhs.prestasi[i];
                }
            } else {
                //reset array prestasi
                for(int i = 0; i < 10; i++) {
                    infoMhs.prestasi[i] = "";
                }

            }

            adr_mhs newElmMhs = alokasiMhs(infoMhs);
            insertLastMhs(LM, newElmMhs);
            cout << "+----------------------------------+" << endl;
            cout << "|-------------*SUKSES*-------------|" << endl;
            cout << endl;


        } else if (pilihan == 2){
            cout << "+----------------------------------+" << endl;
            cout << "|        *TAMBAH ORGANISASI*       |" << endl;
            cout << "+----------------------------------+" << endl;
            cout << "Nama           : "; cin >> infoOrg.nama;
            cout << "Jenis          : "; cin >> infoOrg.jenis;
            cout << "Tahun Terbit   : "; cin >> infoOrg.tahun_terbit;
            cout << "Jumlah Anggota : "; cin >> infoOrg.jumlah_anggota;
             cout <<"+----------------------------------+" << endl;

            adr_org newElmOrg = alokasiOrg(infoOrg);
            insertLastOrg(LO, newElmOrg);

            cout << "|-------------*SUKSES*-------------|" << endl;
            cout << endl;

        } else if (pilihan == 3){
            int pilihSub = subMenuShowMhs();
            while (pilihSub != 0){
                if( pilihSub == 1){
                    printInfoMhs(LM);
                    cout << "~Press any key" << endl;
                    _getch();
                    cout << endl;
                }else if (pilihSub == 2){
                    cout << "+----------------------------------+" << endl;
                    cout << "|     *MASUKKAN NAMA MAHASISWA*    |" << endl;
                    cout << "+----------------------------------+" << endl;
                    string namaMhs;
                    cout << "JAWABAN ANDA: "; cin >> namaMhs;
                    cout << endl;
                    showRelasiMhs(LM, namaMhs);
                    cout << "~Press any key" << endl;
                    _getch();
                }else if (pilihSub == 3){
                    showAllRelasi(LM);
                    cout << endl;
                }
                pilihSub = subMenuShowMhs();
            }
        } else if (pilihan == 4){
            printInfoOrg(LO);
            cout << "~Press any key" << endl;
            _getch();
            cout << endl;

        } else if (pilihan == 5){
            if (isEmptyMhs(LM)){
                cout << "+-------------------------------+" << endl;
                cout << "|        *TIDAK ADA DATA *      |" << endl;
                cout << "+-------------------------------+" << endl;
                cout << "~Press any key" << endl;
                _getch();
            } else {
                string del_mhs;
                cout << "+--------------------------------------+" << endl;
                cout << "|  *NAMA MAHASISWA YANG AKAN DIHAPUS*  |" << endl;
                cout << "+--------------------------------------+" << endl;
                cout << "JAWABAN ANDA : "; cin >> del_mhs;
                deleteDataMhs(LM, del_mhs);
            }

        } else if (pilihan == 6){
            if (isEmptyOrg(LO)){
                cout << "+-------------------------------+" << endl;
                cout << "|        *TIDAK ADA DATA *      |" << endl;
                cout << "+-------------------------------+" << endl;
                cout << "~Press any key" << endl;
                _getch();
            } else {
                string del_org;
                cout << "+--------------------------------------+" << endl;
                cout << "|  *NAMA ORGANISASI YANG AKAN DIHAPUS* |" << endl;
                cout << "+--------------------------------------+" << endl;
                cout << "JAWABAN ANDA : "; cin >> del_org;
                deleteDataOrg(LM, LO, del_org);
            }

        } else if (pilihan == 7){
            if (isEmptyMhs(LM)){
                cout << "+-------------------------------+" << endl;
                cout << "|        *TIDAK ADA DATA *      |" << endl;
                cout << "+-------------------------------+" << endl;
                cout << "~Press any key" << endl;
                _getch();
            } else {
                cout << "+----------------------------------+" << endl;
                cout << "|    *NIM MAHASISWA YANG DICARI*   |" << endl;
                cout << "+----------------------------------+" << endl;
                string cariNimMhs;
                cout << "JAWABAN ANDA: "; cin >> cariNimMhs;
                cout << endl;
                adr_mhs cariMhs = findMhs(LM, cariNimMhs);

                if (cariMhs != NULL){
                    cout << "+----------------------------------+" << endl;
                    cout << "|         *DATA DITEMUKAN*         |" << endl;
                    cout << "+----------------------------------+" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "|       *DATA MAHASISWA*         |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| Nama       : " << setw(17) << left << info(cariMhs).nama << " |" << endl;
                    cout << "| NIM        : " << setw(17) << left << info(cariMhs).nim << " |" << endl;
                    cout << "| Umur       : " << setw(17) << left << info(cariMhs).umur << " |" << endl;
                    cout << "| Semester   : " << setw(17) << left << info(cariMhs).semester << " |" << endl;
                    cout << "| IPK        : " << setw(17) << left << info(cariMhs).ipk << " |" << endl;
                    cout << "+--------------------------------+" << endl;

                    bool adaPrestasi = false; //buat cek prestasi
                    // Print prestasi
                    for (int i = 0; i < 10; i++) {
                        if (!info(cariMhs).prestasi[i].empty()) {
                            adaPrestasi = true;
                            cout << "| Prestasi " << i << " : " << setw(17) << left << info(cariMhs).prestasi[i] << " |" << endl;
                        }
                    }
                    //pembatas bawah kalo ada prestasi
                    if (adaPrestasi){
                        cout << "+--------------------------------+" << endl;
                    }
                        cout << "~Press any key" << endl;
                        _getch();
                }else{
                    cout << "+----------------------------------+" << endl;
                    cout << "|      *DATA TIDAK DITEMUKAN *     |" << endl;
                    cout << "+----------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                }
            }


        } else if (pilihan == 8){
            if (isEmptyOrg(LO)){
                cout << "+-------------------------------+" << endl;
                cout << "|        *TIDAK ADA DATA *      |" << endl;
                cout << "+-------------------------------+" << endl;
                cout << "~Press any key" << endl;
                _getch();
            } else {
                cout << "+----------------------------------+" << endl;
                cout << "|   *NAMA ORGANISASI YANG DICARI*  |" << endl;
                cout << "+----------------------------------+" << endl;
                string cariNamaOrg;
                cout << "JAWABAN ANDA: "; cin >> cariNamaOrg;
                adr_org cariOrg = findOrg(LO, cariNamaOrg);
                if (cariOrg != NULL){
                    cout << "+----------------------------------+" << endl;
                    cout << "|         *DATA DITEMUKAN*         |" << endl;
                    cout << "+----------------------------------+" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "|       *DATA ORGANISASI*        |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "| Nama         : " << setw(15) << left << info(cariOrg).nama << " |" << endl;
                    cout << "| Jenis        : " << setw(15) << left << info(cariOrg).jenis << " |" << endl;
                    cout << "| Tahun Terbit : " << setw(15) << left << info(cariOrg).tahun_terbit << " |" << endl;
                    cout << "| Anggota      : " << setw(15) << left << info(cariOrg).jumlah_anggota << " |" << endl;
                    cout << "+--------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
               } else {
                    cout << "+----------------------------------+" << endl;
                    cout << "|      *DATA TIDAK DITEMUKAN*      |" << endl;
                    cout << "+----------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
               }
            }

        } else if (pilihan == 9){

            // Kalau tidak ada data parent / child
            if (isEmptyMhs(LM) || isEmptyOrg(LO)) {
                if (isEmptyMhs(LM) && isEmptyOrg(LO)){
                    cout << "+-------------------------------+" << endl;
                    cout << "|        *TIDAK ADA DATA *      |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                } else if (isEmptyMhs(LM)) {
                    cout << "+-------------------------------+" << endl;
                    cout << "|   *TIDAK ADA DATA MAHASISWA*  |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                } else {
                    cout << "+-------------------------------+" << endl;
                    cout << "|  *TIDAK ADA DATA ORGANISASI*  |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                }

            } else {
                 //connect parent-child
                connectRelasi(LM,LO);
                //print relasi mahasiswa 'x'
            }

        } else if (pilihan == 10){
             if (isEmptyMhs(LM) || isEmptyOrg(LO)) {
                if (isEmptyMhs(LM) && isEmptyOrg(LO)){
                    cout << "+-------------------------------+" << endl;
                    cout << "|        *TIDAK ADA DATA *      |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                } else if (isEmptyMhs(LM)) {
                    cout << "+-------------------------------+" << endl;
                    cout << "|   *TIDAK ADA DATA MAHASISWA*  |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                } else {
                    cout << "+-------------------------------+" << endl;
                    cout << "|   *TIDAK ADA DATA MAHASISWA*  |" << endl;
                    cout << "+-------------------------------+" << endl;
                    cout << "~Press any key" << endl;
                    _getch();
                }

            } else {
                 //disconnect
                string namaOrg, namaMhs;
                cout << "Masukkan NAMA Mahasiswa  : "; cin >> namaMhs;
                cout << "Masukkan NAMA Organisasi : "; cin >> namaOrg;
                disconnectRelasi(LM, LO, namaMhs, namaOrg);
            }

        } else if (pilihan == 11){
            int pilihSub = subMenuCountElm();
            while (pilihSub != 0){
                if (pilihSub == 1){
                   cout << "Total Mahasiswa: " << countMhs(LM) << endl;
                }else if (pilihSub == 2){
                    cout << "Total Organisasi: " << countOrg(LO) << endl;
                }else if (pilihSub == 3){
                    string namaMhs;
                    cout << "Masukkan nama mahasiswa: "; cin >> namaMhs;
                    adr_mhs cariMhs = findMhsByNama(LM, namaMhs);
                    cout << "Total Organisasi yang diikuti " << namaMhs << ": " <<  countOrgByMhs(LM, cariMhs) << endl;
                }
                pilihSub = subMenuCountElm();
            }
        } else {
            cout << "+-------------------------+" << endl;
            cout << "|   *INPUTAN ANDA SALAH*  |" << endl;
            cout << "+-------------------------+" << endl;
            cout << "PILIHAN ANDA : "; cin >> pilihan;
            cout << endl;
        }
        pilihan = mainMenu();
    }
    return 0;
}

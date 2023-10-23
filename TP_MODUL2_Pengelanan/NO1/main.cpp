#include <iostream>

using namespace std;

int main(){

    string nama, nim;
    cout << "Siapa nama anda? ";
    getline(cin, nama);
    //cin >> nama;
    cout << "Berapa nim anda? ";
    cin >> nim;
    cout << "Nama saya:" << nama << endl;
    cout << "NIM saya:" << nim << endl;
    return 0;
}

#include <iostream>
#include "kerucut.h"

using namespace std;

int main() {
    Kerucut kerucut;
    double r, t;

    cout << "Program Volume dan luas permukaan kerucut" << endl;
    cout << "Jari - jari : ";
    cin >> r;
    cout << "Tinggi      : ";
    cin >> t;
    isiKerucut_1301223088(kerucut, r, t);

    double volume = hitungVolume_1301223088(kerucut);
    double luasPermukaan = hitungLuasPermukaan_1301223088(kerucut);

    cout << "Volume Kerucut        : " << volume << endl;
    cout << "Luas Permukaan Kerucut: " << luasPermukaan << endl;

    return 0;
}

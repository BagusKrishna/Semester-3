#include <cmath>
#include "kerucut.h"


void isiKerucut_1301223088(Kerucut& kerucut, double r, double t) {
    kerucut.jariJari = r;
    kerucut.tinggi = t;
}

double hitungVolume_1301223088(Kerucut& kerucut) {
    return (1.0 / 3.0) * 3.14159265359 * kerucut.jariJari * kerucut.jariJari * kerucut.tinggi;
}

double hitungLuasPermukaan_1301223088(Kerucut& kerucut) {
    double sisiMiring = sqrt(kerucut.jariJari * kerucut.jariJari + kerucut.tinggi * kerucut.tinggi);
    return 3.14159265359 * kerucut.jariJari * (kerucut.jariJari + sisiMiring);
}

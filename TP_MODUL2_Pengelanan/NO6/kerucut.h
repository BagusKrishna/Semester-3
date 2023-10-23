#ifndef KERUCUT_H
#define KERUCUT_H

struct Kerucut {
    double jariJari;
    double tinggi;
};

void isiKerucut_1301223088(Kerucut& kerucut, double r, double t);

double hitungVolume_1301223088(Kerucut& kerucut);

double hitungLuasPermukaan_1301223088(Kerucut& kerucut);

#endif // KERUCUT_H

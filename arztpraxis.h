#ifndef ARZTPRAXIS_H
#define ARZTPRAXIS_H

#include "termin.h"
#include<string>
#include<vector>
using namespace std;

class Arztpraxis{
private:
    const string name ="Dr.Koch";
    vector<Termin> terminListe;
public:
    Arztpraxis();
    Arztpraxis(string,vector<Termin>&);
    vector<Termin>& get_terminListe();
    string get_PraxisName()const;
    void terminAnlegen(string, Impfstoff, string p1);
    void terminLoeschen(string);
    void printTermin();
    void sortedTermin(vector<Termin>& v);
};

#endif // ARZTPRAXIS_H


#ifndef TERMIN_H
#define TERMIN_H

#include<iostream>
#include<string>
using namespace std;
enum Impfstoff{Biontech=1,Moderna,AstraZeneca, JohnsonJohnson};


class Termin{
private:
    string patient;
    Impfstoff impfstofftyp;
    string datumUhrzeit;
    bool geloescht=false;

public:
    Termin();
    Termin(string, Impfstoff, string);
    string get_Patient()const;
    string get_datumUhrzeit()const;
    Impfstoff get_impfstofftyp()const;
    void printTerminDetails();

};


#endif // TERMIN_H

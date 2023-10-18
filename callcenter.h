#ifndef CALLCENTER_H
#define CALLCENTER_H

#include"arztpraxis.h"

class Callcenter
{
private:
    Arztpraxis arztpraxis;
    vector<Arztpraxis>praxisListe={arztpraxis};

public:
    Callcenter();
    void dialog();
    void ArztpraxisAnlegen(string ,vector<Termin>&);
    void printall();
   // void sorted(vector<Arztpraxis>&);
};




#endif // CALLCENTER_H

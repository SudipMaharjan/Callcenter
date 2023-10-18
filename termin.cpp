#include "termin.h"

Termin::Termin()
    :patient{"Ram"},impfstofftyp{Impfstoff::Biontech},datumUhrzeit{"16.01.2023:0830"}
{}

Termin::Termin(string p, Impfstoff i, string d)
    :patient{p},impfstofftyp{i}, datumUhrzeit{d}
{}

string Termin::get_Patient()const{
    return patient;
}

string Termin::get_datumUhrzeit()const{
    return datumUhrzeit;
}

Impfstoff Termin::get_impfstofftyp()const{
   return impfstofftyp;
}

void Termin::printTerminDetails(){
    cout<<patient<<"\t"<<datumUhrzeit<<"\t";
    if(impfstofftyp==1)cout<<"Biontech";
    if(impfstofftyp==2)cout<<"Moderna";
    if(impfstofftyp==3)cout<<"AstraZeneca";
    if(impfstofftyp==4)cout<<"JohnsonJohnson";
    cout<<endl;
}

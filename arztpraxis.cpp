#include "arztpraxis.h"
#include<algorithm>

Arztpraxis::Arztpraxis()
    :terminListe{}
{}

Arztpraxis::Arztpraxis(string n, vector<Termin> &v)
    :name{n},terminListe{v}
{}

bool compareByPatient(const Termin &a, const Termin &b) {
    return a.get_Patient() < b.get_Patient();
}

void Arztpraxis::terminAnlegen(string p, Impfstoff i, string n){
    Termin t1(p,i,n);
    terminListe.push_back(t1);
    cout<<"Termin wurde eingetragen"<<endl;
}
string Arztpraxis::get_PraxisName()const{
    return name;
}
void Arztpraxis::terminLoeschen(string n){
    for( unsigned int i=0;i<terminListe.size();i++){
        if(terminListe[i].get_Patient()== n){
            terminListe.erase(terminListe.begin()+i);
            i--;
        }
    }
}
vector<Termin>& Arztpraxis::get_terminListe(){
    return terminListe;
}
void Arztpraxis::printTermin(){
    if(terminListe.size()!=0){
        cout<<endl;

        sort(terminListe.begin(),terminListe.end(),compareByPatient);

        cout<<"Arztpraxis "<<name<<endl;
        for(unsigned int i{};i<terminListe.size();i++){
            terminListe[i].printTerminDetails();
        }
    }
}

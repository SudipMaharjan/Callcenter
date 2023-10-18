#include "callcenter.h"
#include "arztpraxis.h"

Callcenter::Callcenter()
    :arztpraxis{}
{}

void Callcenter::ArztpraxisAnlegen(string n,vector<Termin>& v){
    Arztpraxis praxis2(n,v);
    praxisListe.push_back(praxis2);
    cout<<"Arztpraxis angelegt"<<endl;
}

void Callcenter::printall(){

    for(unsigned int i{};i<praxisListe.size();i++){
        praxisListe[i].printTermin();
    }
}



void Callcenter::dialog(){
    int auswahl,i;
    string n,p1,p2,praxis;
    bool loop=true;
    vector<Termin>v{};


    while(loop){
        cout<<"Menuu"<<endl;
        cout<<"\t 1: Termin anlegen"<<endl;
        cout<<"\t 2:Termin loeschen"<<endl;
        cout<<"\t 3:Arztpraxis anlegen "<<endl;
        cout<<"\t 4:Alle anzeigen "<<endl;
        cout<<"\t 0: Program beednden"<<endl;
        cout<<"Bitte Auswaehlen"<<endl;

        cin>> auswahl;

        switch(auswahl){
        case 1: cout<<"Termin anlegen"<<endl;
                cout<<"Bitte Ihren Namen eingeben"<<endl;
                cin>>n;

                cout<<"Welcher Arztpraxis? Name der Arzt eingaben."<<endl;
                for(unsigned int j{};j<praxisListe.size();j++){
                    cout<<"\t"<<j+1<<": ";
                    cout<<praxisListe.at(j).get_PraxisName()<<endl;
                }
                cin>>praxis;

                cout<<"Bitte Impfstofftyp eingeben"<<endl;
                cout<<"1: Biontech"<<endl;
                cout<<"2: Moderna"<<endl;
                cout<<"3: AstraZeneca"<<endl;
                cout<<"4: JohnsonJohnson"<<endl;
                cin>>i;

                for(unsigned int j{};j<praxisListe.size();j++){
                    if(praxisListe[j].get_PraxisName()==praxis){
                            if(i==1){
                                cout<<"Termin datum (tt/mm/jj)?"<<endl;
                                cin>>p1;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p1==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben (tt/mm/jj)"<<endl;
                                        cin>>p1;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::Biontech,p1);

                                cout<<"zweite Termin eingeben (tt/mm/jj)"<<endl;
                                cin>> p2;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p2==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p2;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::Biontech,p2);
                            }

                            else if(i==2){
                                cout<<"Termin?"<<endl;
                                cin>>p1;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p1==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p1;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::Moderna,p1);

                                cout<<"zweite Termin eingeben"<<endl;
                                cin>> p2;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p2==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p2;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::Moderna,p2);
                            }
                            else if(i==3){
                                cout<<"Termin?"<<endl;
                                cin>>p1;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p1==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p1;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::AstraZeneca,p1);

                                cout<<"zweite Termin eingeben"<<endl;
                                cin>> p2;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p2==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p2;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::AstraZeneca,p2);
                            }
                            else if(i==4){
                                cout<<"Termin?"<<endl;
                                cin>>p1;
                                for(unsigned int q{};q<praxisListe[j].get_terminListe().size();q++){
                                    while(p1==praxisListe[j].get_terminListe()[q].get_datumUhrzeit()){
                                        cout<<"Termin ist schon vergeben. Bitte neuen termin eingeben"<<endl;
                                        cin>>p1;
                                    }
                                }
                                praxisListe[j].terminAnlegen(n,Impfstoff::JohnsonJohnson,p1);
                            }
                            else{
                                cout<<"falsche eingebe"<<endl;
                            }
                    }

                }
            break;

        case 2: cout<<"Termin loeschen"<<endl;
                cout<<"Bitte Ihren Namen eingeben"<<endl;
                cin>>n;
                for(unsigned int j{};j<praxisListe.size();j++){
                    praxisListe[j].terminLoeschen(n);
                }
                cout<< "termin geloescht"<<endl;
            break;

        case 3: cout<<"Arztpraxis anlegen"<<endl;
                cout<<"Bitte Names des Praxis eingeben"<<endl;
                cin>>n;
                ArztpraxisAnlegen(n,v);
            break;

        case 4:cout<<"Alle Termine"<<endl;
               printall();
            break;

        case 0: cout<<"Programm beendet"<<endl;
                loop=false;
            break;
        }
    }
}

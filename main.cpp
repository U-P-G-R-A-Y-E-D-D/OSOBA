#include "Osoba.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    Osoba osoba;
    int c;
    std::string rc;
    Osoba osoba1("0801080016");
    cout<<"osoba ma rodne cislo "<<osoba.getRodneCislo()<<endl;
    cout<<"Datum narozeni osoby je "<<osoba.getDatum()<<endl;
    cout<<"osoba ma "<<osoba.getVek()<<" let"<<endl;
    cout<<"osoba1 ma rodne cislo "<<osoba1.getRodneCislo()<<endl;
    cout<<"Datum narozeni osoby1 je "<<osoba1.getDatum()<<endl;
    cout<<"osoba 1 ma "<<osoba1.getVek()<<" let"<<endl;
    cout<<"Datum narozeni osoby je "<<osoba.getDatum()<<endl;
    cout<<"osoba 1 ma "<<osoba.getVek()<<" let"<<endl;
    do{
        cout<<"Zadej rodne cislo: ";
        cin>>rc;
        if(osoba.setRodneCislo(rc)){
            cout<<"Rodne cislo :"<<osoba.getRodneCislo()<<endl;
            cout<<"Datum narozeni osoby je "<<osoba.getDatum()<<endl;
            cout<<"osoba ma "<<osoba.getVek()<<" let"<<endl;
        }
        else
            cout<<"Zadal jsi chybne rodne cislo"<<endl;

        cout<<"chcete pokracovat? 1-ano 0-ne ";
        cin>>c;
    }while(c==1);

    return 0;
}

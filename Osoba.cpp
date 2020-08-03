//
// Created by Honza on 03.08.2020.
//

#include "Osoba.hpp"
#define RC "9999999999"
#define MIN 1954
#define MAX 2053

Osoba::Osoba() {
    this->rodneCislo=RC;
}

Osoba:: Osoba(std::string rodneCislo){
    if(platnost(rodneCislo))
        this->rodneCislo=rodneCislo;
    else
        this->rodneCislo=RC;
}

std::string Osoba::getRodneCislo() const{
    return this->rodneCislo;
}

int Osoba::getDen(std::string rc) const{
    return std::stoi(rc.substr(4,2));
}

int Osoba::getMesic(std::string rc) const{
    return std::stoi(rc.substr(2,2))>50?
           std::stoi(rc.substr(2,2))-50 :
           std::stoi(rc.substr(2,2));

}

int Osoba::getRok(std::string rc) const{
    return std::stoi(rc.substr(0,2))<54?
           std::stoi(rc.substr(0,2))+2000 :
           std::stoi(rc.substr(0,2))+1900;

}

std::string Osoba::getDatum() const{
    std::ostringstream datum;
    //podminka pokud jde o defaultni rodne cislo
    if(this->rodneCislo==RC){
        return "\npro defaultni rodne cislo nelze urcit datum";
    }
    datum<<this->getDen(this->rodneCislo)<<". "<<this->getMesic(this->rodneCislo)<<". "
         <<this->getRok(this->rodneCislo);
    return datum.str();
}

int Osoba:: getVek()const{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    if(this->rodneCislo==RC){
        return -1;
    }

    int den=timeinfo->tm_mday;
    int mesic=timeinfo->tm_mon+1;
    int rok=timeinfo->tm_year+1900;
    int vek=rok-getRok(this->rodneCislo);
    if(mesic<getMesic(this->rodneCislo))
        vek--;
    else if(mesic==getMesic(this->rodneCislo) && den<getDen(this->rodneCislo))
        vek--;

    return vek;
}

Osoba::Osoba(const Osoba& orig) {
}

bool Osoba::platnost(std::string rc) const{
    //kontrola delky
    if(rc.length()!=10)
        return false;
    //kontrola platonosti data
    if(!(kontrolaData(getDen(rc), getMesic(rc), getRok(rc))))
        return false;
    std::string prvnich9 = rc.substr (0,9);
    int kontrolniCifra=std::stoi(prvnich9)%11;
    //kontrola vlastnosti zadaneho rodneho cisla
    if(kontrolniCifra==std::stoi(rc.substr(9,1)))
        return true;
    else if(kontrolniCifra==10 && rc.substr(9,1)=="0")
        return true;
    else
        return false;
}

bool Osoba::prestupnyRok(int rok) const{
    if((rok%4==0) && (rok%100!=0 || rok%400==0)){
        return true;
    }
    else
        return false;

}

int Osoba::pocetDniMesic(int rok, int mesic) const{
    int dny[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(prestupnyRok(rok)&&mesic==2){
        return 29;
        //return dny[mesic-1]+1;
    }
    else
        return dny[mesic-1];

}

bool Osoba::kontrolaData(int den, int mesic, int rok) const{
    if (rok<MIN||rok>MAX){
        return false;
    }
    if (mesic<1||mesic>12){
        return false;
    }
    if (den<1||den>pocetDniMesic(rok,mesic)){
        return false;
    }
    else
        return true;
}

bool Osoba::setRodneCislo(std::string rc){
    //kontrola platnosti zadaneho parametru
    if(platnost(rc)){
        this->rodneCislo=rc;
        return true;
    }
        //pokud rodne cislo nevyhovuje, tak vracime false
    else
        return false;
}


Osoba::~Osoba() {
}



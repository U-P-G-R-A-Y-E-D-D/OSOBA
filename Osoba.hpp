//
// Created by Honza on 03.08.2020.
//


#ifndef OSOBA_OSOBA_HPP
#define OSOBA_OSOBA_HPP
#include <string>
#include <sstream>
#include <ctime>
class Osoba {
public:
    Osoba();
    Osoba (std::string);
    Osoba(const Osoba& orig);
    virtual ~Osoba();
    bool setRodneCislo(std::string);
    std::string getRodneCislo()const;
    std::string getDatum()const;
    int getVek()const;

private:
    std::string rodneCislo;
    bool platnost(std::string)const;
    int getDen(std::string)const;
    int getMesic(std::string)const;
    int getRok(std::string)const;
    bool prestupnyRok(int)const;
    int pocetDniMesic(int, int)const;
    bool kontrolaData(int,int,int)const;
};

#endif /* OSOBA_HPP */


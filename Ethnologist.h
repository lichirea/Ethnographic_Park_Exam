//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_ETHNOLOGIST_H
#define PEXAM_REDONE_ETHNOLOGIST_H

#include <string>
using namespace std;

class Ethnologist{
public:
    std::string name;
    std::string area;
    bool operator==(const Ethnologist& e) const{
        if(this->name == e.name && this->area == e.area) return true;
        return false;
    }
    Ethnologist(string n, string a){
        name = std::move(n);
        area = std::move(a);
    }
    std::string toStr(){
        return name + "|" + area;
    }
};

#endif //PEXAM_REDONE_ETHNOLOGIST_H

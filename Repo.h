//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_REPO_H
#define PEXAM_REDONE_REPO_H
#include <vector>
#include <string>
#include "Ethnologist.h"
#include "Building.h"

class Repo {
private:
    std::vector<Ethnologist> ev;
    std::vector<Building> bv;
public:
    std::vector<Ethnologist> getEthnologists();
    std::vector<Building> getBuildings();

    void addE (const Ethnologist& e);
    void addB (const Building& b);
    int sizeE(){
        return ev.size();
    }
    int sizeB(){
        return bv.size();
    }

};


#endif //PEXAM_REDONE_REPO_H

//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_SERVICE_H
#define PEXAM_REDONE_SERVICE_H
#include "Repo.h"

class Service {
private:
    Repo* r;
public:
    Service(Repo* repo){
        r = repo;
    }

    void addB(std::string desc,std::string area,int id,std::string coord);
    vector<Ethnologist> getEthno();

    std::vector<Building> getBuildings();
};


#endif //PEXAM_REDONE_SERVICE_H

//
// Created by vibii on 07/07/2021.
//

#include "Repo.h"

std::vector<Ethnologist> Repo::getEthnologists() {
    return this->ev;
}

std::vector<Building> Repo::getBuildings() {
    return this->bv;
}

void Repo::addE(const Ethnologist& e) {
    for(const auto& i : ev){
        if(i == e) throw std::exception();
    }
    ev.push_back(e);
}

void Repo::addB(const Building& b) {
    for(const auto& i : bv){
        if(i == b) throw std::exception();
    }

    bv.push_back(b);
}

//
// Created by vibii on 07/07/2021.
//

#include "Service.h"

#include <utility>

void Service::addB(std::string desc, std::string area, int id, std::string coord) {
    if(desc.empty()) throw std::exception();
    Building b (id, desc, std::move(area), std::move(coord));
    this->r->addB(b);
}

std::vector<Ethnologist> Service::getEthno() {
    return r->getEthnologists();
}

std::vector<Building> Service::getBuildings() {
    return r->getBuildings();
}

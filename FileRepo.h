//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_FILEREPO_H
#define PEXAM_REDONE_FILEREPO_H
#include "Repo.h"
#include <fstream>
using namespace std;

class FileRepo{
public:

    void readEthnologists(Repo* r){
        std::ifstream file("../ethnologists.txt");
        while(!file.eof()){
            string name; string area;
            getline(file, name);
            getline(file, area);
            Ethnologist e (name, area);
            r->addE(e);
        }
        file.close();
    }

    void readBuildings(Repo* r){
        std::ifstream file("../buildings.txt");
        while(!file.eof()){
            int id;
            string desc;
            string area;
            string location;
            string nothing;
            file >> id;
            getline(file, nothing);
            getline(file, desc);
            getline(file, area);
            getline(file, location);
            Building b(id, desc, area, location);
            r->addB(b);
        }
        file.close();
    }
};

#endif //PEXAM_REDONE_FILEREPO_H

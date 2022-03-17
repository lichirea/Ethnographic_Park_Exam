//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_BUILDING_H
#define PEXAM_REDONE_BUILDING_H

#include <string>
#include <vector>
using namespace std;
class Building{
public:
    std::string desc;
    std::string area;
    int id;
    std::string coord;
    bool operator==(const Building& e) const{
        if(this->id == e.id) return true;
        if(coord.length() == 2 && e.coord.length()==2 && coord == e.coord) return true;
        else{
            vector<string> v1, v2;
            string delimiter = ";";
            string c;
            int pos = 0;
            for(int i = 1; i < coord.length()/2+1; i++){
                c = coord.substr(pos, coord.find(delimiter));
                pos += c.length();
                v1.push_back(c);
            }
            pos = 0;
            for(int i = 1; i < coord.length()/2+1; i++){
                c = coord.substr(pos, coord.find(delimiter));
                pos += c.length();
                v1.push_back(c);
            }
            for(auto i1 : v1){
                for(auto i2: v2){
                    if(v1 == v2) return true;
                }
            }
        }
        return false;
    }
    Building(int i, string d, string a, string l){
        id = i;
        desc = std::move(d);
        area = std::move(a);
        coord = std::move(l);
    }
    string toStr(){
        return to_string(id) + "|" + desc + "|" + area + "|" + coord;
    }
};
#endif //PEXAM_REDONE_BUILDING_H

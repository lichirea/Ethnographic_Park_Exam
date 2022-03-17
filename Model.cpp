//
// Created by vibii on 07/07/2021.
//

#include "Model.h"
#include <QPalette>
#include <utility>
#include "Building.h"
#include <iostream>

int Model::rowCount(const QModelIndex &parent) const {
    return this->v.size();
}


int Model::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant Model::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        std::vector<std::string> split;
        this->split(this->v[index.row()], "|", split);
        return QString::fromStdString(split[index.column()]);
    }
    if (role == Qt::BackgroundRole){
        std::vector<std::string> split;
        this->split(this->v[index.row()], "|", split);
        if(split[2] == this->area){
            return QBrush(Qt::lightGray);
        }

    }
    return QVariant();
}

Model::Model(std::string n, std::string a, std::vector<std::string> ve, QObject *parent) {
    name = n;
    area = a;
    v = std::move(ve);
}

void Model::split(const std::string &str, const std::string &delim, std::vector<std::string> &parts) const {
    size_t start, end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != std::string::npos)) {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == std::string::npos)) {
            end++;
        }
        if (end-start != 0) {
            parts.push_back(std::string(str, start, end-start));
        }
    }
}

void Model::changed(std::vector<std::string> change) {
    beginResetModel();
    this->v = std::move(change);
    for(const auto& i : this->v){
        std::cout<<i<<"\n";
    }
    endResetModel();
}


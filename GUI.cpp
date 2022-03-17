//
// Created by vibii on 07/07/2021.
//
#include <iostream>
#include "GUI.h"
#include <QMessageBox>
#include <utility>

GUI::GUI(Service *serv) {
    s = serv;
    std::vector<Building> x = s->getBuildings();
    std::vector<std::string> y;
    y.reserve(x.size());
    for(auto j: x){
        y.push_back(j.toStr());
    }
    std::vector<Ethnologist> ethnos = s->getEthno();
    for(auto i : ethnos){
        auto* model = new Model(i.name, i.area, y);
        auto* w = new Window(s, model);
        QObject::connect(w, &Window::addSignal, this, &GUI::add);
        QObject::connect(this, &GUI::changedSignal, model, &Model::changed);
        v.push_back(w);
    }
}

void GUI::add(int id, std::string desc,std::string area, std::string coord) {
    try{
        this->s->addB(desc, area,id, coord);
        std::vector<Building> x = s->getBuildings();
        std::vector<std::string> y;
        y.reserve(x.size());
        for(auto j: x){
            y.push_back(j.toStr());
        }
        for(const auto& i : y){
            std::cout<<i<<"\n";
        }
        emit changedSignal(y);
    }
    catch(std::exception& e){
        QMessageBox messageBox;
        QMessageBox::critical(nullptr, "Error", "Invalid input!");
    }
}


Window::Window(Service *se, Model* mod) {
    this->s = se;
    this->ethnologist =mod->name;
    this->area = mod->area;

    this->m = mod;
    this->v.setModel(this->m);

    this->setWindowTitle(QString::fromStdString(ethnologist));

    this->layout = new QHBoxLayout(this);
    layout->addWidget(&v);


    auto right = new QWidget(this);
    auto rightlayout = new QVBoxLayout(right);

    this->id = new QLineEdit("ID");
    this->desc = new QLineEdit("DESC");
    this->coord = new QLineEdit("COORDINATES");
    this->addButton = new QPushButton("ADD");
    rightlayout->addWidget(id);
    rightlayout->addWidget(desc);
    rightlayout->addWidget(coord);
    rightlayout->addWidget(addButton);
    layout->addWidget(right);

    QObject::connect(this->addButton, &QPushButton::clicked, this, &Window::addHandler);

    this->show();
}

void Window::addHandler() {
    int a; std::string b; std::string c;
    a = this->id->text().toInt();
    b = this->desc->text().toStdString();
    c = this->coord->text().toStdString();
    emit addSignal(a,b,area,c);
}


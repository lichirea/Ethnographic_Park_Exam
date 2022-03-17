//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_GUI_H
#define PEXAM_REDONE_GUI_H
#include "Service.h"
#include <QWidget>
#include <QTableView>
#include "Model.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

class Window: public QWidget{
    Q_OBJECT
private:
    Service* s;
    Model* m;
    QTableView v;
    std::string ethnologist;
    std::string area;
    QHBoxLayout* layout;
    QLineEdit* id;
    QLineEdit* desc;
    QLineEdit* coord;
    QPushButton* addButton;

public:
    Window(Service *s, Model* mod);
    signals:
    void addSignal(int id, std::string desc,std::string area, std::string coord);
    public slots:
    void addHandler();

};

class GUI: public QWidget {
    Q_OBJECT
private:
    std::vector<Window*> v;
    Service* s;
    Model* m;
public:
    explicit GUI(Service* serv);
    signals:
    void changedSignal(std::vector<std::string> change);
public slots:
    void add(int id, std::string desc,std::string area, std::string coord);
};


#endif //PEXAM_REDONE_GUI_H

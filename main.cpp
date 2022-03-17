#include <QApplication>
#include <QPushButton>
#include "FileRepo.h"
#include "Service.h"
#include "Repo.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
   QApplication a(argc, argv);
    auto* r = new Repo;
    auto* f = new FileRepo;
    f->readBuildings(r);
    f->readEthnologists(r);
    auto* s = new Service(r);
    auto* gui = new GUI(s);
    return QApplication::exec();
}

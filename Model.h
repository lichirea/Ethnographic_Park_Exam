//
// Created by vibii on 07/07/2021.
//

#ifndef PEXAM_REDONE_MODEL_H
#define PEXAM_REDONE_MODEL_H
#include <QString>
#include <QAbstractTableModel>
#include <vector>
#include <string>

class Model: public QAbstractTableModel{
    Q_OBJECT
private:
    std::vector<std::string> v;
public:
    std::string name;
    std::string area;
    Model(std::string n, std::string a, std::vector<std::string> ve, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts) const;
public slots:
    void changed(std::vector<std::string> change);
};


#endif //PEXAM_REDONE_MODEL_H

#pragma once


#include <QAbstractTableModel>

#include "dataMeasure.h"


class ModelMeasure : public QAbstractTableModel
{
public:
    explicit ModelMeasure(QObject *parent = nullptr, DataMeasure *dataMeasure=nullptr): QAbstractTableModel{parent}, m_dataMeasure{dataMeasure}{};
private:
    DataMeasure *m_dataMeasure{nullptr};
    
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

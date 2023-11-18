#include "modelMeasure.h"

#include <fmt/core.h>

#include <QSize>

int ModelMeasure::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    if(!m_dataMeasure)
    {
        return 0;
    }
    else
    {
        return m_dataMeasure->size();
    }
}

int ModelMeasure::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6; // lp | Time | Name | Image | Check | Thumb
}


QVariant ModelMeasure::data(const QModelIndex &index, int role) const
{
    (void)role;
    if(!index.isValid()==true){
        return QVariant();
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole){
        int row = index.row();
        int col = index.column();
        auto &oneMeasure = m_dataMeasure->getMeasure(row);
        if(col==0){
            return row;
        }
        if(col==1){
            return  QString::fromStdString( oneMeasure.time); 
        }
        if(col==2){
            return QString::fromStdString( oneMeasure.name);
        }
        if(col==3){
            return QString::fromStdString( oneMeasure.image);
        }
        if(col==4){
            return oneMeasure.checked;
        }
        if(col==5){
            return QString::fromStdString( oneMeasure.desc);
        }
    }

    return QVariant();
}


bool ModelMeasure::setData(const QModelIndex &index, const QVariant &value, int role)
{
    (void)value;
    (void)role;

    if(!index.isValid()==true){
        return false;
    }

    if(role==Qt::EditRole){
        bool ok{false};
        int row{index.row()};
        int col{index.column()};

        if(col==0 || col == 1)
        {
            int x = value.toInt(&ok);
            if(ok){

                // if(col==0) m_fileUSB->data().at(row).size = x;
                // if(col==1) m_fileUSB->data().at(row).adress = x;

                emit dataChanged(index,index,QVector<int>{Qt::EditRole});
                return true;
            }
        }
        if(col==2)
        {
            // m_fileUSB->data().at(row).name = value.toString().toStdString();
            emit dataChanged(index,index,QVector<int>{Qt::EditRole});
            return true;
        }
    }

    return true;
}

QVariant ModelMeasure::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation==Qt::Horizontal)
    {
        if(role==Qt::DisplayRole )
        {
            if(section==0){
                QVariant header;
                header="lp";
                return header;
            }
            if(section==1){
                QVariant header;
                header="Time";
                return header;
            }
            if(section==2){
                QVariant header;
                header="Name";
                return header;
            }
            if(section==3){
                QVariant header;
                header="ImagePath";
                return header;
            }
            if(section==4){
                QVariant header;
                header="Check";
                return header;
            }
            if(section==5){
                QVariant header;
                header="Desc";
                return header;
            }
            if(section==6){
                QVariant header;
                header="Thumb";
                return header;
            }
        }
        else if(role == Qt::SizeHintRole)
		{
				QSize size(100, 20);
				if (section == 0)
				{
					size.setWidth(300);
				}

				return QVariant(size);
        }
    }

#ifdef LATER
    if(role==Qt::DisplayRole && orientation==Qt::Vertical){
        return QString ("%1").arg(section+1);
    }
#endif
    return QVariant();
}

Qt::ItemFlags ModelMeasure::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flag = QAbstractItemModel::flags(index);

    // if(index.column()<3)
    // {
    //     flag |= Qt::ItemIsEditable;
    //     return flag;
    // }

    return flag;
}

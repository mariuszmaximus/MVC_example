#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

#include "delegate001.h"
#include "delegate002.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    model = new ModelMeasure(this,&m_data);

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setItemDelegate(new Delegate001);

    ui->listView->setModel(model);
    ui->listView->setItemDelegate(new Delegate002);


    // //  https://stackoverflow.com/questions/19001933/qt-hide-column-in-qtableview
    // ui->tableView->setColumnHidden(3, true);
    // ui->tableView->setColumnHidden(4, true);
    // //or 
    // ui->tableView->horizontalHeader()->hideSection(3); 
    // ui->tableView->horizontalHeader()->hideSection(4); 


    ui->listView->setViewMode(QListView::ViewMode::IconMode);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //const QModelIndexList indexes = model->selectedRows();//

    // for (QModelIndex index : indexes) {
    //     // int row = proxy->mapToSource(index).row();
    //     // model->removeRows(row, 1, QModelIndex());
    // }    

    model->removeRows(1,1, QModelIndex());
    qDebug() << "delete?";
}


#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    auto model = new ModelMeasure(this,&m_data);

    ui->tableView->setModel(model);
    ui->listView->setModel(model);
 
    // //  https://stackoverflow.com/questions/19001933/qt-hide-column-in-qtableview
    // ui->tableView->setColumnHidden(3, true);
    // ui->tableView->setColumnHidden(4, true);
    // //or 
    // ui->tableView->horizontalHeader()->hideSection(3); 
    // ui->tableView->horizontalHeader()->hideSection(4); 


    // ui->listView->setViewMode(QListView::ViewMode::IconMode);
}

Widget::~Widget()
{
    delete ui;
}


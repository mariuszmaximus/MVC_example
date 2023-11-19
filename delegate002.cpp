
#include "delegate002.h"

#include <fmt/core.h>
#include <QPainter>
#include <QDebug>

//! [0]
void Delegate002::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{

    // fmt::print("Delegate002::paint, index.column()={} index.row()={}\n", index.column(), index.row());
    



    if(index.column()==0)
    {
        qDebug() << index.row();
        qDebug() << option.rect;
        qDebug() << index.data();
        qDebug() << "option.state="<<option.state;
        if (option.state & QStyle::State_Selected)
         {
            qDebug() << "SELECTED";

         }
        qDebug() << "__";

        auto r = option.rect;
        r.setSize(QSize(r.width()-1, r.height()-1));

        // painter->fillRect(option.rect, Qt::red);
        auto filename = fmt::format("image{}.bmp", index.row()); 
        QImage img(QString::fromStdString(filename));
        painter->drawImage(r,img);
    }

    QStyledItemDelegate::paint(painter, option, index);





    // if (index.data().canConvert<StarRating>()) {
    //     StarRating starRating = qvariant_cast<StarRating>(index.data());

    //     if (option.state & QStyle::State_Selected)
    //         painter->fillRect(option.rect, option.palette.highlight());

    //     starRating.paint(painter, option.rect, option.palette,
    //                      StarRating::EditMode::ReadOnly);
    // } else {
    //     QStyledItemDelegate::paint(painter, option, index);
    // }
//! [0]
}

//! [1]
QSize Delegate002::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    return QSize(200,200);
    // if (index.data().canConvert<StarRating>()) {
    //     StarRating starRating = qvariant_cast<StarRating>(index.data());
    //     return starRating.sizeHint();
    // }
    // return QStyledItemDelegate::sizeHint(option, index);
}
//! [1]

//! [2]
QWidget *Delegate002::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{
    // if (index.data().canConvert<StarRating>()) {
    //     StarEditor *editor = new StarEditor(parent);
    //     connect(editor, &StarEditor::editingFinished,
    //             this, &StarDelegate::commitAndCloseEditor);
    //     return editor;
    // }
    return QStyledItemDelegate::createEditor(parent, option, index);
}
//! [2]

//! [3]
void Delegate002::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    QStyledItemDelegate::setEditorData(editor, index);

    // if (index.data().canConvert<StarRating>()) {
    //     StarRating starRating = qvariant_cast<StarRating>(index.data());
    //     StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
    //     starEditor->setStarRating(starRating);
    // } else {
    //     QStyledItemDelegate::setEditorData(editor, index);
    // }
}
//! [3]

//! [4]
void Delegate002::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);

    // if (index.data().canConvert<StarRating>()) {
    //     StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
    //     model->setData(index, QVariant::fromValue(starEditor->starRating()));
    // } else {
    //     QStyledItemDelegate::setModelData(editor, model, index);
    // }
}
//! [4]

//! [5]
void Delegate002::commitAndCloseEditor()
{
    // StarEditor *editor = qobject_cast<StarEditor *>(sender());
    // emit commitData(editor);
    // emit closeEditor(editor);
}
//! [5]

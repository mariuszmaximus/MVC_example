
#include "delegate001.h"

#include <QPainter>

//! [0]
void Delegate001::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{

    if(index.column()==2)
    {
        painter->fillRect(option.rect, Qt::red);
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
QSize Delegate001::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    // if (index.data().canConvert<StarRating>()) {
    //     StarRating starRating = qvariant_cast<StarRating>(index.data());
    //     return starRating.sizeHint();
    // }
    return QStyledItemDelegate::sizeHint(option, index);
}
//! [1]

//! [2]
QWidget *Delegate001::createEditor(QWidget *parent,
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
void Delegate001::setEditorData(QWidget *editor,
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
void Delegate001::setModelData(QWidget *editor, QAbstractItemModel *model,
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
void Delegate001::commitAndCloseEditor()
{
    // StarEditor *editor = qobject_cast<StarEditor *>(sender());
    // emit commitData(editor);
    // emit closeEditor(editor);
}
//! [5]

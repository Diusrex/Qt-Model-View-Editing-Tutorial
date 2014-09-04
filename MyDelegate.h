#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>

// Note: This class will only work when the used model is MyModel
class MyDelegate : public QStyledItemDelegate
{
public:
    MyDelegate(QObject *parent = 0);

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const override;
};

#endif // MYDELEGATE_H
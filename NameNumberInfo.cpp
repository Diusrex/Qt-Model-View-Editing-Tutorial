#include "NameNumberInfo.h"

#include <QLineEdit>
#include <QSpinBox>

QVariant NameNumberInfo::GetData(int column) const
{
    switch (column)
    {
    case NAME_COLUMN:
        return name;

    case NUMBER_COLUMN:
        return number;

    default:
        return QVariant();
    }
}

void NameNumberInfo::DataChanged(const int & column, const QVariant & value)
{
    switch (column)
    {
    case NAME_COLUMN:
        name = value.toString();
        break;

    case NUMBER_COLUMN:
        number = value.toInt();
        break;

    default:
        // Do nothing
        break;
    }
}

bool NameNumberInfo::CanBeChanged(const int & column) const
{
    return (column == NAME_COLUMN || column == NUMBER_COLUMN);
}

QWidget* NameNumberInfo::CreateEditor(QWidget *parent, const int & column) const
{
    switch (column)
    {
    case NAME_COLUMN:
        return new QLineEdit(parent);

    case NUMBER_COLUMN:
        return new QSpinBox(parent);

    default:
        return nullptr;
    }
}

void NameNumberInfo::SetEditorData(QWidget *editor, const int & column) const
{
    switch (column)
    {
    case NAME_COLUMN:
    {
        QLineEdit * lineEdit = static_cast<QLineEdit *>(editor);
        lineEdit->setText(name);
        break;
    }

    case NUMBER_COLUMN:
    {
        QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
        spinBox->setValue(number);
        spinBox->setMinimum(minimum);
        spinBox->setMaximum(maximum);
        break;
    }

    default:
        // Do nothing
        break;
    }
}

void NameNumberInfo::SetDataFromEditor(QWidget * editor, int column)
{
    switch (column)
    {
    case NAME_COLUMN:
    {
        QLineEdit * lineEdit = static_cast<QLineEdit *>(editor);
        DataChanged(column, lineEdit->text());
        break;
    }

    case NUMBER_COLUMN:
    {
        QSpinBox * spinBox = static_cast<QSpinBox *>(editor);
        DataChanged(column, spinBox->value());
        break;
    }
    }
}

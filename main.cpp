#include "MyDelegate.h"
#include "MyModel.h"
#include "NameNumberInfo.h"

#include <QItemEditorFactory>
#include <QHeaderView>
#include <QLineEdit>
#include <QSpinBox>
#include <QStandardItemEditorCreator>
#include <QtWidgets/QApplication>
#include <QTableView>

void ChangeQItemEditorFactory();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView table;

    // Basic and optional formatting for the table and its headers.
    // table.setShowGrid(false);

    // table.verticalHeader()->setVisible(false);
    // table.horizontalHeader()->setVisible(false);
    // table.horizontalHeader()->setStretchLastSection(true);

    std::vector<std::unique_ptr<DataRow>> numbers;
    numbers.push_back(std::unique_ptr<DataRow>(new NameNumberInfo("Row 1", 0, -1, 20)));
    numbers.push_back(std::unique_ptr<DataRow>(new NameNumberInfo("Row 2", 1, 1, 5)));

    MyModel model = MyModel(numbers);
    table.setModel(&model);

    MyDelegate delegate = MyDelegate(&table);
    table.setItemDelegate(&delegate);

    ChangeQItemEditorFactory();

    table.show();

    return a.exec();
}


void ChangeQItemEditorFactory()
{
    QItemEditorFactory * factory = new QItemEditorFactory;

    QItemEditorCreatorBase * stringEditor = new QStandardItemEditorCreator<QLineEdit>();
    factory->registerEditor(QVariant::String, stringEditor);

    QItemEditorCreatorBase * intEditor = new QStandardItemEditorCreator<QSpinBox>();
    factory->registerEditor(QVariant::Int, intEditor);

    QItemEditorFactory::setDefaultFactory(factory);
}
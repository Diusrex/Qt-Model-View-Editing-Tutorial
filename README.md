Qt Model/View Editing Tutorial
============================

This repository is for my tutorial on how to improve the editing functionality when using a view and model.

It is built upon the code for my [Qt TableModel Implementation](https://github.com/Diusrex/qt-tablemodel-implementation).

This branch (DelegateImplementation) contains editing customizations throught the use of a delegate and QItemEditorFactory.

The other branch (DelegateCreatesEditor) contains editing customization through solely the use of a delegate.

Requirements to Run
============================

A working installation of Qt 5.

c++11 (or could remove the unique_ptr and replace it with a normal pointer).
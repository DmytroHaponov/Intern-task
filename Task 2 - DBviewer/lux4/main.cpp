/**
    main.cpp
    Purpose: launch the program

    @author Dmytro Haponov
    @version 1.2 3/08/15
*/

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

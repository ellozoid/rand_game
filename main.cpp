#include "rand_game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rand_game w;
    w.setWindowTitle("Rand Game Test (Graphics View)");
    w.show();
    return a.exec();
}

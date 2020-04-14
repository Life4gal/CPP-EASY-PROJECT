#include <QApplication>

#include <ctime>
#include <cstdlib>

#include "GUI/GameBoard.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    srand(static_cast<unsigned int>(time(nullptr)));

    GUI::GameBoard board1(nullptr, 4);
    //GUI::GameBoard board2(nullptr, 8);

    board1.show();
    //board2.show();

    return app.exec();
}

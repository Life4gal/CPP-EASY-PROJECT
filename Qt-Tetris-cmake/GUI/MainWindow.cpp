#include "MainWindow.h"

using namespace GUI;

MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent), gameBoard(new GameBoard(this))
{
    setCentralWidget(gameBoard);
}

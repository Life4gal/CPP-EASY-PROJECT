#ifndef QT_TETRIS_MAINWINDOW_H
#define QT_TETRIS_MAINWINDOW_H

#include <QMainWindow>

#include "GameBoard.h"

namespace GUI
{

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    GameBoard* gameBoard;
};

}

#endif //QT_TETRIS_MAINWINDOW_H

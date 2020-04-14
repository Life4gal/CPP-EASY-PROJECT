#ifndef GUI_MAINWINDOW_H
#define GUI_MAINWINDOW_H

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

#endif //GUI_MAINWINDOW_H

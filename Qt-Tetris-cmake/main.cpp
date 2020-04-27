#include <QApplication>

#include "GUI/GameBoard.h"

/*
	@TODO 问题：某些图形在靠右边旋转的时候会发生越界问题，尚不明确为何有些图形边界矫正有效有的无效。
*/

int main(int argc, char** argv)
{
    constexpr const int WIDTH = 10;
    constexpr const int HEIGHT = 20;
    QApplication app(argc, argv);

    GUI::GameBoard board(nullptr, WIDTH, HEIGHT);

    board.show();

    return app.exec();
}

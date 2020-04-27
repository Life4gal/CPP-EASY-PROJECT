#include "GameOverWindow.h"

using namespace GUI;

GUI::GameOverWindow::GameOverWindow(QWidget *parent)
                    : QWidget(parent), reset(new ResetButton(this))
{
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "GameOverWindow");

    setStyleSheet(".GameOverWindow { background: rgb(237,224,200); }");
    setFixedSize(425,205);
    auto* layout = new QVBoxLayout(this);

    auto* game_over = new QLabel("Game Over", this);
    game_over->setStyleSheet("QLabel { color: rgb(119,110,101); font: 40pt; font: bold;} ");

    reset->setFixedSize(50, 100);

    layout->insertWidget(0, game_over, 0, Qt::AlignCenter);
    layout->insertWidget(1, reset, 0, Qt::AlignCenter);
}

GUI::ResetButton *GUI::GameOverWindow::getResetButton() const
{
    return reset;
}

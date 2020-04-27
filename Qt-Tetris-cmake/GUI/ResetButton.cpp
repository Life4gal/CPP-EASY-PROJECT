#include "ResetButton.h"

using namespace GUI;

ResetButton::ResetButton(QWidget *parent)
                : QLabel(parent)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setProperty("class", "ResetButton");

    setText("Try again!");
    setAlignment(Qt::AlignCenter);
    setStyleSheet(".ResetButton { background-color: rgb(143,122,102); border-radius: 10px; font: bold; color: white; }");
}

void ResetButton::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    //QLabel::mousePressEvent(event);
}

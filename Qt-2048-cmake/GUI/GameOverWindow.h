#ifndef GUI_GAMEOVERWINDOW_H
#define GUI_GAMEOVERWINDOW_H

#include <QVBoxLayout>
#include <QLabel>
#include <QResizeEvent>
#include <QVariant>

#include "ResetButton.h"

namespace GUI
{

//游戏结束窗口
class GameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverWindow(QWidget* parent = nullptr);

    //获取管理的重新开始按钮
    [[nodiscard]] ResetButton* getResetButton() const;

private:
    //管理自己的重新开始按钮
    ResetButton* reset;

signals:
public slots:
};




}

#endif //GUI_GAMEOVERWINDOW_H

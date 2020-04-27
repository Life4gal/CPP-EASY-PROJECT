#ifndef QT_TETRIS_GAMEOVERWINDOW_H
#define QT_TETRIS_GAMEOVERWINDOW_H

#include <QVBoxLayout>
#include <QLabel>
#include <QResizeEvent>
#include <QVariant>

#include "ResetButton.h"

namespace GUI
{

class GameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameOverWindow(QWidget* parent = nullptr);

    //获取管理的重新开始按钮
    [[nodiscard]] ResetButton* getResetButton() const;

private:
    // 管理自己的重新开始按钮
    ResetButton* reset;

signals:
public slots:
};

}

#endif //QT_TETRIS_GAMEOVERWINDOW_H

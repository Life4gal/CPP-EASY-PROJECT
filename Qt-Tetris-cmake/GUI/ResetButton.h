#ifndef QT_TETRIS_RESETBUTTON_H
#define QT_TETRIS_RESETBUTTON_H

#include <QLabel>
#include <QVariant>

namespace GUI
{

class ResetButton : public QLabel
{
    Q_OBJECT
public:
    explicit ResetButton(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override ;

signals:
    void clicked();
public slots:
};

}

#endif //QT_TETRIS_RESETBUTTON_H

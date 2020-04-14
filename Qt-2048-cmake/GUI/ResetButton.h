#ifndef GUI_RESETBUTTON_H
#define GUI_RESETBUTTON_H

#include <QLabel>
#include <QVariant>

namespace GUI
{

//重新开始的按钮
class ResetButton : public QLabel
{
    Q_OBJECT
public:
    explicit ResetButton(QWidget* parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();
public slots:
};

}

#endif //GUI_RESETBUTTON_H

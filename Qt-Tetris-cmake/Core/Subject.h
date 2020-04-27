#ifndef QT_TETRIS_SUBJECT_H
#define QT_TETRIS_SUBJECT_H

#include "Observer.h"

#include <QVector>

namespace Core
{

class Subject
{
public:
    //提醒所有观测者
    void notifyObservers();
    //添加新的观测者
    void registerObserver(Observer* observer);

private:
    //保存观测者，每次行动后提醒观测者进行计算
    QVector<Observer*> observers;
};

}

#endif //QT_TETRIS_SUBJECT_H

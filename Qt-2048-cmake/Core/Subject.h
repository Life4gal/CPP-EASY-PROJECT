#ifndef CORE_SUBJECT_H
#define CORE_SUBJECT_H

#include <QVector>

#include "Observer.h"

namespace Core
{

class Observer;

//观测者管理类，每次行动后负责提醒观测者
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

#endif //CORE_SUBJECT_H

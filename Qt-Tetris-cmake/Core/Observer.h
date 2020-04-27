#ifndef QT_TETRIS_OBSERVER_H
#define QT_TETRIS_OBSERVER_H

namespace Core
{

class Observer
{
public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void notify() = 0;
};

}

#endif //QT_TETRIS_OBSERVER_H

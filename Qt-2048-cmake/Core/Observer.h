#ifndef CORE_OBSERVER_H
#define CORE_OBSERVER_H

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

#endif //CORE_OBSERVER_H

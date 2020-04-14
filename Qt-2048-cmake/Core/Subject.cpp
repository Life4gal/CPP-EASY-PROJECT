#include "Subject.h"

using namespace Core;

void Subject::notifyObservers()
{
    for(Observer* o : observers)
    {
        o->notify();
    }
}

void Subject::registerObserver(Observer* observer)
{
    observers.push_back(observer);
}
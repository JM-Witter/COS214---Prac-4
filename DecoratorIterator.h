#ifndef DECORATORITERATOR_H
#define DECORATORITERATOR_H

#include "Iterator.h"
#include "ProductionComponent.h"

//Placeholder for decorator iterator until it is added 
class DecoratorIterator : public Iterator
{
public:
  void first() override {}
  void next() override {}
  bool isDone() const override { return true; }
  ProductionComponent *currentItem() const override { return nullptr; }
};

#endif

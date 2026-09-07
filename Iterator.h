#ifndef ITERATOR_H
#define ITERATOR_H

class ProductionComponent;

class Iterator 
{
public:
  virtual ~Iterator() {}
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() const = 0;
  virtual ProductionComponent *currentItem() const = 0;
};

#endif

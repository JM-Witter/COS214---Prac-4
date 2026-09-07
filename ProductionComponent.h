#ifndef PRODUCTIONCOMPONENT_H
#define PRODUCTIONCOMPONENT_H

#include <string>

class Iterator; // Added for access to vector

class ProductionComponent
{
protected:
  std::string name;

public:
  ProductionComponent(const std::string &name) : name(name) {};

  virtual ~ProductionComponent() {};

  std::string getName() const
  {
    return name;
  }

  virtual double getDevelopmentCost() const = 0;

  virtual void display(int n) const = 0;

  virtual Iterator *createIterator() {return nullptr;}; // Added for calling DecoratorIterator later

  virtual std::string getProgress() const = 0; //Used to reach decorator objects in iterator

  virtual Iterator *createIterator(const std::string &state) { return nullptr; }
};

#endif
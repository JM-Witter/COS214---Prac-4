#ifndef PRODUCTIONCOMPONENT_H
#define PRODUCTIONCOMPONENT_H

#include <string>

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
};

#endif
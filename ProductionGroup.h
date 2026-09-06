#ifndef PRODUCTION_GROUP_H
#define PRODUCTION_GROUP_H

#include "ProductionComponent.h"
#include <vector>
#include <iostream>

class ProductionGroup : public ProductionComponent
{
private:
  std::vector<ProductionComponent *> children;

public:
  ProductionGroup(const std::string &name) : ProductionComponent(name) {}

  void addChild(ProductionComponent *child)
  {
    if (!child)
    {
      std::cerr << "Error: Cannot add a null child to ProductionGroup." << std::endl;
      return;
    }
    children.push_back(child);
  }

  ProductionComponent *removeChild(const std::string &name)
  {

    std::vector<ProductionComponent *>::iterator it;
    for (it = children.begin(); it != children.end(); ++it)
    {
      if ((*it)->getName() == name)
      {
        ProductionComponent *removedChild = *it;
        children.erase(it);
        return removedChild;
      }
    }
    return nullptr; // Child not found
  }

  double getDevelopmentCost() const override
  {
    double totalCost = 0.0;
    for (const auto &child : children)
    {
      totalCost += child->getDevelopmentCost();
    }
    return totalCost;
  }

  void display(int depth) const
  {
    std::vector<ProductionComponent *>::const_iterator it;

    std::string indent(depth * 2, ' ');
    std::cout << indent << "[ProductionGroup[]: " << name << std::endl;
    for (it = children.begin(); it != children.end(); ++it)
    {
      (*it)->display(depth + 1);
    }
    std::cout << indent << "]" << std::endl;
  }

  ~ProductionGroup()
  {
    std::vector<ProductionComponent *>::iterator it;

    for (it = children.begin(); it != children.end(); ++it)
    {
      delete *it;
    }
  }
};

#endif
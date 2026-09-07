#ifndef STATEITERATOR_H
#define STATEITERATOR_H

#include "Iterator.h"
#include "ProductionComponent.h"
#include "ProductionGroup.h"
#include <vector>
#include <string>
#include <cstddef>

class StateIterator : public Iterator
{
private:
  std::vector<ProductionComponent *> items;
  std::size_t index;
  std::string targetState;

  void collect(ProductionComponent *node) {
    if (!node) {
      return;
    }

    ProductionGroup *group = dynamic_cast<ProductionGroup *>(node);
    if (group) {
      for (auto it = group->children.begin(); it != group->children.end(); ++it) {
        collect(*it);
      }
    }
    else {
      if (node->getProgress() == targetState) {
        items.push_back(node);
      }
    }
  }

public:
  StateIterator(ProductionComponent *root, const std::string &targetState)
      : index(0), targetState(targetState) {
        collect(root);
    }

  void first() override { index = 0; }
  void next() override { if (!isDone()) ++index; }
  bool isDone() const override { return index >= items.size(); }
  ProductionComponent *currentItem() const override {
    return isDone() ? nullptr : items[index];
  }
};

inline Iterator *ProductionGroup::createIterator(const std::string &state) {
    return new StateIterator(this, state);
}

#endif
#ifndef FULLTRAVERSALITERATOR_H
#define FULLTRAVERSALITERATOR_H

#include "Iterator.h"
#include "ProductionComponent.h"
#include <vector>
#include <cstddef>

class ProductionGroup;

class FullTraversalIterator : public Iterator {

private:

  std::vector<ProductionComponent *> items;
  std::size_t index;

  void collect(ProductionComponent *node) {
    if (!node) {
      return;
    }

    items.push_back(node);

    ProductionGroup *group = dynamic_cast<ProductionGroup *>(node);
    if (group) {
      // friend access into ProductionGroup's private children vector
      for (auto it = group->children.begin(); it != group->children.end(); ++it) {
        collect(*it);
      }
    }
  }

public:

  explicit FullTraversalIterator(ProductionComponent *root) : index(0) {
    collect(root);
  }

  void first() override {
    index = 0;
  }

  void next() override {
    if (!isDone())
    {
      ++index;
    }
  }

  bool isDone() const override {
    return index >= items.size();
  }

  ProductionComponent *currentItem() const override {
    return isDone() ? nullptr : items[index];
  }
};

inline Iterator* ProductionGroup::createIterator() {
    return new FullTraversalIterator(this);
}

#endif

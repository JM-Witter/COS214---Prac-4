#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "ProductionComponent.h"
#include <vector>
#include <iostream>

class Production : public ProductionComponent
{
private:
  std::string productionCompany;
  double developmentCost;
  std::vector<std::string> cast;
  std::string credits;
  int numberOfEpisodes;

public:
  Production(const std::string &name, const std::string productionCompany, double developmentCost, int numberOfEpisodes = 0) : ProductionComponent(name), productionCompany(productionCompany), developmentCost(developmentCost), credits("Not set"), numberOfEpisodes(numberOfEpisodes) {}

  void addCastMember(const std::string &person)
  {
    cast.push_back(person);
  }

  void setCredits(const std::string &credits)
  {
    this->credits = credits;
  }

  double getDevelopmentCost() const override
  {
    return developmentCost;
  }

  void display(int depth) const
  {
    std::string indent(depth * 2, ' ');
    std::cout << indent << "[Production[]: " << name << std::endl;
  }

  ~Production() {}
};

#endif
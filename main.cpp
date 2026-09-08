#include <iostream>
#include <iomanip>

#include "Production.h"
#include "ProductionGroup.h"
#include "Iterator.h"
#include "FullTraversalIterator.h"
#include "StateIterator.h"
#include "AvailableDecorator.h"
#include "PlatformDecorator.h"
#include "TheatricalDecorator.h"

int main()
{
    // root
    ProductionGroup *starWars = new ProductionGroup("Star Wars");

    // tv series
    ProductionGroup *tvSeries = new ProductionGroup("TV Series");

    // leaves
    Production *mandalorian = new Production("The Mandalorian",     "Lucasfilm", 15000000.0, 24);
    Production *bobaFett = new Production("The Book of Boba Fett",  "Lucasfilm", 12000000.0, 7);
    Production *acolyte = new Production("The Acolyte",             "Lucasfilm", 10000000.0, 8);

    mandalorian->updateProgress();
    mandalorian->updateProgress();
    mandalorian->updateProgress();

    bobaFett->updateProgress();
    bobaFett->updateProgress();

    acolyte->updateProgress();

    // Added info for the Mandalorian
    mandalorian->addCastMember("Pedro Pascal");
    mandalorian->addCastMember("Giancarlo Esposito");

    mandalorian->setCredits("Created by Jon Favreau");

     // Decorators
    ProductionComponent *mandalorianFilm = new PlatformDecorator(new PlatformDecorator(mandalorian,
        "Disney+", "Disney+ Subscription", 180),
        "Apple TV", "Buy Season 1-3", 300);

    ProductionComponent *bobaFettFilm = new PlatformDecorator(bobaFett, "Disney+", "Disney+ Subscription", 180);
    ProductionComponent *acolyteFilm = new PlatformDecorator(acolyte, "Disney+", "Disney+ Subscription", 180);

    tvSeries->addChild(mandalorianFilm);
    tvSeries->addChild(bobaFettFilm);
    tvSeries->addChild(acolyteFilm);

    // delete acolyteFilm; // testing error

    // animated series, inside tv series
    ProductionGroup *animatedSeries = new ProductionGroup("Animated TV Series");

    animatedSeries->addChild(new Production("The Clone Wars", "Lucasfilm Animation", 8500000.0, 133));
    animatedSeries->addChild(new Production("Rebels",       "Lucasfilm Animation",  6000000.0, 75));
    animatedSeries->addChild(new Production("Resistance",   "Lucasfilm Animation",  3500000.0, 40));

    // Add Composite to another Composite
    tvSeries->addChild(animatedSeries);

    // movies
    ProductionGroup *movies = new ProductionGroup("Movies");

    movies->addChild(new TheatricalDecorator(new Production("The Force Awakens", "Lucasfilm", 18000000.0), "Ster-Kinekor", "2D", 100));
    movies->addChild(new TheatricalDecorator(new TheatricalDecorator(new TheatricalDecorator(new Production("The Empire Strikes Back", "Lucasfilm", 245000000.0), "The", "1D", 100), "Absolute", "2D", 200), "Theater", "3D", 300));

    // build tree
    starWars->addChild(tvSeries);
    starWars->addChild(movies);

    // display tree
    std::cout << "STAR WARS PRODUCTIONS" << std::endl;

    starWars->display(0);

    // full traversal via Iterator
    std::cout << "\nFULL TRAVERSAL (Iterator pattern)" << std::endl;

    Iterator *it = starWars->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
        std::cout << " - " << it->currentItem()->getName() << std::endl;
    }
    std::cout << std::endl;
    delete it;

    // state-filtered traversal via Iterator
    std::cout << "\nPRODUCTIONS CURRENTLY RELEASED" << std::endl;

    Iterator *Released = starWars->createIterator("Released");
    if (Released != nullptr) {
        for (Released->first(); !Released->isDone(); Released->next()) {
            std::cout << " - " << Released->currentItem()->getName()
                      << " (" << Released->currentItem()->getProgress() << ")" << std::endl;
        }
        std::cout << std::endl;
        delete Released;
    }

    // developmen costs
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "DEVELOPMENT COSTS" << std::endl;

    std::cout
        << "The Mandalorian: R"
        << mandalorian->getDevelopmentCost()
        << std::endl;

    std::cout
        << "Animated Series: R"
        << animatedSeries->getDevelopmentCost()
        << std::endl;

    std::cout
        << "TV Series: R"
        << tvSeries->getDevelopmentCost()
        << std::endl;

    std::cout
        << "Movies: R"
        << movies->getDevelopmentCost()
        << std::endl;

    std::cout
        << "Entire Star Wars hierarchy: R"
        << starWars->getDevelopmentCost()
        << std::endl;

    // adding a leaf
    std::cout << "ADDING ROGUE ONE" << std::endl;

    movies->addChild(new Production("Rogue One", "Lucasfilm", 200000000.0));

    std::cout << "\nUpdated hierarchy:" << std::endl;

    starWars->display(0);

    std::cout
        << "\nUpdated total cost: R"
        << starWars->getDevelopmentCost()
        << std::endl;

    // removing
    std::cout << "REMOVING THE FORCE AWAKENS" << std::endl;

    ProductionComponent *removed = movies->removeChild("The Force Awakens");

    if (removed != nullptr)
    {
        std::cout
            << removed->getName()
            << " removed successfully."
            << std::endl;

        // removeChild removed it from the Composite,
        // so movies no longer owns it.
        delete removed;
        removed = nullptr;
    }
    else
    {
        std::cout << "Production was not found." << std::endl;
    }

    std::cout << "\nFinal hierarchy:" << std::endl;

    starWars->display(0);

    std::cout << "\nFinal total cost: R" << starWars->getDevelopmentCost()  << std::endl;

    delete starWars;

    starWars = nullptr;

    return 0;
}
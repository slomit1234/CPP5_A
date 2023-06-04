#include "doctest.h"
#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Test1-Container Test")
{
    MagicalContainer container;

    CHECK(container.size() == 0);
    int ElementsNumA = 2;
    int ElementsNumB = 5;
    // Inserting
    for (int i = 1; i <= ElementsNumA; i++)
    {
        container.addElement(i);
        CHECK(container.size() == i);
    }
    CHECK(container.size() == 2);
    // Removal
    for (int i = 1; i <= ElementsNumB; i++)
    {
        container.removeElement(i);
    }
    CHECK(container.size() == 0);

    // inserting and removing together
    for (int j = 1; j <= ElementsNumB; j++)
    {
        container.addElement(j);
        CHECK(container.size() == 1);
        container.removeElement(j);
        CHECK(container.size() == 0);
    }
}

TEST_CASE("Test2-AscendingIterator")
{
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::AscendingIterator ascenIter(container);

    CHECK(ascenIter == ascenIter.begin());
    for (int i = 0; ascenIter != ascenIter.end(); ++ascenIter, ++i)
    {
        CHECK(*ascenIter == i);
    }
    CHECK(ascenIter == ascenIter.end());
}

TEST_CASE("Test3-SideCrossIterator")
{
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::SideCrossIterator ascenIter(container);

    CHECK(ascenIter == ascenIter.begin());
    for (int i = 0; ascenIter != ascenIter.end(); ++ascenIter, ++i)
    {
        CHECK(*ascenIter == i);
    }
    CHECK(ascenIter == ascenIter.end());
}

TEST_CASE("Test4-PrimeIterator")
{
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator ascenIter(container);

    CHECK(ascenIter == ascenIter.begin());
    for (int i = 0; ascenIter != ascenIter.end(); ++ascenIter, ++i)
    {
        CHECK(*ascenIter == i);
    }
    CHECK(ascenIter == ascenIter.end());
}
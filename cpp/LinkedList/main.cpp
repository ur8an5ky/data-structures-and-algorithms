/*
Journey plan to test Linked List implementation and performance.
*/
#include <iostream>
#include <memory>
#include <string>

#include "linked_list.hpp"

int main()
{
    std::unique_ptr<Node> krakow = std::make_unique<Node>("Krakow", "Poland", 806201);
    std::unique_ptr<List> travelList = std::make_unique<List>(std::move(krakow));

    std::cout<<travelList->getHead()->getName()<<std::endl;

    // nullptr check
    std::unique_ptr<List> travelList2 = std::make_unique<List>();

    std::cout<<travelList2->getHead()<<std::endl;

    return 0;
}
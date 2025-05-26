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

    std::cout<<std::boolalpha;
    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    // List() constructor check
    std::unique_ptr<List> travelList2 = std::make_unique<List>();

    std::cout<<travelList2->front()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList2->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList2->size()<<std::endl<<std::endl;

    // adding more cities into the travel list
    std::unique_ptr<Node> katowice = std::make_unique<Node>("Katowice", "Poland", 279190);
    std::unique_ptr<Node> czestochowa = std::make_unique<Node>("Czestochowa", "Poland", 205969);
    travelList->pushFront(std::move(katowice));
    travelList->pushBack(std::move(czestochowa));

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    // popFront i popBakc
    std::unique_ptr<Node> city1 = travelList->popFront();
    std::cout<<"City popped from front is: "<<city1->getName()<<std::endl;
    std::unique_ptr<Node> city2 = travelList->popBack();
    std::cout<<"City popped from back is: "<<city2->getName()<<std::endl<<std::endl;

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    return 0;
}
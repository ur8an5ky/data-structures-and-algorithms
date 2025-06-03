/*
Journey plan to test Linked List implementation and performance.
*/
#include <iostream>
#include <memory>
#include <string>

#include "linked_list.hpp"

// TO DO: TESTY, WYJATKI (exceptions), REFACTOR, przeladowanie operatorow (do wypisywania zawartosci)

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
    std::unique_ptr<List> emptyList = std::make_unique<List>();

    std::cout<<emptyList->front()<<std::endl;
    std::cout<<"Is the travel list empty? "<<emptyList->empty()<<std::endl<<
                "The size of the travel list is: "<<emptyList->size()<<std::endl<<std::endl;

    // adding more cities into the travel list
    std::unique_ptr<Node> katowice = std::make_unique<Node>("Katowice", "Poland", 279190);
    std::unique_ptr<Node> czestochowa = std::make_unique<Node>("Czestochowa", "Poland", 205969);
    travelList->pushFront(std::move(katowice));
    travelList->pushBack(std::move(czestochowa));

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    // popFront i popBack
    std::unique_ptr<Node> city1 = travelList->popFront();
    std::cout<<"City popped from front is: "<<city1->getName()<<std::endl;
    std::unique_ptr<Node> city2 = travelList->popBack();
    std::cout<<"City popped from back is: "<<city2->getName()<<std::endl;

    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    // removeFront i removeBack
    std::unique_ptr<Node> wroclaw = std::make_unique<Node>("Wroclaw", "Poland", 673743);
    std::unique_ptr<Node> poznan = std::make_unique<Node>("Poznan", "Poland", 538439);
    travelList->pushFront(std::move(wroclaw));
    travelList->pushBack(std::move(poznan));

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    travelList->removeFront();
    travelList->removeBack();

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    // edgecases
    std::cout<<emptyList->front()<<std::endl;
    std::unique_ptr<Node> noCity1 = emptyList->popFront();
    std::unique_ptr<Node> noCity2 = emptyList->popFront();
    std::cout<<std::endl;

    // insert
    std::unique_ptr<Node> oswiecim = std::make_unique<Node>("Oswiecim", "Poland", 35577);
    std::unique_ptr<Node> zakopane = std::make_unique<Node>("Zakopane", "Poland", 25204);
    std::unique_ptr<Node> wieliczka = std::make_unique<Node>("Wieliczka", "Poland", 27845);
    travelList->pushFront(std::move(oswiecim));
    travelList->pushBack(std::move(zakopane));

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;

    travelList->insert(std::move(wieliczka), 2);

    std::cout<<travelList->front()->getName()<<std::endl;
    std::cout<<travelList->back()->getName()<<std::endl;
    std::cout<<"Is the travel list empty? "<<travelList->empty()<<std::endl<<
                "The size of the travel list is: "<<travelList->size()<<std::endl<<std::endl;    
    
    return 0;
}
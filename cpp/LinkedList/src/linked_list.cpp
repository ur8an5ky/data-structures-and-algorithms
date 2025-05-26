#include "linked_list.hpp"

Node::Node(std::string name, std::string country, unsigned int population, std::unique_ptr<Node> next)
{
    this->name = name;
    this->country = country;
    this->population = population;
    this->next = std::move(next);
}

const std::string& Node::getName() const
{
    return this->name;
}

const std::string& Node::getCountry() const
{
    return this->country;
}

const unsigned int& Node::getPopulation() const
{
    return this->population;
}

Node* Node::getNext()
{
    return this->next.get();
}

/*######################################################*/
/*                          List                        */
/*######################################################*/

List::List(std::unique_ptr<Node> city)
{
    this->size = 1;
    this->head = std::move(city);
}

Node* List::getHead() const
{
    return this->head.get();
}

Node* List::back() const
{
    Node* result = this->front();
    while(result->getNext())
    {
        result = result->getNext();
    }
    return result;
}
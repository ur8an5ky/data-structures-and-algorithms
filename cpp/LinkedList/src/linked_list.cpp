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

std::unique_ptr<Node> Node::popNext()
{
    return std::move(next);
}

void Node::setNext(std::unique_ptr<Node> next)
{
    this->next = std::move(next);
}

/*######################################################*/
/*                          List                        */
/*######################################################*/

List::List(std::unique_ptr<Node> city)
{
    this->listSize = 1;
    this->head = std::move(city);
}

bool List::empty() const
{
    return listSize == 0;
}

size_t List::size() const
{
    return this->listSize;
}

Node* List::front() const
{
    return this->head.get();
}

Node* List::back() const
{
    Node* result = this->front();
    if(this->empty())
    {
        return nullptr;
    }
    
    while(result->getNext())
    {
        result = result->getNext();
    }
    return result;
}

void List::pushFront(std::unique_ptr<Node> city)
{
    city->setNext(std::move(this->head));
    this->head = std::move(city);
    listSize++;
}

std::unique_ptr<Node> List::popFront()
{
    if(this->empty())
    {
        // jakies wyjatki
        std::cout<<"There is nothing to pop! The List is empty!"<<std::endl;
        return nullptr;
    }

    std::unique_ptr<Node> result = std::move(this->head);
    this->head = std::move(result->popNext());
    listSize--;

    return result;
}

void List::pushBack(std::unique_ptr<Node> city)
{
    Node* tmp = this->front();
    while(tmp->getNext())
    {
        tmp = tmp->getNext();
    }
    tmp->setNext(std::move(city));
    listSize++;
}

std::unique_ptr<Node> List::popBack()
{
    if(this->empty())
    {
        // jakies wyjatki
        std::cout<<"There is nothing to pop! The List is empty!"<<std::endl;
        return nullptr;
    }

    Node* current = this->front();
    Node* prev = nullptr;

    while(current->getNext())
    {
        prev = current;
        current = current->getNext();
    }

    std::unique_ptr<Node> result = std::move(prev->popNext());
    listSize--;

    return result;
}
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
    this->head = result->popNext();
    listSize--;

    return result;
}

void List::removeFront()
{
    if(this->empty())
    {
        // jakies wyjatki
        std::cout<<"There is nothing to remove! The List is empty!"<<std::endl;
        return;
    }

    this->head = this->head->popNext();
    listSize--;
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

    if (head->getNext() == nullptr)
    {
        std::unique_ptr<Node> result = std::move(head);
        head.reset();
        listSize--;
        return result;
    }

    Node* current = this->front();
    Node* prev = nullptr;

    while(current->getNext())
    {
        prev = current;
        current = current->getNext();
    }

    std::unique_ptr<Node> result = prev->popNext();
    listSize--;

    return result;
}

void List::removeBack()
{
    if(this->empty())
    {
        // jakies wyjatki
        std::cout<<"There is nothing to remove! The List is empty!"<<std::endl;
        return;
    }

    if (head->getNext() == nullptr)
    {
        std::unique_ptr<Node> result = std::move(head);
        head.reset();
        listSize--;
        return;
    }

    Node* current = this->front();
    Node* prev = nullptr;

    while(current->getNext())
    {
        prev = current;
        current = current->getNext();
    }
    prev->setNext(nullptr);
    listSize--;
}

void List::insert(std::unique_ptr<Node> city, size_t idx)
{
    if(this->size() < idx)
    {
        // jakies wyjatki
        std::cout<<"Given index is bigger than the size of a list!"<<std::endl;
        return;
    }

    if(idx == 0)
    {
        this->pushFront(std::move(city));
        return;
    }
    else if(idx == this->size())
    {
        this->pushBack(std::move(city));
        return;
    }

    size_t i = 1;
    Node* current = this->front();
    
    while(i < idx)
    {
        current = current->getNext();
        i++;
    }

    city->setNext(current->popNext());
    current->setNext(std::move(city));
    listSize++;
}
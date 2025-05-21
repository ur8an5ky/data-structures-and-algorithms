#pragma once

#include <iostream>
#include <memory>
#include <string>

class Node
{
    private:
        std::string name;
        std::string country;
        unsigned int population;
        std::unique_ptr<Node> next;

    public:
        // Node();
        // lista inicjalizacyjna
        Node(std::string name, std::string country, unsigned int population, std::unique_ptr<Node> next=nullptr);
        ~Node() = default;
        const std::string& getName() const;
        const std::string& getCountry() const;
        const unsigned int& getPopulation() const;
        // const Node& getNext();
};

class List
{
    private:
        std::unique_ptr<Node> head;
        int size;

    public:
        List(std::unique_ptr<Node> city=nullptr);
        // czy default???
        ~List() = default;
        Node* getHead() const;
        // const Node& getHead();
};
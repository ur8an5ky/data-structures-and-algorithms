#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <cstddef>

class Node
{
    private:
        std::string name;
        std::string country;
        unsigned int population;
        std::unique_ptr<Node> next;

    public:
        Node(std::string name, std::string country, unsigned int population, std::unique_ptr<Node> next=nullptr):
            name(name), country(country), population(population), next(std::move(next)) {}
        ~Node() = default;
        const std::string& getName() const;
        const std::string& getCountry() const;
        const unsigned int& getPopulation() const;
        Node* getNext();
        std::unique_ptr<Node> popNext();
        void setNext(std::unique_ptr<Node> next);
};

class List
{
    private:
        std::unique_ptr<Node> head;
        size_t listSize;

    public:
        List(): head(nullptr), listSize(0) {}
        List(std::unique_ptr<Node> city);
        ~List() = default;

        // capacity
        bool empty() const;
        size_t size() const;

        // element access
        Node* front() const;
        Node* back() const;

        // modifiers
        void pushFront(std::unique_ptr<Node> city);
        std::unique_ptr<Node> popFront();
        void removeFront();
        void pushBack(std::unique_ptr<Node> city);
        std::unique_ptr<Node> popBack();
        void removeBack();
        void insert(std::unique_ptr<Node> city, size_t idx);
};
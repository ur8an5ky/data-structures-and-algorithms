#include <gtest/gtest.h>
#include "linked_list.hpp"

TEST(NodeTest, GettersTest)
{
    Node node("City", "Country", 10000);
    std::unique_ptr<Node> nextNode = std::make_unique<Node>("NextCity", "NextCountry", 100000);

    EXPECT_EQ(node.getName(), "City");
    EXPECT_EQ(node.getCountry(), "Country");
    EXPECT_EQ(node.getPopulation(), 10000);
    EXPECT_EQ(node.getNext(), nullptr);

    node.setNext(std::move(nextNode));
    EXPECT_NE(node.getNext(), nullptr);
    
    Node* next = node.getNext();
    ASSERT_NE(next, nullptr);
    EXPECT_EQ(next->getName(), "NextCity");
    EXPECT_EQ(next->getCountry(), "NextCountry");
    EXPECT_EQ(next->getPopulation(), 100000);
    EXPECT_EQ(next->getNext(), nullptr);
}

TEST(NodeTest, PopNextTest)
{
    Node node("City", "Country", 10000);
    std::unique_ptr<Node> nextNode = std::make_unique<Node>("PoppedCity", "PoppedCountry", 10000);
    node.setNext(std::move(nextNode));

    EXPECT_NE(node.getNext(), nullptr);

    std::unique_ptr<Node> poppedNode = node.popNext();
    EXPECT_EQ(node.getNext(), nullptr);

    ASSERT_NE(poppedNode, nullptr);
    EXPECT_EQ(poppedNode->getName(), "PoppedCity");
    EXPECT_EQ(poppedNode->getCountry(), "PoppedCountry");
    EXPECT_EQ(poppedNode->getPopulation(), 10000);
    EXPECT_EQ(poppedNode->getNext(), nullptr);
}

TEST(ListTest, EmptyListTest)
{
    List testList;

    EXPECT_TRUE(testList.empty());
    EXPECT_EQ(testList.size(), 0);
    EXPECT_EQ(testList.front(), nullptr);
    EXPECT_EQ(testList.back(), nullptr);
}

TEST(ListTest, OneElementListTest)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>("NewCity", "NewCountry", 30000);
    List testList(std::move(newNode));

    EXPECT_FALSE(testList.empty());
    EXPECT_EQ(testList.size(), 1);

    EXPECT_NE(testList.front(), nullptr);
    EXPECT_EQ(testList.front()->getName(), "NewCity");
    EXPECT_EQ(testList.front()->getCountry(), "NewCountry");
    EXPECT_EQ(testList.front()->getPopulation(), 30000);

    EXPECT_NE(testList.back(), nullptr);
    EXPECT_EQ(testList.back()->getName(), "NewCity");
    EXPECT_EQ(testList.back()->getCountry(), "NewCountry");
    EXPECT_EQ(testList.back()->getPopulation(), 30000);
}

TEST(ListTest, PushingToTheListTest)
{
    std::unique_ptr<Node> city1 = std::make_unique<Node>("City1", "Country1", 1000);
    std::unique_ptr<Node> city2 = std::make_unique<Node>("City2", "Country2", 2000);
    std::unique_ptr<Node> city3 = std::make_unique<Node>("City3", "Country3", 3000);
    List testList(std::move(city2));

    testList.pushFront(std::move(city1));
    testList.pushBack(std::move(city3));
    
    EXPECT_FALSE(testList.empty());
    EXPECT_EQ(testList.size(), 3);

    EXPECT_NE(testList.front(), nullptr);
    EXPECT_EQ(testList.front()->getName(), "City1");
    EXPECT_EQ(testList.front()->getCountry(), "Country1");
    EXPECT_EQ(testList.front()->getPopulation(), 1000);

    EXPECT_NE(testList.back(), nullptr);
    EXPECT_EQ(testList.back()->getName(), "City3");
    EXPECT_EQ(testList.back()->getCountry(), "Country3");
    EXPECT_EQ(testList.back()->getPopulation(), 3000);
}

TEST(ListTest, PoppingFromTheListTest)
{
    std::unique_ptr<Node> city1 = std::make_unique<Node>("City1", "Country1", 1000);
    std::unique_ptr<Node> city2 = std::make_unique<Node>("City2", "Country2", 2000);
    std::unique_ptr<Node> city3 = std::make_unique<Node>("City3", "Country3", 3000);
    List testList(std::move(city1));

    testList.pushBack(std::move(city2));
    testList.pushBack(std::move(city3));

    EXPECT_FALSE(testList.empty());
    EXPECT_EQ(testList.size(), 3);

    std::unique_ptr<Node> frontPoppedCity = testList.popFront();
    EXPECT_EQ(testList.size(), 2);

    std::unique_ptr<Node> backPoppedCity = testList.popBack();
    EXPECT_EQ(testList.size(), 1);

    EXPECT_NE(frontPoppedCity, nullptr);
    EXPECT_EQ(frontPoppedCity->getName(), "City1");
    EXPECT_EQ(frontPoppedCity->getCountry(), "Country1");
    EXPECT_EQ(frontPoppedCity->getPopulation(), 1000);

    EXPECT_NE(backPoppedCity, nullptr);
    EXPECT_EQ(backPoppedCity->getName(), "City3");
    EXPECT_EQ(backPoppedCity->getCountry(), "Country3");
    EXPECT_EQ(backPoppedCity->getPopulation(), 3000);
}
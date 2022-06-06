// Homework 2 Problem 3 Data Structures
// Braden Owens
// 5/23/2022
//This is a program that will test the behavior of our bag class.

#include <vector> 
#include <gtest/gtest.h>
#include "bag.h"
// TEST: Confirm default constructor behaves correctly
TEST(BagUnitTests, DefaultConstructor) {
	Bag<int>* aBag = new Bag<int>();
	EXPECT_FALSE(aBag == nullptr);
	EXPECT_EQ(aBag->size(), 0);
	EXPECT_EQ(aBag->count(42), 0);
	delete aBag;
}


TEST(BagUnitests, InsertNewThing) {
	Bag<int>* aBag = new Bag<int>();
	EXPECT_FALSE(aBag == nullptr);
	EXPECT_EQ(aBag->size(), 0);
	EXPECT_EQ(aBag->count(10), 0);
	aBag->insert(42);
	EXPECT_EQ(aBag->size(), 1);
	EXPECT_EQ(aBag->count(42), 1);
	aBag->insert(59);
	EXPECT_EQ(aBag->size(), 2);
	EXPECT_EQ(aBag->count(59), 1);
	delete aBag;

}
#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "add.hpp"
#include "mult.hpp"

TEST(AddTest, AddEvaluationNineAndThreePtFive){
   Op* op1 = new Op(9);
   Op* op2 = new Op(3.5);
   Add* test = new Add(op1, op2);
   EXPECT_EQ(test->evaluate(), 12.5);
}

TEST(AddTest, AddStringThreePtThirtyThreeAndSeven){
   Op* op1 = new Op(3.33);
   Op* op2 = new Op(7);
   std::string result = "3.33 + 7";
   Add* test = new Add(op1, op2);
   EXPECT_EQ(test->stringify(), result);
}

TEST(AddTest, AddEvaluateFromMult){
   Op* op1 = new Op(1);
   Op* op2 = new Op(4);
   Mult* mult1 = new Mult(op1, op2);
   Op* op3 = new Op(20);
   Add* test = new Add(mult1, op3);
   EXPECT_EQ(test->evaluate(), 24);
}

TEST(AddTest, AddStringFromMult){
   Op* op1 = new Op(1);
   Op* op2 = new Op(4); 
   Mult* mult1 = new Mult(op1, op2);
   Op* op3 = new Op(20);
   Add* test = new Add(mult1, op3);
   std::string result = "1 * 4 + 20";
   EXPECT_EQ(test->stringify(), result);
}


TEST(AddTest, AddEvaluateTwoMults){
   Op* op1 = new Op(2.0);
   Op* op2 = new Op(4.5);
   Op* op3 = new Op(1.2);
   Op* op4 = new Op(3.6);
   Mult* mult1 = new Mult(op1, op2);
   Mult* mult2 = new Mult(op3, op4);
   Add* test = new Add(mult1, mult2);
   EXPECT_EQ(test->evaluate(), 13.32);
}

#endif

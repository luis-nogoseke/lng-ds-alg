#include "stack.h"
#include "gtest/gtest.h"

TEST(Stack, isEmptyOnInit)
{
    lnfData::Stack<int> s;
    EXPECT_TRUE(s.empty());
}

TEST(Stack, PushAndPop)
{
    lnfData::Stack<int> s;
    s.push(5);
    EXPECT_EQ(5, s.pop());
    EXPECT_TRUE(s.empty());
}


TEST(Stack, CheckSize)
{
  lnfData::Stack<int> s;
  EXPECT_EQ(0U, s.size());
  for (int i = 0; i < 20; ++i){
    s.push(i);
  }
  EXPECT_EQ(20U, s.size());
  for (int i = 0; i < 20; ++i){
    s.pop();
  }
  EXPECT_EQ(0U, s.size());
}

TEST(Stack, Peek)
{
  lnfData::Stack<int> s;
  for (int i = 0; i < 20; ++i){
    s.push(i);
  }
  EXPECT_EQ(20U, s.size());
  EXPECT_EQ(19, s.peek());
  EXPECT_EQ(20U, s.size());
  for (int i = 0; i < 20; ++i){
    s.pop();
  }
  EXPECT_THROW(s.peek(), std::out_of_range);
}

TEST(Stack, PopEmpty)
{
  lnfData::Stack<int> s;
  EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(Stack, Allocate)
{
  lnfData::Stack<int> s;
  EXPECT_EQ(0U, s.size());
  for (int i = 0; i < 1000; ++i){
    s.push(i);
  }
  EXPECT_EQ(1000U, s.size());
  for (int i = 0; i < 1000; ++i){
    s.pop();
  }
  EXPECT_EQ(0U, s.size());
}

TEST(Stack, Stacking)
{
  lnfData::Stack<int> s;
  for (int i = 0; i < 20; ++i){
    s.push(i);
  }
  for (int i = 19; i >= 0; --i){
    EXPECT_EQ(i, s.pop());
  }
}
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

}

TEST(Stack, PopEmpty)
{
  lnfData::Stack<int> s;
  EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(Stack, Allocate)
{
  lnfData::Stack<int> s;
  s.push(37);
  EXPECT_EQ(37, s.peek());
  s.push(37);
  s.push(40);
  s.push(42);
  EXPECT_EQ(42, s.peek());
  s.pop();
  EXPECT_EQ(40, s.peek());
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
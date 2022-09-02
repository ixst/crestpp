#include "gtest/gtest.h"

#include "crestpp/protocol.hh"


using namespace crestpp;

TEST(Protocol, equal) {
  auto h1 = Protocol::h1;
  auto h2 = Protocol::h2;

  EXPECT_EQ(h1, Protocol::h1);
  EXPECT_NE(h1, h2);
}

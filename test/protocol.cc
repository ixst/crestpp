#include "gtest/gtest.h"

#include "crestpp/protocol.hh"


using namespace crestpp;

TEST(Protocol, port) {
  EXPECT_EQ(Protocol::h1c.port, 80);
  EXPECT_EQ(Protocol::h1.port, 443);
  EXPECT_EQ(Protocol::h2c.port, 80);
  EXPECT_EQ(Protocol::h2.port, 443);
  EXPECT_EQ(Protocol::h3.port, 443);
}

TEST(Protocol, equal) {
  auto h1c1 = Protocol::h1c;
  auto h1c2 = Protocol::h1c;
  auto h2c = Protocol::h2c;
  EXPECT_EQ(h1c1, Protocol::h1c);
  EXPECT_EQ(h1c2, Protocol::h1c);
  EXPECT_EQ(h1c1, h1c2);
  EXPECT_NE(Protocol::h1c, Protocol::h2c);
  EXPECT_NE(h1c1, Protocol::h2c);
  EXPECT_NE(h1c1, h2c);
}

#include "gtest/gtest.h"
#include "crestpp/path.hh"


using namespace crestpp;

TEST(Path, str1) {
  Path path("/");
  EXPECT_EQ(path.str(), "/");
}

TEST(Path, str2) {
  Path path("/p1/p2");
  EXPECT_EQ(path.str(), "/p1/p2");
}

TEST(Path, append) {
  Path path("p1/p2");
  path << ("p3");
  EXPECT_EQ(path, "p1/p2/p3");
}

TEST(Path, equal1) {
  Path path("/p1");
  EXPECT_NE(path, "/p1/p2");
}

TEST(Path, equal2) {
  Path path("/p1/p2");
  EXPECT_NE(path, "/p2/p3");
}

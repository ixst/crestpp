#include "gtest/gtest.h"
#include "crestpp/header/custom.hh"


using namespace crestpp;

TEST(CustomHeader, constructor) {
  std::string name = "name";
  std::string value = "value";
  header::Custom header(name, value);
  EXPECT_EQ(header.name, name);
  EXPECT_EQ(header.value, value);
  EXPECT_EQ(header.serialized_value(), value);
}

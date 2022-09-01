#include "gtest/gtest.h"
#include "crestpp/header/content_length.hh"


using namespace crestpp;

TEST(ContentLengthHeader, constructor) {
  int value = 1024;
  header::ContentLength header(value);
  EXPECT_EQ(header.name, "Content-Length");
  EXPECT_EQ(header.value, 1024);
  EXPECT_EQ(header.serialized_value(), "1024");
}

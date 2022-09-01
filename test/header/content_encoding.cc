#include "gtest/gtest.h"
#include "crestpp/header/content_encoding.hh"


using namespace crestpp;

TEST(ContentEncodingHeader, constructor) {
  header::ContentEncoding header(Encoding::br);
  EXPECT_EQ(header.name, "Content-Encoding");
  EXPECT_EQ(header.encoding, Encoding::br);
  EXPECT_EQ(header.serialized_value(), "br");
}

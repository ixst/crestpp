#include "gtest/gtest.h"
#include "crestpp/encoding.hh"


using namespace crestpp;

TEST(Encoding, str) {
  EXPECT_EQ(Encoding::br.name, "br");
  EXPECT_EQ(Encoding::gzip.name, "gzip");
  EXPECT_EQ(Encoding::deflate.name, "deflate");
}

TEST(Encoding, equal) {
  EXPECT_EQ(Encoding::br, Encoding::br);
  EXPECT_NE(Encoding::br, Encoding::gzip);
}

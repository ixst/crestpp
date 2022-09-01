#include "gtest/gtest.h"
#include "crestpp/header/accept_encoding.hh"


using namespace crestpp;

TEST(AcceptEncodingHeader, constructor) {
  header::AcceptEncoding header(
      { Encoding::br, Encoding::gzip, Encoding::deflate }
  );
  EXPECT_EQ(header.name, "Accept-Encoding");
  EXPECT_EQ(header.encodings.size(), 3);
  EXPECT_EQ(header.encodings[0], Encoding::br);
  EXPECT_EQ(header.encodings[1], Encoding::gzip);
  EXPECT_EQ(header.encodings[2], Encoding::deflate);
  EXPECT_EQ(header.serialized_value(), "br, gzip, deflate");
}

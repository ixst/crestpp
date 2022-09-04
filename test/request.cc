#include "gtest/gtest.h"
#include "crestpp/request.hh"


using namespace crestpp;

TEST(Request, constructor) {
  Request req("/test");
  EXPECT_EQ(req.path, "/test");
}

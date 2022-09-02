#include "gtest/gtest.h"
#include "crestpp/well_known_port.hh"


using namespace crestpp;

TEST(WellKnownPort, constructor) {
  EXPECT_EQ(WellKnownPort::http, 80);
  EXPECT_EQ(WellKnownPort::https, 443);
}

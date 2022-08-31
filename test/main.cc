#include <iostream>

#include "gtest/gtest.h"
#include "chttpp/chttpp.hh"


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  HelloWorld();
  return RUN_ALL_TESTS();
}

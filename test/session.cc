#include "gtest/gtest.h"
#include "crestpp/session.hh"


using namespace crestpp;

TEST(Session, Builder) {
  std::string host = "example.com";
  int port = 80;
  Protocol protocol = Protocol::h1;
  { 
    auto session = Session::Builder(host)
        .port(port)
        .protocols({ protocol })
        .Build();
    
    EXPECT_EQ(session.host, host);
    EXPECT_EQ(session.port, port);
    EXPECT_EQ(session.protocols.size(), 1);
    EXPECT_EQ(session.protocols[0], protocol);
  }
  { 
    int port = 80;
    auto session = Session::Builder(host).Build();
    
    EXPECT_EQ(session.port, port);
    EXPECT_EQ(session.protocols.size(), 1);
    EXPECT_EQ(session.protocols[0], protocol);
  } 
}

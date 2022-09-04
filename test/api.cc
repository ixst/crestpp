#include "gtest/gtest.h"
#include "crestpp/api.hh"
#include "crestpp/session_impl.hh"


using namespace crestpp;

class MockSessionImpl : public SessionImpl {
public:
  MockSessionImpl() noexcept 
      : SessionImpl("example.com", 80, { Protocol::h1 }, "/base/")
  {}

};

TEST(Api, constructor) {
  auto session_impl = std::make_shared<MockSessionImpl>();
  auto api = Api("echo", session_impl);
  EXPECT_EQ(api.path, "/base/echo");
}


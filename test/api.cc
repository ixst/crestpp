#include "gtest/gtest.h"
#include "crestpp/api.hh"
#include "crestpp/session_impl.hh"


using namespace crestpp;

class MockSessionImpl : public SessionImpl {
public:
  MockSessionImpl() noexcept 
      : SessionImpl("example.com", 80, { Protocol::h1 }, "/base/")
  {}


public:
  void Enqueue(
      Request req,
      std::promise<Response>& promise
  ) noexcept override {
  }

  void Enqueue(
      Request req,
      std::function<void(const Response&)> on_response,
      std::function<void(const Error&)> on_error
  ) noexcept override {
    
  }

};

auto session_impl = std::make_shared<MockSessionImpl>();

TEST(Api, constructor1) {
  auto api = Api(session_impl, "echo");
  EXPECT_EQ(api.path, "/base/echo");
}

TEST(Api, constructor2) {
  auto echo = Api(
      session_impl,
      "echo", 
      [&](auto& req) noexcept {
        req.path << 1;
        EXPECT_EQ(req.path, "/base/echo/1");
      }
  );
}

TEST(Api, functor) {
  auto echo = Api(session_impl, "echo");
  echo(
      [&](const auto& res) {

      },
      [&](const auto& error) {

      }
  );
}

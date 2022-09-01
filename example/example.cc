#include <iostream>

#include "crestpp/session.hh"

class App {
public:
  Api test;

public:
  App() noexcept {
    auto session = crestpp::Session::Builder()
      .host("example.com")
      .protocols(
          {
              { Protocol::h1, Protocol::h1.port }, 
              { Protocol::h1c, Protocol::h1c.port },
              { Protocol::h2, Protocol::h2.port },
              { Protocol::h2c, Protocol::h2c.port },
              { Protocol::h3, Protocol::h3.port },
          }
      )
      .Build();
    test = session.Get("/test", [&](auto& req) noexcept {
        auto& query = req.query;
        req.headers =
          header::AcceptEncoding(
              { 
                  encoding::br,
                  encoding::gzip,
                  encoding::deflate
              }
          ) +
          header::Accept( 
              { 
                  mimetype::text.html,
                  mimetype::application.xml,
              }
          )
        req.body = Stream(
            [&](const auto& stream) noexcept {
              std::string text;
              text.reserve(1024);
              memset(text.data(), 'A', 1024);
              for(int i = 0; i < 100; i++) {
                stream << buffer;
              }
            }
        );
      }   
  }

};

int main(int argc, char** argv) {
  {
    std::string content;
    session.test(
        [&](const auto& res) noexcept {
          const auto& status = res.status;
          const auto& headers = res.headers;
          const auto& body = res.body;
          auto future = body.future();
          auto text = future.get();
        } 
    );
  }

  {
    std::stringstream sout;
    session.test(
        [&](const auto& res) noexcept {
          const auto& status = res.status;
          const auto& headers = res.headers;
          const auto& body = res.body;
          body.stream(
              [&](const auto& partial, const auto& size) noexcept {
                sout << partial
              }
          );
        } 
    ).Wait();
  }
      
  return 0;
}

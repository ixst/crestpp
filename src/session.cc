#include "crestpp/session.hh"


namespace crestpp {

Session::Session(
    std::string host,
    int port,
    std::vector<Protocol> protocols
) noexcept 
    : host(std::move(host)),
      port(port),
      protocols(std::move(protocols))
{}



Session::Builder::Builder(std::string host) noexcept 
    : host_(std::move(host)),
      port_(80),
      protocols_({ Protocol::h1 })
{}

Session::Builder& Session::Builder::port(int port) noexcept {
  port_ = port;
  return *this;
}

Session::Builder& Session::Builder::protocols(
    std::vector<Protocol> protocols
) noexcept {
  protocols_ = std::move(protocols);
  return *this;
}

Session Session::Builder::Build() noexcept {
  return Session(host_, port_, protocols_);
}

}

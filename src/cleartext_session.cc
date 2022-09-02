#include "crestpp/cleartext_session.hh"


namespace crestpp {

CleartextSession::CleartextSession(std::shared_ptr<Impl> impl) noexcept
    : Session(impl)
{}



CleartextSession::Impl::Impl(
    std::string host,
    int port,
    std::vector<Protocol> protocols
) noexcept
    : Session::Impl(std::move(host), port, std::move(protocols))
{}



CleartextSession::Builder::Builder(std::string host) noexcept 
    : Session::Builder<CleartextSession>(std::move(host), 80, Protocol::h1)
{}

CleartextSession CleartextSession::Builder::Build() const noexcept {
  return { 
      std::make_shared<CleartextSession::Impl>(host_, port_, protocols_) 
  };
}

}

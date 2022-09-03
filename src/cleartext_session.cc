#include "crestpp/cleartext_session.hh"

#include "cleartext_session_impl.hh"


namespace crestpp {

CleartextSession::CleartextSession(std::shared_ptr<Impl> impl) noexcept
    : Session(impl)
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

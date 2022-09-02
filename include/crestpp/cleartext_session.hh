#ifndef CRESTPP_CLEARTEXT_SESSION_HH__
#define CRESTPP_CLEARTEXT_SESSION_HH__

#include <string>
#include <vector>
#include <memory>

#include "protocol.hh"
#include "session.hh"


namespace crestpp {

class CleartextSession : public Session {
public:
  class Impl;
  class Builder;

public:
  CleartextSession(std::shared_ptr<Impl> impl) noexcept;

};

class CleartextSession::Impl : public Session::Impl {
public:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols
  ) noexcept;

};

class CleartextSession::Builder : public Session::Builder<CleartextSession> {
public:
  Builder(std::string host) noexcept;

public:
  CleartextSession Build() const noexcept override;

};

}


#endif

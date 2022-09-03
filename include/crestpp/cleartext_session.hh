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
  class Builder;

private:
  class Impl;

private:
  CleartextSession(std::shared_ptr<Impl> impl) noexcept;

friend Builder;

};

class CleartextSession::Builder : public Session::Builder<CleartextSession> {
public:
  Builder(std::string host) noexcept;

public:
  CleartextSession Build() const noexcept override;

};

}


#endif

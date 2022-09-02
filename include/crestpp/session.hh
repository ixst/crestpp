#ifndef CRESTPP_SESSION_HH__
#define CRESTPP_SESSION_HH__

#include <vector>
#include <string>

#include "crestpp/protocol.hh"


namespace crestpp {

class Session {
public:
  class Builder;

public:
  const std::string host;
  const int port;
  const std::vector<Protocol> protocols;

public:
  Session(
      std::string host,
      int port,
      std::vector<Protocol> protocols
  ) noexcept;

};

class Session::Builder {
public:
  Builder(std::string host) noexcept;

public:
  Builder& port(int port) noexcept;
  Builder& protocols(std::vector<Protocol> protocols) noexcept;

public:
  Session Build() noexcept;

private:
  std::string host_;
  int port_;
  std::vector<Protocol> protocols_;

};

}


#endif

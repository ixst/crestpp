#ifndef CRESTPP_SESSION_HH__
#define CRESTPP_SESSION_HH__

#include <string>
#include <vector>
#include <memory>

#include "protocol.hh"


namespace crestpp {

class Session {
public:
  class Impl;
  template <class T>
  class Builder;

public:
  const std::string& host;
  const int& port;
  const std::vector<Protocol>& protocols;

public:
  Session(std::shared_ptr<Impl> impl) noexcept;

protected:
  std::shared_ptr<Impl> impl_;

};

class Session::Impl {
public:
  std::string host;
  int port;
  std::vector<Protocol> protocols;

protected:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols
  ) noexcept;

};


template <class T>
class Session::Builder {
public:
  T::Builder& port(int port) noexcept {
    port_ = port;
    return *static_cast<T::Builder*>(this);
  }
  T::Builder& protocols(std::vector<Protocol> protocols) noexcept {
    protocols_ = std::move(protocols);
    return *static_cast<T::Builder*>(this);
  }

public:
  virtual T Build() const noexcept = 0;

protected:
  std::string host_;
  int port_;
  std::vector<Protocol> protocols_;

protected:
  Builder(
      std::string host,
      int default_port,
      Protocol default_protocol
  ) noexcept 
      : host_(std::move(host)),
        port_(default_port),
        protocols_({ default_protocol })
  {}

};

}


#endif

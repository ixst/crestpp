#ifndef CRESTPP_SESSION_IMPL_HH__
#define CRESTPP_SESSION_IMPL_HH__

#include "crestpp/session.hh"


namespace crestpp {

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

}


#endif

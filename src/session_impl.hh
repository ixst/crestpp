#ifndef CRESTPP_SESSION_IMPL_HH__
#define CRESTPP_SESSION_IMPL_HH__

#include <string>
#include <vector>

#include "crestpp/session.hh"
#include "crestpp/protocol.hh"
#include "crestpp/path.hh"


namespace crestpp {

class Session::Impl {
public:
  std::string host;
  int port;
  std::vector<Protocol> protocols;
  Path base_path;

protected:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
  ) noexcept;

};

}


#endif

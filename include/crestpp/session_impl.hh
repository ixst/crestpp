#ifndef CRESTPP_SESSION_IMPL_HH__
#define CRESTPP_SESSION_IMPL_HH__

#include <string>
#include <vector>

#include "protocol.hh"
#include "path.hh"


namespace crestpp {

class SessionImpl {
public:
  std::string host;
  int port;
  std::vector<Protocol> protocols;
  Path base_path;

protected:
  SessionImpl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
  ) noexcept;

};

}


#endif

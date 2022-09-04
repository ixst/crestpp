#ifndef CRESTPP_CLEARTEXT_SESSION_IMPL_HH__
#define CRESTPP_CLEARTEXT_SESSION_IMPL_HH__

#include <string>
#include <vector>

#include "session_impl.hh"
#include "crestpp/path.hh"
#include "crestpp/protocol.hh"
#include "crestpp/cleartext_session.hh"


namespace crestpp {

class CleartextSession::Impl : public Session::Impl {
public:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
  ) noexcept;

};

}


#endif

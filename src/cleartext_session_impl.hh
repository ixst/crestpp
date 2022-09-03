#ifndef CRESTPP_CLEARTEXT_SESSION_IMPL_HH__
#define CRESTPP_CLEARTEXT_SESSION_IMPL_HH__

#include "session_impl.hh"
#include "crestpp/cleartext_session.hh"


namespace crestpp {

class CleartextSession::Impl : public Session::Impl {
public:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols
  ) noexcept;

};

}


#endif

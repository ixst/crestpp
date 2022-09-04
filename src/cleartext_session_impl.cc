#include "cleartext_session_impl.hh"


namespace crestpp {

CleartextSession::Impl::Impl(
    std::string host,
    int port,
    std::vector<Protocol> protocols,
    Path base_path
) noexcept 
    : Session::Impl(
          std::move(host), 
          port, 
          std::move(protocols),
          std::move(base_path)
      )
{}

}

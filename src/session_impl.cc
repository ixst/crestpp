#include "session_impl.hh"


namespace crestpp {

Session::Impl::Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols
) noexcept
    : host(std::move(host)),
      port(port),
      protocols(std::move(protocols))
{}

}

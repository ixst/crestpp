#include "crestpp/session_impl.hh"


namespace crestpp {

SessionImpl::SessionImpl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
) noexcept
    : host(std::move(host)),
      port(port),
      protocols(std::move(protocols)),
      base_path(std::move(base_path))
{}

}

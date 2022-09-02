#include "crestpp/session.hh"


namespace crestpp {

Session::Session(std::shared_ptr<Impl> impl) noexcept
    : host(impl->host),
      port(impl->port),
      protocols(impl->protocols),
      impl_(std::move(impl))
{}



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

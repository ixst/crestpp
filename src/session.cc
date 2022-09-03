#include "crestpp/session.hh"

#include "session_impl.hh"


namespace crestpp {

Session::Session(std::shared_ptr<Impl> impl) noexcept
    : host(impl->host),
      port(impl->port),
      protocols(impl->protocols),
      impl_(std::move(impl))
{}

}

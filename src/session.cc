#include "crestpp/session.hh"

#include "crestpp/session_impl.hh"


namespace crestpp {

Session::Session(std::shared_ptr<Impl> impl) noexcept
    : host(impl->host),
      port(impl->port),
      protocols(impl->protocols),
      base_path(impl->base_path),
      impl_(std::move(impl))
{}

}

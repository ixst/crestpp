#include "cleartext_session_impl.hh"


namespace crestpp {

CleartextSession::Impl::Impl(
    std::string host,
    int port,
    std::vector<Protocol> protocols
) noexcept 
    : Session::Impl(std::move(host), port, std::move(protocols))
{}

}

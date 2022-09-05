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

void CleartextSession::Impl::Enqueue(
    Request req,
    std::promise<Response>& promise
) noexcept {
  //TODO
}

void CleartextSession::Impl::Enqueue(
    Request req,
    std::function<void(const Response&)> on_response,
    std::function<void(const Error&)> on_error
) noexcept {
  //TODO
}

}

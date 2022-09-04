#include "crestpp/api.hh"


namespace crestpp {

Api::Api(
    const std::shared_ptr<SessionImpl> session_impl,
    Path path,
    std::function<void(Request& req)> on_request) noexcept 
    : path(session_impl->base_path << std::move(path)),
      session_impl_(std::move(session_impl)),
      on_request_(std::move(on_request))
{}

Api::Api(const std::shared_ptr<SessionImpl> session_impl, Path path) noexcept 
    : Api(std::move(session_impl), std::move(path), {})
{}

void Api::operator()(
    std::function<void(Request& req)> on_request,
    std::function<void(const Response& res)> on_response,
    std::function<void(const Error& error)> on_error
) noexcept {
}

void Api::operator()(
    std::function<void(const Response& res)> on_response,
    std::function<void(const Error& error)> on_error
) noexcept {
  (*this)({}, std::move(on_response), std::move(on_error));
}

}

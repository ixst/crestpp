#include "crestpp/api.hh"


namespace crestpp {

namespace api_internal {

Request CreateRequest(
    const Path& path, 
    const std::function<void(Request&)>& on_request
) noexcept {
  Request req(path);
  if(on_request) {
    on_request(req);
  }
  return req;
}

}

Api::Api(
    const std::shared_ptr<SessionImpl> session_impl,
    Path path,
    std::function<void(Request&)> on_request
) noexcept 
    : path(session_impl->base_path << std::move(path)),
      session_impl_(std::move(session_impl)),
      on_request_(std::move(on_request))
{}

Api::Api(const std::shared_ptr<SessionImpl> session_impl, Path path) noexcept 
    : Api(std::move(session_impl), std::move(path), {})
{}

std::future<Response> Api::operator()(
    const std::function<void(Request&)>& on_request
) noexcept {
  std::promise<Response> promise;
  session_impl_->Enqueue(
      api_internal::CreateRequest(path, on_request), 
      promise
  );
  return promise.get_future();
}

void Api::operator()(
    const std::function<void(Request&)>& on_request,
    std::function<void(const Response&)> on_response,
    std::function<void(const Error&)> on_error
) noexcept {
  session_impl_->Enqueue(
      api_internal::CreateRequest(path, on_request), 
      std::move(on_response),
      std::move(on_error)
  );
}

void Api::operator()(
    std::function<void(const Response&)> on_response,
    std::function<void(const Error&)> on_error
) noexcept {
  (*this)({}, std::move(on_response), std::move(on_error));
}

}

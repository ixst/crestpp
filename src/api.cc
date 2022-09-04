#include "crestpp/api.hh"


namespace crestpp {

Api::Api(Path path, const std::shared_ptr<SessionImpl> session_impl) noexcept 
    : path(session_impl->base_path << path),
      session_impl_(std::move(session_impl))
{}

}

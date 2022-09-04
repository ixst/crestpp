#ifndef CRESTPP_API_HH__
#define CRESTPP_API_HH__

#include <string>
#include <memory>
#include <functional>

#include "path.hh"
#include "request.hh"
#include "response.hh"
#include "error.hh"
#include "session_impl.hh"


namespace crestpp {

class Api {
public:
  Path path;

public:
  Api(
      const std::shared_ptr<SessionImpl> session_impl,
      Path path,
      std::function<void(Request& req)> on_request) noexcept;
  Api(const std::shared_ptr<SessionImpl> session_impl, Path path) noexcept;

public:
  void operator()(
      std::function<void(Request& req)> on_request,
      std::function<void(const Response& res)> on_response,
      std::function<void(const Error& error)> on_error
  ) noexcept;
  void operator()(
      std::function<void(const Response& res)> on_response,
      std::function<void(const Error& error)> on_error
  ) noexcept;

private:
  std::shared_ptr<SessionImpl> session_impl_;
  std::function<void(Request& req)> on_request_;

};

}


#endif

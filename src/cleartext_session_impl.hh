#ifndef CRESTPP_CLEARTEXT_SESSION_IMPL_HH__
#define CRESTPP_CLEARTEXT_SESSION_IMPL_HH__

#include <string>
#include <vector>
#include <future>

#include "crestpp/session_impl.hh"
#include "crestpp/path.hh"
#include "crestpp/protocol.hh"
#include "crestpp/response.hh"
#include "crestpp/request.hh"
#include "crestpp/cleartext_session.hh"


namespace crestpp {

class CleartextSession::Impl : public Session::Impl {
public:
  Impl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
  ) noexcept;

public:
  void Enqueue(
      Request req, 
      std::promise<Response>& promise
  ) noexcept override;

  void Enqueue(
      Request req,
      std::function<void(const Response&)> on_response,
      std::function<void(const Error&)> on_error
  ) noexcept override;

};

}


#endif

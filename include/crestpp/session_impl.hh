#ifndef CRESTPP_SESSION_IMPL_HH__
#define CRESTPP_SESSION_IMPL_HH__

#include <string>
#include <vector>
#include <future>

#include "protocol.hh"
#include "path.hh"
#include "request.hh"
#include "response.hh"
#include "error.hh"


namespace crestpp {

class SessionImpl {
public:
  std::string host;
  int port;
  std::vector<Protocol> protocols;
  Path base_path;

public:
  virtual void Enqueue(
      Request req,
      std::promise<Response>& promise
  ) noexcept = 0;
  virtual void Enqueue(
      Request req,
      std::function<void(const Response&)> on_response,
      std::function<void(const Error&)> on_error
  ) noexcept = 0;

protected:
  SessionImpl(
      std::string host,
      int port,
      std::vector<Protocol> protocols,
      Path base_path
  ) noexcept;

};

}


#endif

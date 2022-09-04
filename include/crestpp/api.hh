#ifndef CRESTPP_API_HH__
#define CRESTPP_API_HH__

#include <string>
#include <memory>

#include "path.hh"
#include "session_impl.hh"


namespace crestpp {

class Api {
public:
  Path path;

public:
  Api(Path path, const std::shared_ptr<SessionImpl> session_impl) noexcept;

private:
  std::shared_ptr<SessionImpl> session_impl_;

};

}


#endif

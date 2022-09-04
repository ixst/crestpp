#ifndef CRESTPP_REQUEST_HH__
#define CRESTPP_REQUEST_HH__

#include "crestpp/path.hh"


namespace crestpp {

class Request {
public:
  Path path;

public:
  Request(Path path) noexcept;

};

}


#endif
